#include <iostream>
#include <string>
 
 
#define MAX_STACK_SIZE 100
 
using namespace std;
 
inline void error(const char* message) {
    printf("%s\n", message);
    exit(1);
}
 
class ArrayStack { // Stack 클래스 구현
private:
    int top;
    double data[MAX_STACK_SIZE];
public:
    ArrayStack() { top = -1; }
    ~ArrayStack() {}
    int Howtop() { return top; }
    void reset_Top() { top = 0; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE - 1; }
 
    char find(int count) {
        return data[count];
    }
 
    void push(double e) {
        if (isFull()) error("스택 포화 에러");
        data[++top] = e;
    }
 
    double pop() {
        if (isEmpty()) error("스택 공백 에러");
        return data[top--];
    }
 
    double peek() {
        if (isEmpty()) error("스택 공백 에러");
        return data[top];
    }
};
 
 
int precedence(char op) {
    switch (op) {
    case'(': case')': return 0;
    case'+': case'-': return 1;
    case'*': case'/': return 2;
    }
    return -1;
}
 
ArrayStack infix2Postfix(FILE *fp = stdin) {
    char c, op;
    double val;
    ArrayStack st, real_St;
 
    while ((c=getc(fp)) != '\n') {
 
        if (c >= '0' && c <= '9') {
            ungetc(c, fp);
            fscanf(fp, "%lf", &val);
            real_St.push(val);
        }
 
        else if (c == '(') st.push(c);
 
        else if (c == ')') {
            while (!st.isEmpty()) {
                op = st.pop();
                if (op == '(')break;
                else real_St.push(op);
            }
        }
 
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!st.isEmpty()) {
                op = st.peek();
                if (precedence(c) <= precedence(op)) {
                    real_St.push(op);
                    st.pop();
                }
                else break;
            }
            st.push(c);
        }
    }
    while (!st.isEmpty())
        real_St.push(st.pop());
 
    return real_St;
}
 
double calcPostfixExpr(ArrayStack r_St, int top) {
    double c;
    ArrayStack st;
    while ((r_St.Howtop()) != -1) {
        c = r_St.pop();
        if (c == 43) {
            double val2 = st.pop();
            double val1 = st.pop();
            st.push(val1 + val2); 
        }
        else if (c==45) {
            double val2 = st.pop();
            double val1 = st.pop();
            st.push(val1 - val2); 
        }
        else if (c==42) {
            double val2 = st.pop();
            double val1 = st.pop();
            st.push(val1 * val2); 
        }
        else if (c==47) {
            double val2 = st.pop();
            double val1 = st.pop();
            if (val2 == 0) {
                printf("Error : zero division error\n");
                exit(1);
            }
            st.push(val1 / val2);
        }
        else st.push(c);
    }
    return (st.pop());
}
 
int main() {
    ArrayStack real_Stack;
    ArrayStack st = infix2Postfix();
    int top = st.Howtop();
    for (int i = 0; i <= top; i++) {
        real_Stack.push(st.pop());
    }
    printf("%.2f", calcPostfixExpr(real_Stack, top));
}