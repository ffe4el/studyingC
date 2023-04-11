#include "CircularQueue.h"

class CircularDeque : public CircularQueue{
public :
    CircularDeque(){}
    void addRear(int val){enqueue(val);}    
    int deleteFront(){return dequeue();}
    int getFront() {return peek();}
    void addFront(int val){ //전단 삽입
        if(isfull()){
            error(" error: 덱이 포화상태입니다.\n");
        }
        else{
            data[front] = val;
            front =(front-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE; //이건 머누
        }
    }
    int deleteRear(){   //후단 삭제
        if(isEmpty()){
            error(" error: 덱이 공백상태입니다.\n");
        }
        else{
            int ret = data[rear];
            rear = (rear-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            return ret;
        }
    }
    int getRear(){  //후단에서 peek
        if(isEmpty()){
            error(" error: 덱이 공백상태입니다.\n");
        }
        else return data[rear];
    }
    void display(){
        printf("덱의 내용 : ");
        int maxi = (front < rear) ? rear: rear+MAX_QUEUE_SIZE;
        for(int i=front+1; i<=maxi; i++){
            printf("[%2d] ", data[i%MAX_QUEUE_SIZE]);
        }
        printf("\n");
    }
};