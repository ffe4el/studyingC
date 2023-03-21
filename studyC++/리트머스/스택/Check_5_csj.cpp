#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <iostream>
using namespace std;
stack <double> operand; //피연산자 스택


inline void error(const char* message)
{
    printf("%s\n", message);
    exit(1);
}

const int Max_Stack_Size = 20;

inline int precedence(char op)
{
    switch (op)

    {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;

    }
    //return -1;
}

void postfixcal(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/') { //연산자가 나왔을 떄
        double first = operand.top(); // 맨 위에 거를 뒤로 보내고 두번째거를 앞으로 보내서 계산
        operand.pop();
        double second = operand.top();
        operand.pop();
        switch (c) {
        case '+':operand.push(second + first); break;
        case '-':operand.push(second - first); break;
        case '*':operand.push(second * first); break;
        case '/':if (first == 0)
        {
            cout << "Error : zero division error"; exit(1);
        } //0으로 나눌때 종료
                operand.push(second / first);
                break;
        }
    }
}


void infix2postfix(FILE* fp = stdin)
{

    char c, op;
    double val;
    stack <char> st;
    //ArrayStack st; //연산자 스택

    while ((c = getc(fp)) != '\n') //enter 키가 나오면 종료
    {
        if ((c >= '0') && c <= '9') //c가 숫자일 경우 double형으로 바꿔서 피연산자 스택에 push
        {
            ungetc(c, fp);
            fscanf(fp, "%lf", &val);
            //printf("%4.1f", val);
            operand.push(val);
        }

        else if (c == '(') //여는 괄호가 나오면 연산자 스택에 push
            st.push(c);
        else if (c == ')') //닫는 괄호가 나왔을 때
        {
            while (!st.empty()) //비어있지 않으면
            {
                op = st.top();
                st.pop();//맨 위에 스택을 꺼내보고
                if (op == '(') //짝이 맞으면 맨 위 스택 삭제 후 break
                    break;
                else //짝이 맞지 않으면 계산
                    postfixcal(op);//printf("%c ", op);


            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') // c가 사칙연산자일경우
        {
            while (!st.empty()) //비어있지 않을 때
            {
                op = st.top(); //스택 맨 위에 것과 c의 우선순위를 비교
                if (precedence(c) <= precedence(op))
                {
                    //printf("%c ", op);
                    postfixcal(op); //c의 우선순위가 더 낮으면 op부터 계산
                    st.pop();
                }
                else break;
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        postfixcal(st.top());
        st.pop();
    }
    //printf("%c ", st.pop());


    printf("%0.2lf", operand.top());
    printf("\n");

}


int main()
{
    infix2postfix();
}