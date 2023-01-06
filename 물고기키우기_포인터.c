#include <stdio.h>
#include <time.h>

int level;
int arrayfish[6];
void initData();    // 게임 초기화 함수 선언
void printfishes();     //어항 물 높이 출력 함수 선언


int main(void){
    // long형은 int형과 같이 정수를 담을 때 사용
    long starttime = 0;   // 게임 시작 시간을 담을 변수 선언 및 초기화
    initData(); // 게임 초기화 함수 호출
    starttime = clock();    // 프로그램 수행 이후 현재까지 흐 른 시간을 시작 시간으로 저장
    while(1){               // 어항에 물 주기 무한 반복
        printfishes();         // 어항 물 높이 출력 함수 호출
    }
    return 0;

}

void initData(){
    level=1;
    for(int i=0; i<6; i++){
        arrayfish[i]=100;   // 어항 물높이 초기화
    }

}

void printfishes(){         // 어항 물 높이 출력 함수 정의
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1,2,3,4,5,6);
    for(int i=0; i<6; i++){
        printf(" %3d ", arrayfish[i]);  // 서식 지정자로 출력 결과 출력
    }
    printf("\n\n");     // 가독성을 위해 추가
}