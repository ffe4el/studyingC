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
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return 0;
}

void infix2Postfix(string s){
    ArrayStack stack;
    string ans;
    cout << s[2] <<endl;
    for(int i=0; i<s.length(); i++){
        //피연산자 출력
        if(s[i]>='0' && s[i]<='9'){
            ans += s[i];
            continue;
        }
        //스택이 비어있는경우 or '('인경우 push
        if(stack.isEmpty()|| s[i]=='('){
            stack.push(s[i]);
            continue;
        }
        //')'경우 '('만날때까지 출력
        if(s[i]==')'){
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
}

int main(){
    ArrayStack stack;
    string ans;
    string input;
    double a;
    // cout << s[2] <<endl;
    getline(cin, input); // 입력 받기
    string s = ""; // 추출한 숫자를 저장할 문자열
    for (int i=0; i<input.length(); i++) { // 입력 문자열을 한 문자씩 검사
        char c= input[i];
        if (isdigit(c) || c == '.') { // 숫자나 소수점인 경우
            s += c; // 문자열에 추가
            // numStr += ' ';
        }
    }
    // double s = stod(numStr); // 문자열을 double형으로 변환
    for(int i=0; i<s.length(); i++){
        //피연산자 출력
        if(s[i]>='0' && s[i]<='9'){
            // char s[i];
            // a = strtof(s[i]);
            // ans += s[i];
            cout <<s[i] << " ";

            continue;
        }
        //스택이 비어있는경우 or '('인경우 push
        if(stack.isEmpty()|| s[i]=='('){
            stack.push(s[i]);
            continue;
        }
        //')'경우 '('만날때까지 출력
        if(s[i]==')'){
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