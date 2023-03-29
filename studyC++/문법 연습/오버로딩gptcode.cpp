#include <iostream>
#include <string>

using namespace std;

// 정수형 데이터를 받아서 더하는 함수
int SUM(int a, int b) {
    return a + b;
}

// 실수형 데이터를 받아서 더하는 함수
double SUM(double a, double b) {
    return a + b;
}

// 문자열을 받아서 더하는 함수
string SUM(string a, string b) {
    return a + b;
}

// 정수형 데이터를 받아서 빼는 함수
int SUB(int a, int b) {
    return a - b;
}

// 실수형 데이터를 받아서 빼는 함수
double SUB(double a, double b) {
    return a - b;
}

// 정수형 데이터를 받아서 곱하는 함수
int MULT(int a, int b) {
    return a * b;
}

// 실수형 데이터를 받아서 곱하는 함수
double MULT(double a, double b) {
    return a * b;
}

// 정수형 데이터를 받아서 나누는 함수
int DIV(int a, int b) {
    return a / b;
}

// 실수형 데이터를 받아서 나누는 함수
double DIV(double a, double b) {
    return a / b;
}

// 정수형 데이터를 받아서 나머지를 구하는 함수
int MOD(int a, int b) {
    return a % b;
}

int main() {
    int type;
    cin >> type;

    // type에 따라 알맞은 변수를 입력 받는다.
    if (type == 1) {
        int a, b;
        char op;
        cin >> a >> op >> b;
        if (op == '+') {
            cout << SUM(a, b) << endl;
        } else if (op == '-') {
            cout << SUB(a, b) << endl;
        } else if (op == '*') {
            cout << MULT(a, b) << endl;
        } else if (op == '/') {
            cout << DIV(a, b) << endl;
        } else if (op == '%') {
            cout << MOD(a, b) << endl;
        } else {
            cout << "incorrect" << endl;
        }
    } else if (type == 2) {
        double a, b;
        char op;
        cin >> a >> op >> b;
        if (op == '+') {
            cout << SUM(a, b) << endl;
        } else if (op == '-') {
            cout << SUB(a, b) << endl;
        } else if (op == '*') {
            cout << MULT(a, b) << endl;
        } else if (op == '/') {
            cout << DIV(a, b) << endl;
        } else {
            cout << "incorrect" << endl;
        }
    } else if (type == 3) {
        string a, b;
        char op;
        cin >> a >> op >> b;
        if (op == '+') {
            cout << SUM(a, b);
        }else {
            cout << "incorrect" << endl;
        }
    }
    return 0;
}     
