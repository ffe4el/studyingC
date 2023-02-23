#include <stdio.h>

void card(int x);     // 함수선언
int n;                // 
int dap[20], check[20]={0,};    //배열 선언

void card(int x){
    if(x==n){
        for(int i=0; i<n; i++){
            printf("%d ", dap[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0; i<n;i++){
        if(check[i]==0){
            check[i]=1;
            dap[x] = i+1;
            card(x+1);
            check[i]=0; // 초기화
        }
    }
}


int main(){
    scanf("%d", &n);
    card(0);
    return 0;
}