#include <stdio.h>

void swap(int a, int b);

int main(void){
    int a = 10;
    int b = 20;
    printf("전환 전 %d, %d\n", a, b);
    printf("메인함수에서 a와 b의 주소 %d, %d\n", &a, &b);
    swap(a,b);
    printf("전환 후 %d, %d\n", a, b);



}

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    printf("swap함수에서 a와 b의 주소 %d, %d\n", &a, &b);
}