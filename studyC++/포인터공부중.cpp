#include <iostream>
using namespace std;

int x = 7;            // 변수의 선언

int *ptr = &x;      // 포인터의 선언

int **pptr = &ptr; // 포인터의 참조

int main(){
    cout << *ptr;
    cout << "\n";
    cout << **pptr;
}