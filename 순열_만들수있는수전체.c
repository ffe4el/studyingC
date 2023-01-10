#include <stdio.h>

void rec(int);
int n;
int dap[20];

void rec(int x){
    if(x==4){
        for(int i=0; i<4; i++){
            printf("%d ", dap[i]);
        }
        printf("\n");
        return;
    }
    dap[x]=1;
    rec(x+1);
    dap[x]=2;
    rec(x+1);
    dap[x]=3;
    rec(x+1);
    dap[x]=4;
    rec(x+1);
}

int main(){
    rec(0);
    return 0;
}