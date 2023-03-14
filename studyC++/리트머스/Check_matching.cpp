#include <iostream>
#include <string>
// #include "ArrayStack.h"
using namespace std;

const int MAX_STACK_SIZE = 20;

inline void error(char *message){
    cout << message <<endl;
    exit(1);
}


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
        // if(isEmpty()) {
        //     error ("EOF");
        // }
        //
        return data[top--];
    }

    int peek(){
        // if(isEmpty()) {
        //     error ("EOF");
        // }
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

void checkMatching(string Str){
    ArrayStack stack;
    string ans = "OK";
    int a;
    int lc = 1;
    int bc = 2;
    char ch;
    a = Str.length();

    if(Str == '[' || Str=='(' || Str=='{'){
        stack.push(Str);
    }

    else if(Str == ']' || Str==')' || Str=='}'){
        if(stack.isEmpty()){
            cout << "비었음" << endl;

        }
        stack.pop();
    }

    cout << a<<endl;
    cout << ans <<", Line_count : "<<lc<<", bracket_count : "<<bc<<endl;

}

int main(){
    string Str,temp;
    while(true){
        getline(cin,temp);
        if(temp=="EOF")break;
        Str.append(temp);
        Str.append("\n");
        cin.clear();
    }
    cout << Str << endl;
    checkMatching(Str);

    return 0;
}