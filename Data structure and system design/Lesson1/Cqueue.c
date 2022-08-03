#include"Cqueue.h"


Buffer_status FIFO_init(FIFO_Buf_t * fifo,elment_type* buff,uint32_t buff_length){
    if( !(fifo &&buff))
        return FIFO_null;
    fifo->base=buff;
    fifo->head=fifo->base;
    fifo->tail=fifo->base;
    fifo->length=buff_length;
    fifo->count=0;
    return FIFO_no_error;
}
Buffer_status FIFO_Is_Buf_Full(FIFO_Buf_t* a){
    if(!a->base || !a->head || !a->tail){
        printf("fifo_is full null ");
        return FIFO_null;
    }
    //printf("a->count %d , a->length %d",a->count,a->length);
    if(a->count==a->length){
        printf("Fifo is full");
        return FIFO_full;
    }
    return FIFO_no_error;
}

Buffer_status FIFO_enqueue (FIFO_Buf_t * a,elment_type en){
    printf("\n head : %x : " ,a->head);
    if(FIFO_Is_Buf_Full(a)==FIFO_no_error){
        *a->head=en;
        a->count++;
        if(a->head==    (a->base  +  (int)a->length))
            a->head=a->base;
        else
            a->head++;
        
        return FIFO_no_error;
        printf("\n head : %x : ",a->head);
    }
    printf("FIFO Enqueue failded");
    printf("\n head : %x : " ,a->head);
    return FIFO_Is_Buf_Full(a);
}

Buffer_status FIFO_dequeue (FIFO_Buf_t * a,elment_type* en){
     if(!a->base || !a->head || !a->tail){
        return FIFO_null;
    }
    if(a->count==0){
        printf("fifo is empty");
        return FIFO_empty;
    }
    *en = *a->tail;
    a->count--;
    
    
        a->tail++;
    
    return FIFO_no_error;
    
    printf("FIFO Enqueue failded");
    return FIFO_Is_Buf_Full(a);
}

void FIFO_print(FIFO_Buf_t* a){
    elment_type* ab;
    elment_type i ;
    if(a->count==0){
        printf("fifo is empty");
        //return FIFO_empty;
    
    }
    ab=a->tail;
    printf(" \n===========fifo========= \n");
    for(i = 0 ; i < a->count;i++){
        printf("\t %x /n",*ab);
        ab++;
    }
    printf(" \n  ================\n");

}
#define buffer_length1 5
elment_type buffer1[buffer_length1];
int main(){
    FIFO_Buf_t uart;
    elment_type i,temp = 0;
    if(FIFO_init(&uart,buffer1,buffer_length1)==FIFO_no_error)
        printf("No error init\n");
    for(i = 0 ;i < 7;i++){
        printf("fifo enqueue (%x)\n",i);
        if(FIFO_enqueue(&uart,i)==FIFO_no_error){
            printf("fifo enqueue(%x) ==done\n",i);
        }else{
            printf("fifo enqueue(%x) ==failed\n",i);
        }
    }
    FIFO_print(&uart);
    FIFO_dequeue(&uart,&temp);
    printf("Fifo_depque : data = %x \n",temp);
    FIFO_dequeue(&uart,&temp);
    printf("Fifo_depque : data = %x \n",temp);
    for(i = 0 ; i < 4 ; i++){
        printf("Fifo enqueuee (%x)\n",i);
        if(FIFO_enqueue(&uart,i)==FIFO_no_error){
            printf("fifo enqueue(%x) ==done\n",i);
        }else{
            printf("fifo enqueue(%x) ==failed\n",i);
        }
    }


}