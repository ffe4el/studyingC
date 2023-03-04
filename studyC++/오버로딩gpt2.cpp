#include <iostream>
#include <string>
using namespace std;

int SUM(int a, int b) {
    return a + b;
}

double SUM(double a, double b) {
    return a + b;
}

string SUM(string a, string b) {
    return a + b;
}

int SUB(int a, int b) {
    return a - b;
}

double SUB(double a, double b) {
    return a - b;
}

int MULT(int a, int b) {
    return a * b;
}

double MULT(double a, double b) {
    return a * b;
}

int DIV(int a, int b) {
    return a / b;
}

double DIV(double a, double b) {
    return a / b;
}

int MOD(int a, int b) {
    return a % b;
}

int main() {
    int type;
    cin >> type;

    if (type == 1) {
        int a, b;
        char op;
        cin >> a >> op >> b;

        switch (op) {
            case '+':
                cout << SUM(a, b) << endl;
                break;
            case '-':
                cout << SUB(a, b) << endl;
                break;
            case '*':
                cout << MULT(a, b) << endl;
                break;
            case '/':
                cout << DIV(a, b) << endl;
                break;
            case '%':
                cout << MOD(a, b) << endl;
                break;
            default:
                cout << "incorrect" << endl;
                break;
        }
    }
    else if (type == 2) {
        double a, b;
        char op;
        cin >> a >> op >> b;

        switch (op) {
            case '+':
                cout << SUM(a, b) << endl;
                break;
            case '-':
                cout << SUB(a, b) << endl;
                break;
            case '*':
                cout << MULT(a, b) << endl;
                break;
            case '/':
                cout << DIV(a, b) << endl;
                break;
            default:
                cout << "incorrect" << endl;
                break;
        }
    }
    else if (type == 3) {
        string a, b;
        char op;
        cin >> a >> op >> b;

        if (op == '+') {
            cout << SUM(a, b) << endl;
        }
        else {
            cout << "incorrect" << endl;
        }
    }

    return 0;
}
