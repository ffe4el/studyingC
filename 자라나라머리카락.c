#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    srand(time(NULL));
    int treatment = rand() %4;
    printf("\n\n === 자라나라 머리머리 === \n\n");
    int cntShowBottle = 0; // 이번회차에 조합할 약병 개수
    int prevCntShowBottle = 0; // 앞 회차에서 조합한 약병의 개수
    for(int i =1; i<=3; i++){ // 3회 동안 테스트 진행
        int bottle[4]={0, 0, 0, 0};  // 약병 4개를 담는 배열 선언
        do{                              // 약병의 개수가 다를 때까지 조합
            cntShowBottle= rand() % 2+2; // 조합할 약병의 개수(2~3)
        }while (cntShowBottle == prevCntShowBottle);  
        prevCntShowBottle = cntShowBottle; // 이번회차의 약병개수를 저장

        printf(" >> %d번째 테스트 : " , i);
        int isIncluded = 0; // 진짜 발모제인지 확인용
        for (int j =0; j<cntShowBottle; j++){  // 보여줄 약병 조합해서 선택
            int randomBottle = rand() % 4;   // 약병 번호 뽑기(0~3)
            if (bottle[randomBottle]==0){    // 아직 선택되지 않은 약병이면
                bottle[randomBottle] = 1;    // 값을 0 -> 1
                if(randomBottle == treatment){
                    isIncluded = 1;          // 진짜 발모제가 포함됨!
                }
            }else{                           // 이미 선택됐던 약병이면 중복이므로 다시 선택
                j--;
            }   
        }
        // 사용자에게 테스트 결과 표시
        for(int k = 0; k<4; k++){   // bottle 배열의 값 확인
            if(bottle[k]==1){       // 선택된 약병인지 확인
                printf("%d ", k+1);  // 인덱스+1
            }
        }
            printf("번 물약을 머리에 바릅니다. \n\n");  //안내문구 출력 

            if (isIncluded == 1)                // 약병조합에 발모제가 포함된 경우
            {
                printf("  >> 성공 ! 머리가 났어요 !!\n"); 
            }else{                                // 약병조합에 발모제가 포함 안된 경우
                printf("  >> 실패 ! 머리가 나지 않았어요.. ㅠㅠ\n");
            }

            printf("\n ... 계속 하려면 아무키나 누르세요 ... \n");   // 아무키나 입력받아 다음 테스트 회차로 넘어가기
            (void) getchar();
        
    }

    printf("\n\n발모제는 몇 번일까요? ");   //안내문구 출력 
    int answer;                         // 사용자가 입력한 값을 받은 변수 선언
    scanf("%d", &answer);               // 사용자 입력받기

    if (answer == treatment + 1)        // 진짜 발모제 번호와 같다면
    {
        printf("\n >> 정답입니다!\n");
    }else                               //다르면 정답 알려주기
    {
        printf("\n >> 땡 ! 틀렸어요, 정답은 %d 입니다\n", treatment + 1);
    }
        
    
    return 0;
}