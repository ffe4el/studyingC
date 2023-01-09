#include <stdio.h>

int main(){
    int i;
    int j;
    int arr2d[3][3];

    // scanf로 데이터 입력받기
    for(i=0; i<3;i++){
        for (j=0; j<3; j++ ){
            printf("arr2d[%d][%d] : ", i,j);
            scanf("%d", &arr2d[i][j]);
        }
    }
    
    
    // 확인용
    for(i=0; i<3;i++){
        for(j=0; j<3; j++ ){
            printf("    arr2d[%d][%d] : %d \n", i,j, arr2d[i][j]);

        }
    }
}