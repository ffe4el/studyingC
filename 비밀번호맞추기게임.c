#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);


int main(void){
    srand(time(NULL));
    
    for(int i=1; i<=5; i++){
        int num1= getRandomNumber(i);
        int num2 = getRandomNumber(i);
        showQuestion(i, num1, num2);
        int answer = -1;
        scanf("%d", &answer);
        printf("----\n");
        if(answer==num1*num2){
            printf("맞췄습니당\n");
        }
        else{
            printf("틀렸습니다\n");
        }
    }
}


int getRandomNumber(int level){
    int num = rand() % (level*9)+1;
    return num; 
}

void showQuestion(int level, int num1, int num2){
    printf("%d 번째 단계\n", level);
    printf("%d x %d ?\n", num1, num2);
    printf("정답을 입력하세요 => (종료를 원하시면 -1 입력)\n");
}
