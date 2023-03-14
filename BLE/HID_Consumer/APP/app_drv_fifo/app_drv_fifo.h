/********************************** (C) COPYRIGHT *******************************
 * File Name          : app_drv_fifo.h
 * Author             : WCH
 * Version            : V1.1
 * Date               : 2022/01/19
 * Description        :
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/

#ifndef __APP_DRV_FIFO_H__
#define __APP_DRV_FIFO_H__

#include <stdbool.h>
#include <stdint.h>

#ifndef BV
  #define BV(n)    (1 << (n))
#endif

#ifndef BF
  #define BF(x, b, s)    (((x) & (b)) >> (s))
#endif

#ifndef MIN
  #define MIN(n, m)    (((n) < (m)) ? (n) : (m))
#endif

#ifndef MAX
  #define MAX(n, m)    (((n) < (m)) ? (m) : (n))
#endif

#ifndef ABS
  #define ABS(n)    (((n) < 0) ? -(n) : (n))
#endif

typedef enum
{
    APP_DRV_FIFO_RESULT_SUCCESS = 0,
    APP_DRV_FIFO_RESULT_LENGTH_ERROR,
    APP_DRV_FIFO_RESULT_NOT_FOUND,
    APP_DRV_FIFO_RESULT_NOT_MEM,
    APP_DRV_FIFO_RESULT_NULL,

} app_drv_fifo_result_t;

#ifndef NULL
  #define NULL    0
#endif

/*!
 * FIFO structure
 */
typedef struct Fifo_s
{
    uint16_t begin;
    uint16_t end;
    uint8_t *data;
    uint16_t size;
    uint16_t size_mask;
} app_drv_fifo_t;

//__inline uint16_t app_drv_fifo_length(app_drv_fifo_t *fifo);

uint16_t fifo_length(app_drv_fifo_t *fifo);

uint16_t app_drv_fifo_length(app_drv_fifo_t *fifo);

/*!
 * Initializes the FIFO structure
 *
 * \param [IN] fifo   Pointer to the FIFO object
 * \param [IN] buffer Buffer to be used as FIFO
 * \param [IN] size   size of the buffer
 */
static __inline app_drv_fifo_result_t
app_drv_fifo_init(app_drv_fifo_t *fifo, uint8_t *buffer, uint16_t buffer_size)
{
    if(buffer_size == 0)
    {
        return APP_DRV_FIFO_RESULT_LENGTH_ERROR;
    }
    if(0 != ((buffer_size) & (buffer_size - 1)))
    {
        return APP_DRV_FIFO_RESULT_LENGTH_ERROR;
    }
    fifo->begin = 0;
    fifo->end = 0;
    fifo->data = buffer;
    fifo->size = buffer_size;
    fifo->size_mask = buffer_size - 1;
    return APP_DRV_FIFO_RESULT_SUCCESS;
}

/*!
 * Pushes data to the FIFO
 *
 * \param [IN] fifo Pointer to the FIFO object
 * \param [IN] data data to be pushed into the FIFO
 */
static __inline void app_drv_fifo_push(app_drv_fifo_t *fifo, uint8_t data)
{
    fifo->data[fifo->end & fifo->size_mask] = data;
    fifo->end++;
    fifo->end = fifo->end & fifo->size_mask;
}

/*!
 * Pops data from the FIFO
 *
 * \param [IN] fifo Pointer to the FIFO object
 * \retval data     data popped from the FIFO
 */
static __inline uint8_t app_drv_fifo_pop(app_drv_fifo_t *fifo)
{
    uint8_t data = fifo->data[fifo->begin & fifo->size_mask];
    fifo->begin++;
    fifo->begin = fifo->begin & fifo->size_mask;
    return data;
}

/*!
 * Flushes the FIFO
 *
 * \param [IN] fifo   Pointer to the FIFO object
 */
static __inline void app_drv_fifo_flush(app_drv_fifo_t *fifo)
{
    fifo->begin = 0;
    fifo->end = 0;
}

/*!
 * Checks if the FIFO is empty
 *
 * \param [IN] fifo   Pointer to the FIFO object
 * \retval isEmpty    true: FIFO is empty, false FIFO is not empty
 */
static __inline bool app_drv_fifo_is_empty(app_drv_fifo_t *fifo)
{
    return (fifo->begin == fifo->end);
}

/*!
 * Checks if the FIFO is full
 *
 * \param [IN] fifo   Pointer to the FIFO object
 * \retval isFull     true: FIFO is full, false FIFO is not full
 */


static __inline app_drv_fifo_result_t app_drv_fifo_write(app_drv_fifo_t *fifo, uint8_t *data, uint16_t *p_write_length)
{
    if(fifo == NULL)
    {
        return APP_DRV_FIFO_RESULT_NULL;
    }
    if(p_write_length == NULL)
    {
        return APP_DRV_FIFO_RESULT_NULL;
    }
    //PRINT("fifo_length = %d\r\n",fifo_length(fifo));
    const uint16_t available_count = fifo->size - fifo_length(fifo);
    const uint16_t requested_len = (*p_write_length);
    uint16_t       index = 0;
    uint16_t       write_size = MIN(requested_len, available_count);
    //PRINT("available_count %d\r\n",available_count);
    // Check if the FIFO is FULL.
    if(available_count == 0)
    {
        return APP_DRV_FIFO_RESULT_NOT_MEM;
    }

    // Check if application has requested only the size.
    if(data == NULL)
    {
        return APP_DRV_FIFO_RESULT_SUCCESS;
    }

    for(index = 0; index < write_size; index++)
    {
        //push
        fifo->data[fifo->end & fifo->size_mask] = data[index];
        fifo->end++;
    }
    if(fifo->end > fifo->size_mask) fifo->end = 0;
    (*p_write_length) = write_size;
    return APP_DRV_FIFO_RESULT_SUCCESS;
}

