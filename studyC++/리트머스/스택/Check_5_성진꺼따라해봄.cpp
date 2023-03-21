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
    if(c=='+'||c=='-'||c=='*'||c=='/'){
        double val1 = num.top();
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
            }
                num.push(val2/val1); break;
        }

    }
}

//중위연산자를 후위연산자로 변환