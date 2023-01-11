#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int result = 0, n, arr[10];
int tc;
// int num;

void recursive(int num, int ten) {
    if (num > n) {
        return;
    }
    result = max(result, num);
    // printf("! %d", result);
    // printf("\n");
    for (int i = 0; i < 2; i++) {
        recursive(num + arr[i] * ten, ten * 10);
    }
    if(num>n) {
        result=-1;
    }
    
}

int main() {
    scanf("%d", &tc);
    for(int j=0; j<tc; j++){
        scanf("%d", &n);
        for (int i = 0; i < 2; i++) {
            scanf("%d", &arr[i]);
        }
        result = 0;
        recursive(0, 1);
        printf("#%d %d", j+1,result);
    }
    return 0;
}