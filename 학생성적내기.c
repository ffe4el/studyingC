#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sum(int sc[]);

int main(void){
    srand(time(NULL));
    int score[5] = {0,0,0,0,0};
    for(int i=0; i<5; i++){
        int randomScore = rand() % 100;
        score[i] = randomScore;
        printf("%d\n", score[i]);
    }
    printf("%lu \n", sizeof(score)/sizeof(int));
    int a = sum(score);
    printf("총점은 %d 점 이고, 평균은 %d 점 입니다.", a, a/(sizeof(score)/sizeof(int)));
}

int sum(int sc[]){
    int sum=0;
    for (int i = 0; i < sizeof(sc)/sizeof(int); i++)    // 배열의 요소 개수만큼 반복
    {
        sum += sc[i];    // sum과 배열의 요소를 더해서 다시 sum에 저장
    }
    return sum;
}