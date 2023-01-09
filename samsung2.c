#include <stdio.h>
#include <string.h>
#include <stdlib.h> //atoi(아스키코드에서 문자열을 정수로 변환해주는 함수)

int main(){
    // 밑에 3개는 입력 받을 수 있게끔..
    int n = 16;
    char x[10]= "1";
    char y[10]= "3";
    int xy; //x와 y로 조합할 수 있는 숫자 초기화
    strcat(x,y);
    // printf("%s\n", x);
    // int z = x - '0';
    xy = atoi(x);
    // printf("%d\n", xy);
    
    if(n>xy){
        printf("%d\n", xy);
    }
    else{
        printf("주어진 숫자보다 큽니다.");
    }



    printf("\n");
    return 0;
}