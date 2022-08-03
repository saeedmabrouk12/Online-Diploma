#include<stdio.h>
#include"lifo.h"
#include<stdlib.h>
#define LIFO_buffer_length 5
Buffer_status LIFO_Is_Buf_Full(LIFO_Buf_t* lbuf){
    if(!lbuf || !lbuf->head || !lbuf->base)
        return LIFO_null;
    if(lbuf->head >=(lbuf->base+lbuf->length))
        return LIFO_full;
    else
        return LIFO_not_full;
}
Buffer_status LIFO_Add_item(LIFO_Buf_t* lbuf,unsigned char item){
    if(!lbuf || !lbuf->head || !lbuf->base)
        return LIFO_null;
    if(LIFO_Is_Buf_Full(lbuf)==LIFO_full){
        return LIFO_null;
    }

    *(lbuf->head)= item;
    lbuf->head++;
    lbuf->count++;
    return LIFO_no_error;
}
Buffer_status LIFO_pop_item(LIFO_Buf_t * lbuf,unsigned char*temp){
    if(!lbuf || !lbuf->head || !lbuf->base)
        return LIFO_null;
    if(lbuf->head==lbuf->base)
        return LIFO_empty;
    lbuf->head--;
    *temp=*(lbuf->head) ;
    lbuf->count--;
    return LIFO_no_error;
}
int main(){
    unsigned staticbuffer[LIFO_buffer_length];
    unsigned char i ,temp;
    LIFO_Buf_t first_buffer,second_buffer;
    first_buffer.base = (unsigned char*)malloc(LIFO_buffer_length);
    first_buffer.length=5;
    first_buffer.head=first_buffer.base;
    first_buffer.count=0;
    for(int i = 0 ; i<5;i++){
        LIFO_Add_item(&first_buffer,i);

    }
    for(int i = 0 ; i < 5 ; i++){
        LIFO_pop_item(&first_buffer,&temp);
        printf("%d ",temp);
    }
}