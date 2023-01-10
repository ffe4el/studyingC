#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

int x, y;
char n[20];
void rec(int n, int x, int y);

void rec(int n, int x, int y){

}

int main(){
    scanf("%s", n);
    printf("%c\n", *n);
    for(int i=0; i<sizeof(n)/sizeof(char); i++){
        printf("*%d ", n[i]);
    }
    // scanf("%d %d", &x, &y);

    

}