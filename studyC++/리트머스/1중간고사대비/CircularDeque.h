#include <cstdio>
#include <cstdlib>

#define MAX_DEQUE_SIZE 100

inline void error(char* message){
    printf("%s", message);
    exit(1);
}

class CircularDeque{
    int front, rear;
    int data[MAX_DEQUE_SIZE];
public:
    CircularDeque(){front = rear = 0;}
    ~CircularDeque(){}
    bool isFull(){return front = (rear+1)%MAX_DEQUE_SIZE;}
    bool isEmpty(){return front == rear;}

    void addFront(int e){
        if(isFull()) error("포화 에러");
        // front = front%MAX_DEQUE_SIZE;
        // data[front--]=e;
        data[front] = e;
        front = (front-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
    }

    void addRear(int e){
        if(isFull()) error("포화 에러");
        rear = (rear+1)%MAX_DEQUE_SIZE;
        data[rear]=e;
    }

    int deleteFront(){
        if(isEmpty()) error("공백 에러");
        front = (front+1)%MAX_DEQUE_SIZE;
        return data[front];
    }

    int deleteRear(){
        if(isEmpty()) error("공백 에러");
        // rear = (rear)%MAX_DEQUE_SIZE;
        // return data[rear--];
        int ret = data[rear];
        rear = (rear-1+MAX_DEQUE_SIZE)%MAX_DEQUE_SIZE;
        return ret;
    }

    int getFront(){
        if(isEmpty()) error("공백 에러");
        return data[(front+1)%MAX_DEQUE_SIZE];
    }

    int getRear(){
        if(isEmpty()) error("공백 에러");
        return data[rear];
    }


};