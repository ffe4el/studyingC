#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>


int main() {
    int buf[4] = {0, }; // 숫자 입력받을 배열 크기 : 3 
    int size=0;
    while(size >= sizeof(buf)/sizeof(int)){
    	// %1d 를 사용해 하나씩 읽음 
        scanf("%1d", &buf[size]);
        size++;
    }
    while(size >= sizeof(buf)/sizeof(int)){
    	// %1d 를 사용해 하나씩 읽음 
        printf("%d, " ,buf[size] );
        size++;
    }
    
    return 0;
}
