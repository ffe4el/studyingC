#include <cstdio>
#include <cstdlib>

// const int MAX_QUEUE_SIZE = 100;
#define MAX_QUEUE_SIZE 100

inline void error(char* message){
    printf("%s\n", message);
    exit(1);
}

class CircularQueue{
protected:
    int front, rear;
    int data[MAX_QUEUE_SIZE];

public : 
    CircularQueue(){front = rear = 0;}
    ~CircularQueue(){} 

    bool isFull(){return (rear+1)%MAX_QUEUE_SIZE == front;}
    bool isEmpty(){return front == rear;}

    void enqueue(int e){
        if(isFull()) error("스택 포화 에러");
        // data[++rear] = e;
        rear = (rear+1)%MAX_QUEUE_SIZE;
        data[rear]= e;
    }

    int dequeue(){
        if(isEmpty()) error("스택 공백 에러");
        // return data[++front];
        front = (front+1) % MAX_QUEUE_SIZE;
        return data[front];
    }

    int peek(){
        if(isEmpty()) error("스택 공백 에러");
        return data[(front+1)%MAX_QUEUE_SIZE];
    }

    // int size

    void display(){
        // 만약 rear가 front를 뛰어 넘었다면 rear, front보다 작으면 한바퀴 돈것임으로..
        int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
        for(int i=front+1; i<=maxi; i++){
            printf("[%2d]", data[i%MAX_QUEUE_SIZE]);
        }
        printf(" \n");
    }
};