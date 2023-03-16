#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAX_STACK_SIZE = 20;
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
        // if(isFull()) error ("스택 포화 에러");
        data[++top] =e; //top에 먼저 1 더하고, 그 자리에 새로운 e값 넣기
    }
    int pop(){
        return data[top--];
    }
    int peek(){
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

//객체의 우선순위 계산
inline int precedence(char op){
    switch(op){
        case '(' : case ')' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1;
}

void infix2Postfix(string s){
    // char d[100];
    string ans;
    for(int i=0; i<s.length(); i++){
        //피연산자 출력
        if(s[i]>='0' && s[i]<='9'){
            ans += s[i];
            continue;
        }
        //스택이 비어있는경우 or '('인경우


    }
}

int main(){
    string s;
    getline(cin, s);

    infix2Postfix(s);


    return 0;
}