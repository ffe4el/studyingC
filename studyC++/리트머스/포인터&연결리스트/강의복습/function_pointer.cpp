#include <cstdio>

void foo(int a){

    printf("foo : %d\n", a);
}

int main(){
    //f는 함수의 주소를 담는 Pointer type이다.
    void (*f)(int);

    f= foo;
    f(10); //==foo(10)
    (*f)(10); //==f(10)

    // 세가지 표현은 완전히 동일하다.
    // foo(10) == f(10) ==(*f)(10)

    return 0;
}