#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5];
void initAnimalArray(); // 배열 값 초기화
char * strAnimal[10];   // 동물 이름 리스트
void initAnimalName();  // 동물 이름 초기화
void shuffleAnimal();    // 동물 이름을 카드지도위에 무작위 배치
int getEmptyPosition(); // 카드지도에서 빈공간을 찾아 위치 반환
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimal();
void printQuestion();
int checkAnimal[4][5];
int failCount=0;
int foundAllAnimals();

int main(){
    srand(time(NULL)); //난수 초기화
    initAnimalArray();
    initAnimalName();   
    shuffleAnimal();
    while(1){
        int select1 = 0;
        int select2 = 0;
        printAnimal();
        printQuestion();
        printf("\n뒤집을 카드 2장을 고르세요.(12 4) -> ");
        scanf("%d %d", &select1, &select2);
        if (select1==select2){  //같은 카드 선택시 무효처리
            continue;   //반복문 시작으로 다시 돌아가기
        }
        int select1_x=conv_pos_x(select1);
        int select1_y=conv_pos_y(select1);
        int select2_x=conv_pos_x(select2);
        int select2_y=conv_pos_y(select2);
        // 두 카드가 같은 동물이고 뒷면인 경우
        if((checkAnimal[select1_x][select1_y]==0
            &&checkAnimal[select2_x][select2_y]==0)
            && (arrayAnimal[select1_x][select1_y]==arrayAnimal[select2_x][select2_y]))
        {
            printf("\n\n 빙고! : %s 발견\n\n", strAnimal[arrayAnimal[select1_x][select1_y]]);
            checkAnimal[select1_x][select1_y] = 1;
            checkAnimal[select2_x][select2_y] = 1;
        }
        // 두 카드가 다른 동물이거나 앞면인 경우
        else
        {
            printf("\n\n 땡!! (틀렸거나, 이미 뒤집힌 카드입니다)\n");
            printf("%d : %s\n", select1, strAnimal[arrayAnimal[select1_x][select1_y]]);
            printf("%d : %s\n", select2, strAnimal[arrayAnimal[select2_x][select2_y]]);
            printf("\n\n");
            failCount++;
        }
        // 모두 다 찾았을때
        if (foundAllAnimals() == 1)
        {
            printf("\n\n 축하합니다 ! 모든 동물을 다 찾았네요 \n");
            printf("지금까지 총 %d 번 실수하였습니다\n", failCount);
            break;
        }
    }
    return 0 ;
}

void initAnimalArray(){
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            arrayAnimal[i][j] = -1;     //카드 뒷면 설정
        }
    }
}

void initAnimalName(){
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";
    strAnimal[5] = "코끼리";
    strAnimal[6] = "기린";
    strAnimal[7] = "낙타";
    strAnimal[8] = "타조";
    strAnimal[9] = "호랑이";
}

void shuffleAnimal(){
    for(int i=0; i<10; i++){
        for(int j =0; j<2; j++){
            int pos = getEmptyPosition(); // 카드지도에서 빈공간을 찾아 위치 반환
            int x = conv_pos_x(pos);    //pos를 x의 (4,5)배열로 변환
            int y = conv_pos_y(pos);    //pos를 y의 (4,5)배열로 변환
            arrayAnimal[x][y]= i;
        }
    }
}

int getEmptyPosition(){
    while(1){
        int randPos = rand() % 20;
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);
        if (arrayAnimal[x][y] == -1){
        return randPos;
        }
    }
    return 0;
}

int conv_pos_x(int x){
    return x/5;
}

int conv_pos_y(int y){
    return y%5;
}

void printAnimal(){
    printf("\n =====동물의 위치를 보여줍니다==== \n\n");
    for(int i=0; i<4; i++){
        for(int j=0; j<5;j++){
            printf("%8s", strAnimal[arrayAnimal[i][j]]);

        }
        printf("\n");
    }
    printf("\n==================\n");
}

void printQuestion(){
    printf("\n(문제)\n\n");
    int seq = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<5;j++){
            if(checkAnimal[i][j] != 0){     //카드가 앞면일때
                printf("%8s", strAnimal[arrayAnimal[i][j]]);
            }
            else {      //카드가 뒷면일때
                printf("%8d", seq); //카드번호 출력
            }
            seq++;
        }
        printf("\n");
    }
    
}

int foundAllAnimals(){
    for(int i=0; i<4; i++){
        for(int j=0; j<5;j++){
            if(checkAnimal[i][j]==0){
                return 0;   // 뒤집지 않은 카드가 있음
            }
        }
    }
    return 1;   // 모든 카드 뒤집음
}