//실행안됨;;

#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE 10

inline void error(char *message){
    printf("%s\n", message);
    exit(1);
}

class CircularStack{
protected:
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
public:
    CircularStack(){front = rear = 0;}
    bool isEmpty() {return front == rear;}
    bool isfull() {return (rear+1)%MAX_QUEUE_SIZE == front;}
    void push(int val){  //큐 삽입
        rear = (rear+1) % MAX_QUEUE_SIZE;
        data[rear] = val;
    }
    int pop(){
        if(isEmpty()){
            error(" error: 큐가 공백상태입니다.\n");
        }
        else{
            rear = (rear-1)%MAX_QUEUE_SIZE;
            return data[rear];
        }
    }
    int peek(){
        if(isEmpty()){
            error(" error: 큐가 공백상태입니다.\n");
        }
        else {
            return data[(rear-1)%MAX_QUEUE_SIZE];
        }
    }
    void display(){
        printf("스택 내용 : ");
        int maxi = (front < rear)? rear : rear+MAX_QUEUE_SIZE;
        for(int i=front+1; i<=maxi; i++){
            printf("[%2d] ", data[i%MAX_QUEUE_SIZE]);
        }
        printf(" \n");
    }

};

int main(){
    CircularStack stack;
    for(int i=0; i<10; i++){
        stack.push(i);
    }
    // stack.display();
    stack.pop();
    // stack.peek();
    stack.pop();
    stack.pop();
    stack.push(11);
    stack.push(12);
    stack.push(13);
    stack.push(14);
    // stack.pop();
    stack.display();
}