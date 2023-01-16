#include <stdio.h>

int arrayAnimal[4][5];
void initAnimalArray(); // 배열 값 초기화

int main(){
    return 0 ;
}

void initAnimalArray(){
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            arrayAnimal[i][j] = -1;
        }
    }
}