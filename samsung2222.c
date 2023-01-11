#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

int n[256];

int main(){
    for(int i =0; i<10; i++){
        scanf("%1d", &n[i]);
    }
    
    for(int i=0; i<10; i++){
    printf("%d, " , n[i]);
    }
    

}