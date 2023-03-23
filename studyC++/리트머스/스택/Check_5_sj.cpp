#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

//계산할때 피연산자 스택
stack <double> num; 

const int MAX_STACK_SIZE = 20;

//연산자 비교 함수
inline int precedence(char op){
    switch(op)
    {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

//후위수식 계산 함수
void calPostfix(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'){ //연산자가 나왔을 떄
        double val1 = num.top(); // 맨 위에 거를 뒤로 보내고 두번째거를 앞으로 보내서 계산
        num.pop();
        double val2 = num.top();
        num.pop();
        switch(c){
            case '+':num.push(val2 + val1); break;
            case '-':num.push(val2 - val1); break;
            case '*':num.push(val2 * val1); break;
            case '/': if(val1==0){
                cout<< "Error : zero division error"<<endl; 
                exit(1);
            } //0으로 나눌때 종료
                num.push(val2/val1); break;
        }

    }
}

//중위연산자를 후위연산자로 변환
void infix2postfix(FILE *fp= stdin){
    char c,op;
    double val;
    stack <char> st; //연산자 스택
    

    while((c=getc(fp)) != '\n'){ //enter 키가 나오면 종료
        if(c>='0' && c<='9'){ //c가 숫자일 경우 double형으로 바꿔서 피연산자 스택에 push
            ungetc(c,fp);
            fscanf(fp, "%lf", &val);
            num.push(val); //바로 num에 push해버림
        }
        else if(c=='('){
            st.push(c);
        }
        else if (c==')'){
            while(!st.empty()){
                op = st.top();
                st.pop();
                if(op=='(') break;  //짝 맞으면 맨 위 스택 삭제
                else calPostfix(op); //짝이 안맞으면 계산하는 함수로 보내기
            }
        }
        // c가 사칙연산자일경우
        else if(c == '+' || c == '-' || c == '*' || c == '/'){
            while(!st.empty()){
                op = st.top();
                if(precedence(c) <= precedence(op)){ //스택 맨 위에 것과 c의 우선순위를 비교
                    calPostfix(op); //c우선순위가 더 낮으면 op부터 넣어서 계산
                    st.pop();
                }
                else break;
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        calPostfix(st.top());
        st.pop();
    }

    printf("%0.2lf\n", num.top());
}



int main(){
    infix2postfix();
}