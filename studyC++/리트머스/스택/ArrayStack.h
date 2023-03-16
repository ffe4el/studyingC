#include <cstdio>
#include <cstdlib>
#include <string>

inline void error(char *message){
    printf("%s\n", message);
    exit(1);
}


// 스택배열의 최대사이즈를 20으로 맞춰줌
const int MAX_STACK_SIZE = 20;

//이제 스택 클래스
class ArrayStack
{
    int top;    //요소 개수
    int data[MAX_STACK_SIZE]; //요소의 배열

public :
    ArrayStack(){top = -1;} //스택의 생성자
    //반환자가 bool 타입이기 때문에 return top==-1일때 True를 반환하고, top!=-1이면 False를 반환한다.
    bool isEmpty(){return top == -1;}
    bool isFull(){return top == MAX_STACK_SIZE-1;}

    void push(int e){
        //만약 스택이 가득 찼다면
        if(isFull()) error ("스택 포화 에러");
        data[++top] =e; //top에 먼저 1 더하고, 그 자리에 새로운 e값 넣기
    }

    int pop(){
        if(isEmpty()) {
            error ("EOF");
        }
        //
        return data[top--];
    }

    int peek(){
        if(isEmpty()) {
            error ("EOF");
        }
        return data[top];
    }

    void display(){
        printf("[스택 항목의 수 = %2d] ==> ", top+1);
        for(int i=0; i<=top; i++){
            printf("<%2d>", data[i]);
            printf("\n");
        }
    }
};

int main(){
    ArrayStack stack;
    for(int i=0; i<10; i++){
        stack.push(i);
    }
    // stack.display();
    stack.pop();
    // stack.peek();
    stack.pop();
    stack.pop();
    stack.push(11);
    // stack.pop();
    stack.display();
}