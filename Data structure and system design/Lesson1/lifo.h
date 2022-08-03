#ifndef LIFOH
#define LIFOH
typedef struct 
{
    unsigned int length;
    unsigned char* base;
    unsigned char* head;
    unsigned int count;
}LIFO_Buf_t;

typedef enum{
    LIFO_no_error,
    LIFO_full,
    LIFO_not_full,
    LIFO_empty,
    LIFO_not_empty,
    LIFO_null
}Buffer_status;

Buffer_status LIFO_Add_item(LIFO_Buf_t* lbuf,unsigned char item);
Buffer_status LIFO_Is_Buf_Full(LIFO_Buf_t* lbuf);
Buffer_status LIFO_pop_item(LIFO_Buf_t * lbuf,unsigned char*temp);
#endif