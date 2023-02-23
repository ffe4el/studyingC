#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int level;
int arrayfish[6];
int * cursor;   // 허걱! 포인트 사용!! 

void initData();    // 게임 초기화 함수 선언
void printfishes();     //어항 물 높이 출력 함수 선언
void decreasewater(long elapsedtime);
int checkfishalive();



int main(void){
    // long형은 int형과 같이 정수를 담을 때 사용(시간은 long형을 쓴다!!)
    long starttime = 0;   // 게임 시작 시간을 담을 변수 선언 및 초기화
    int num;    // 물을 줄 어항 번호
    long totalelapsedtime=0;    // 총 경과 시간
    long prevelapsedtime=0;     // 직전에 물을 준 시간(물을 준 시간 간격)


    initData(); // 게임 초기화 함수 호출
    starttime = clock();    // 프로그램 수행 이후 현재까지 흐 른 시간을 시작 시간으로 저장
    cursor = arrayfish;     // 포인트변수에 어항 배열의 시작 주소 넣기!!!

    while(1){               // 어항에 물 주기 무한 반복
        printfishes();         // 어항 물 높이 출력 함수 호출
        printf("몇번 어항에 물을 줄까요? (1~6) ");  // 입력 안내 문구
        scanf("%d", &num);      // 어항 번호 입력받기
        if (num < 1 || num > 6){        // 입력값 확인
            printf("\n입력값이 잘못됐습니다. \n");
            continue;
        }

        // 총 경과 시간, 초 단위로 표시
        totalelapsedtime = (clock() - starttime)/CLOCKS_PER_SEC;     // 총 경과 시간, 초 단위로 표시
        printf("총 경과 시간 : %ld초\n", totalelapsedtime);         // 총 경과 시간 출력
        //  물을 준 시간 간격
        prevelapsedtime = totalelapsedtime - prevelapsedtime;    // 직전에 물 준 시간 이후로 흐른 시간    
        printf("최근 경과 시간 : %ld초\n", prevelapsedtime);        // 최근 경과 시간 출력


        decreasewater(prevelapsedtime);         // 어항의 물을 증발(감소)시키는 함수 호출

        // 사용자가 입력한 번호의 어항에 물 주기
        // 조건1. 어항의 물 높이가 0 이하면 물을 주지 않음
        if (cursor[num - 1] <= 0)
        {
            printf("%d 번 물고기는 이미 죽었습니다.. 물을 주지 않습니다\n", num);
        }
        // 2. 어항의 물 높이가 0 초과면 100을 넘지 않는지 확인하고 물을 줌
        else if (cursor[num - 1] + 1 <= 100)
        {
            // 물을 준다
            printf("%d 번 어항에 물을 줍니다\n\n", num);
            cursor[num - 1] += 1; // cursor[num - 1] = cursor[num - 1] + 1
        }

        // 레벨업 확인(레벨업은 20초마다 한 번씩 수행)
        if (totalelapsedtime / 20 > level - 1)
        {
            // 레벨업
            level++; // level : 1 -> level : 2 -> level : 3...
            printf("*** 축하합니다. %d레벨에서 %d레벨로 올랐습니다. ***\n\n", level - 1, level);
            if (level == 5) // 최고 레벨
            {
                printf("\n\n축하합니다. 최고 레벨을 달성했습니다. 게임을 종료합니다\n\n");
                exit(0);
            }
        }

        // 모든 물고기가 죽었는지 확인
        if (checkfishalive() == 0)
        {
            // 물고기가 모두 죽음
            printf("모든 물고기가 죽었습니다. ㅠㅠ \n");
            exit(0);
        }
        else
        {
            // 물고기가 최소 한 마리 이상 살아 있음
            printf("물고기가 아직 살아 있어요!\n");
        }
        prevelapsedtime = totalelapsedtime;

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
        printf(" %4d ", arrayfish[i]);  // 서식 지정자로 출력 결과 출력
    }
    printf("\n\n");     // 가독성을 위해 추가
}

void decreasewater(long elapsedtime){   //어항의 물을 증발시키는 함수
    for (int i = 0; i < 6; i++)
    {
        arrayfish[i] -= (level * 3 * (int)elapsedtime); //증발하는 물의 양 계산
        if (arrayfish[i] < 0)       // 물 높이가 0 미만이면 물 높이를 0으로 고정
        {
            arrayfish[i] = 0;       
        }
    }

}


int checkfishalive(){       // 모든 물고기가 죽었는지 확인하는 함수
    for (int i = 0; i < 6; i++)
    {
        if (arrayfish[i] > 0)
            return 1; // 참 True
    }
    return 0;
}