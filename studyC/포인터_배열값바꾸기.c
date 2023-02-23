#include <stdio.h>

void changeArray(int * ptr);

int main(void){
    int arr2[3]={10,20,30};
    changeArray(arr2);
    for(int i=0; i<3; i++){
        printf("arr[%d]의 값은 %d 입니다.\n", i, arr2[i]);
    }
    

}

void changeArray(int * ptr){
    ptr[2]=50;
}