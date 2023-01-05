#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    srand((unsigned int)time(NULL)); //난수 초기화
    int num = rand() % 100+1;
    printf("정답 : %d\n\n", num);
    int answer = 0;
    int chance = 5;
    while(1){
        printf("남은 기회는 %d 번 입니다.", chance--);
        printf("숫자를 입력해주세요(1~100) : ");
        scanf("%d", &answer);
        if(answer < num){
            printf("UP!\n\n");
        }
        else if(answer > num){
            printf("DOWN!\n\n");
        }
        else if (answer == num){
            printf("정답입니다~!!\n\n");
            break;
        }
        else{
            printf("1부터 100까지 사이의 숫자를 입력해주세요. \n\n");
        }
        if(chance==0){
            printf("모든기회를 사용하셨습니다ㅠㅠ.");
            break;
        }
    }
    return 0 ;
}