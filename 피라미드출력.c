#include <stdio.h>

int main(void){
    int input;
    printf("정수를 입력해주세요 : ");
    scanf("%d", &input);
    for(int i=0; i<input; i++){
        for (int j=i; j<input-1; j++){
            printf(" ");
        }
        for (int k=0; k<i*2+1; k++){
            printf("*");
        }
    printf("\n");
    }
}