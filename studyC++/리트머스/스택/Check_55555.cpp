#include <iostream>
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
    int gaesu(){
        return top;
    }
};

//객체의 우선순위 계산
inline int precedence(char op){
    switch(op){
        case '(' : case ')' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1; //공백처리
}

ArrayStack infix2Postfix(FILE *fp=stdin){
    char c,op;
    double val;
    ArrayStack st;
    ArrayStack stt;

    while((c=getc(fp) != '\n')){
        if((c>='0' && c<='9')){
            ungetc(c,fp);
            fscanf(fp,"%lf", &val);
            stt.push(val);
        }
        else if(c=='(') st.push(c);
        
        else if(c==')'){
            while(!st.isEmpty()){
                op = st.pop();
                if(op=='(') break;
                else stt.push(op);
            }
        }

        else if (c=='+' || c=='-' || c=='*' || c=='/'){
            while(!st.isEmpty()){
                op = st.peek();
                if(precedence(c) <= precedence(op)){
                    stt.push(op);
                    st.pop();
                }
                else break;
            }
            st.push(c);
        }
    }
    while (!st.isEmpty())
        stt.push(st.pop());

    return stt;
}

double calcPostfixExpr(ArrayStack str){
    char c;
    ArrayStack sttrr;
    while(str.gaesu() > -1){
        c = str.pop();
        if(c=='+' || c=='-' || c=='*' || c=='/'){
            double val2 = sttrr.pop();
            double val1 = sttrr.pop();
        
            switch(c){
                case '+' : sttrr.push(val1+val2);
                case '-' : sttrr.push(val1-val2);
                case '*' : sttrr.push(val1*val2);
                case '/' : sttrr.push(val1/val2);
            }
        }
        else{sttrr.push(c);}
        
            
    }
    return (sttrr.pop());
}

int main(){
    ArrayStack str = infix2Postfix();
    ArrayStack sttr;
    for(int i=0; i<=sttr.gaesu(); i++){
        sttr.push(str.pop());
    }
    double res = calcPostfixExpr(sttr);
    printf("%f\n", res);
}