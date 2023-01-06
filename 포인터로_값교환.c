#include <stdio.h>

void swap(int a, int b);
void swap_addr(int * a, int * b);

int main(void)
{
    int a = 10;
    int b = 20;
    printf("a 의 주소 : %p\n", &a);
    printf("b 의 주소 : %p\n", &b);

    printf("swap() 함수 호출 전 => a : %d, b : %d\n", a, b);
    swap(a, b);
    printf("swap() 함수 호출 후 => a : %d, b : %d\n", a, b);

    printf("swap_addr() 함수 호출 전 => a : %d, b : %d\n", a, b);
    swap_addr(&a, &b);          // 매개변수로 포인터 함수를 전달하면, 인수로는 메모리 주소를 전달해야한다.
    printf("swap_addr() 함수 호출 후 => a : %d, b : %d\n", a, b);

    return 0;
}


void swap(int a, int b)
{
    printf("swap() 함수 안에서 a의 주소 : %p\n", &a);
    printf("swap() 함수 안에서 b의 주소 : %p\n", &b);

    int temp = a;
    a = b;
    b = temp;
    printf("swap() 함수 안 => a : %d, b : %d\n", a, b);
}

void swap_addr(int* a, int * b)
{   
    printf("swap_addr() 함수 안에서 a의 주소 : %p\n", a);
    printf("swap_addr() 함수 안에서 b의 주소 : %p\n", b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("swap_addr() 함수 안 => a : %d, b : %d\n", *a, *b);
}
