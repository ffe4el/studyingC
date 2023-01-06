#include <stdio.h>


int level;
int arrayfish[6];
void initData();    // 게임 초기화 함수 선언


int main(void){
    initData(); // 게임 초기화 함수 호출

    return 0;
}

void initData(){
    level=1;
    for(int i=0; i<6; i++){
        arrayfish[i]=100;   // 어항 물높이 초기화
    }

}