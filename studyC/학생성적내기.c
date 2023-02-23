#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sum(int sc[],int b);

int main(void){
    srand(time(NULL));
    int score[5] = {0,0,0,0,0};
    for(int i=0; i<5; i++){
        int randomScore = rand() % 100;
        score[i] = randomScore;
        printf("%d\n", score[i]);
    }
    int b = sizeof(score)/sizeof(int);
    printf("%d \n", b);
    float a = sum(score, b);
    float c = a/b;
    printf("총점은 %.0f 점 이고, 평균은 %.2f 점 입니다.", a, c);
}

int sum(int sc[], int b){
    int sum=0;
    for (int i = 0; i < b; i++)    // 배열의 요소 개수만큼 반복
    {
        sum += sc[i];    // sum과 배열의 요소를 더해서 다시 sum에 저장
    }
    printf("** %d \n", sum);
    return sum;
}