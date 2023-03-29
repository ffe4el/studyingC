#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void SUM(int a, int b) {
    cout << a + b << endl;
}

void SUB(int a, int b) {
    cout << a - b << endl;
}

void MULT(int a, int b) {
    cout << a * b << endl;
}

void DIV(int a, int b) {
    cout << a / b << endl;
}

void MOD(int a, int b) {
    cout << a % b << endl;
}

void SUM(double a, double b) {
    cout << fixed << setprecision(2) << a + b << endl;
}

void SUB(double a, double b) {
    cout << fixed << setprecision(2) << a - b << endl;
}

void input_string() {
    string a, b;
    cin >> a >> b;
    cout << a + b << endl;
}

int main() {
    int type;
    cin >> type;

    switch (type) {
        case 1: {
            int a, b;
            char op;
            cin >> a >> op >> b;
            switch (op) {
                case '+':
                    SUM(a, b);
                    break;
                case '-':
                    SUB(a, b);
                    break;
                case '*':
                    MULT(a, b);
                    break;
                case '/':
                    DIV(a, b);
                    break;
                case '%':
                    MOD(a, b);
                    break;
                default:
                    cout << "incorrect" << endl;
                    break;
            }
            break;
        }
        case 2: {
            double a, b;
            char op;
            cin >> a >> op >> b;
            switch (op) {
                case '+':
                    SUM(a, b);
                    break;
                case '-':
                    SUB(a, b);
                    break;
                case '*':
                    MULT(a, b);
                    break;
                case '/':
                    DIV(a, b);
                    break;
                default:
                    cout << "incorrect" << endl;
                    break;
            }
            break;
        }
        case 3:
            input_string();
            break;
        default:
            cout << "incorrect" << endl;
            break;
    }

    return 0;
}
