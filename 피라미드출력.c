#include <stdio.h>

int main(void){
    int input;
    printf("정수를 입력해주세요 : ");
    scanf("%d", &input);
    for(int i=0; i<=input-1; i++){
        for (int j=0; j<=i; j++){
            printf("*");
        }
    printf("\n");
    }
}