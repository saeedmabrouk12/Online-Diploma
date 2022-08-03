#ifndef _QUEUE
#define _QUEUE

#include "stdio.h"
#include"stdint.h"

#define elment_type uint8_t

typedef struct{
    unsigned int length;
    elment_type* base;
    elment_type* tail;
    elment_type* head;
    unsigned int count;
}FIFO_Buf_t;

typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_not_full,
    FIFO_empty,
    FIFO_not_empty,
    FIFO_null
}Buffer_status;

Buffer_status FIFO_enqueue(FIFO_Buf_t* ,elment_type );
Buffer_status FIFO_dequeue(FIFO_Buf_t* ,elment_type* );
Buffer_status FIFO_Is_Buf_Full(FIFO_Buf_t* );
void FIFO_print(FIFO_Buf_t* );
Buffer_status FIFI_init(FIFO_Buf_t * ,elment_type* ,uint32_t );



#endif