#include <stdio.h>

int arrayAnimal[4][5];
void initAnimalArray(void); // 배열 값 초기화
char * strAnimal[10];   // 동물 이름 리스트
void initAnimalName(void);  // 동물 이름 초기화


int main(){
    initAnimalArray();
    initAnimalName();   
    return 0 ;
}

void initAnimalArray(void){
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            arrayAnimal[i][j] = -1;     //카드 뒷면 설정
        }
    }
}

void initAnimalName(void){
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