static __inline app_drv_fifo_result_t app_drv_fifo_write_from_same_addr(app_drv_fifo_t *fifo, uint8_t *data, uint16_t write_length)
{
    if(fifo == NULL)
    {
        return APP_DRV_FIFO_RESULT_NULL;
    }
    const uint16_t available_count = fifo->size_mask - fifo_length(fifo) + 1;
    const uint16_t requested_len = (write_length);
    uint16_t       index = 0;
    uint16_t       write_size = MIN(requested_len, available_count);

    // Check if the FIFO is FULL.
    if(available_count == 0)
    {
        return APP_DRV_FIFO_RESULT_NOT_MEM;
    }

    for(index = 0; index < write_size; index++)
    {
        //push
        fifo->data[fifo->end & fifo->size_mask] = data[0];
        fifo->end++;
        if(fifo->end > fifo->size_mask) fifo->end = 0;
    }
    return APP_DRV_FIFO_RESULT_SUCCESS;
}

static __inline app_drv_fifo_result_t app_drv_fifo_read(app_drv_fifo_t *fifo, uint8_t *data, uint16_t *p_read_length)
{
    if(fifo == NULL)
    {
        return APP_DRV_FIFO_RESULT_NULL;
    }
    if(p_read_length == NULL)
    {
        return APP_DRV_FIFO_RESULT_NULL;
    }
    const uint16_t byte_count = fifo_length(fifo);
    const uint16_t requested_len = (*p_read_length);
    uint32_t       index = 0;
    uint32_t       read_size = MIN(requested_len, byte_count);

    if(byte_count == 0)
    {
        return APP_DRV_FIFO_RESULT_NOT_FOUND;
    }
    //PRINT("read size = %d,byte_count = %d\r\n",read_size,byte_count);
    for(index = 0; index < read_size; index++)
    {
        //pop
        data[index] = fifo->data[fifo->begin & fifo->size_mask];
        fifo->begin++;
    }
    if(fifo->begin > fifo->size_mask) fifo->begin = 0;

    (*p_read_length) = read_size;
    return APP_DRV_FIFO_RESULT_SUCCESS;
}

static __inline app_drv_fifo_result_t app_drv_fifo_read_to_same_addr(app_drv_fifo_t *fifo, uint8_t *data, uint16_t read_length)
{
    if(fifo == NULL)
    {
        return APP_DRV_FIFO_RESULT_NULL;
    }
    const uint16_t byte_count = fifo_length(fifo);
    const uint16_t requested_len = (read_length);
    uint32_t       index = 0;
    uint32_t       read_size = MIN(requested_len, byte_count);

    for(index = 0; index < read_size; index++)
    {
        //pop
        data[0] = fifo->data[fifo->begin & fifo->size_mask];
        fifo->begin++;
    }
    if(fifo->begin > fifo->size_mask) fifo->begin = 0;
    return APP_DRV_FIFO_RESULT_SUCCESS;
}


static __inline app_drv_fifo_result_t app_drv_fifo_read_all_new(app_drv_fifo_t *fifo, uint8_t *data, uint16_t *data_length)
{
    if(fifo == NULL)
    {
        return APP_DRV_FIFO_RESULT_NULL;
    }

    uint16_t       index = 0;

    if((fifo->begin > fifo->size_mask)&&(fifo->end > fifo->size_mask))
    {
        return APP_DRV_FIFO_RESULT_LENGTH_ERROR;
    }
    for(index = 0; index <= (fifo->size_mask); )
    {
        if(fifo->begin == fifo->end)
        {
            break;
        }
        data[index++] = fifo->data[fifo->begin & fifo->size_mask];
        fifo->begin++;
        if(fifo->begin > fifo->size_mask) fifo->begin = 0;
    }

    *data_length = index;

    return APP_DRV_FIFO_RESULT_SUCCESS;
}

static __inline app_drv_fifo_result_t app_drv_fifo_write_all_new(app_drv_fifo_t *fifo, uint8_t *data, uint16_t p_write_length)
{
//    printf("RC***:%d\r\n",p_write_length);
    if(fifo == NULL)
    {
        return APP_DRV_FIFO_RESULT_NULL;
    }

    const uint16_t requested_len = (p_write_length);
    uint16_t       index = 0;

    // Check if application has requested only the size.
    if(data == NULL)
    {
        return APP_DRV_FIFO_RESULT_SUCCESS;
    }

    if(fifo->end > fifo->size_mask) fifo->end = 0;
    for(index = 0; index < p_write_length; index++)
    {
        //push
        fifo->data[fifo->end] = data[index];
        fifo->end++;
        if(fifo->end > fifo->size_mask) fifo->end = 0;
    }
    return APP_DRV_FIFO_RESULT_SUCCESS;
}

#endif // __APP_DRV_FIFO_H__
