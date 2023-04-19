#include <cstdio>
#include <cstdlib>

const int MAX_STACK_SIZE = 100;

inline void error(char *message){
    printf("%s\n", message);
    exit(1);
}

class ArrayStack{
    int top;
    int data[MAX_STACK_SIZE];

public: 
    ArrayStack() {top = -1;}    //스택 생성자 => top을 -1로 초기화
    ~ArrayStack() {} //스택 소멸자

    bool isFull(){return top = MAX_STACK_SIZE-1;}
    bool isEmpty(){return top = -1;}

    void push(int e){
        if(isFull()) error("스택 포화 에러");
        else {
            data[++top] = e; //전위
        }
    }

    void pop(){
        if(isEmpty()) error("스택이 비어있음");
        else{
            data[top--];    //후위
        }
    }

    int peek(){
        if(isEmpty()) error("스택이 비어있음");
        else {
            return data[top];
        }
    }

    // int size(){
    //     return sizeof(data)/sizeof(int);
    // }

    

};