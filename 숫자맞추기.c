#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    srand((unsigned)time(NULL)); //난수 초기화
    int num = rand() % 100+1;
    printf("%d", num);
    int answer = 0;
    scanf("%d", &answer)
}