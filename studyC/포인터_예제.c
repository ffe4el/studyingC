#include <stdio.h>

void square(int * a);

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i=0; i<10; i++){
        // printf("!!%d", arr[i]);
        square(&arr[i]);
        
    }
    for(int i=0; i<10; i++){
        printf("%d", arr[i]);
        if (i+1 <10){
            printf(", ");
        }
    }
    printf("\n");
    return 0;
}

void square(int *a){
    if (*a % 2 == 0){
        *a = (*a) * (*a) ;
    } 
    else {
        *a = *a;
    }
}
