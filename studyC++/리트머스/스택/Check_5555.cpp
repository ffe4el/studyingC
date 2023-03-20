#include <iostream>
#include<string>
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
        data[++top] = e; //top에 먼저 1 더하고, 그 자리에 새로운 e값 넣기
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
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return 0;
}

int main(){
    ArrayStack stack;
    string ans ="";
    string s;
    getline(cin, s);
    for(int i=0; i<s.length(); i++){
        //피연산자 출력
        if(s[i]>='0' && s[i]<='9'){
            while(s[i]!=' '){
                ans += s[i];
                i++;
            }
        }
        //스택이 비어있는경우 or '('인경우 push
        else if(stack.isEmpty()|| s[i]=='('){
            stack.push(s[i]);
            // continue;
        }
        //')'경우 '('만날때까지 출력
        else if(s[i]==')'){
            while(stack.peek() != '('){
                ans += stack.peek();
                stack.pop();
            }
            stack.pop(); //'('는 삭제  
            continue;
        }
        //top보다 우선순위 크면 Push
        if(precedence(stack.peek()) < precedence(s[i])){
            stack.push(s[i]);
        }
        //top보다 우선순위 작거나 같으면 pop 후 반복
        else{
            while(!stack.isEmpty() && precedence(stack.peek())>= precedence(s[i])){
                ans += stack.peek();
                stack.pop();
            }
            stack.push(s[i]);
        }
    }
    while(!stack.isEmpty()){
        ans += stack.peek();
        stack.pop();
    }
    cout << ans << endl;
    return 0;
}
