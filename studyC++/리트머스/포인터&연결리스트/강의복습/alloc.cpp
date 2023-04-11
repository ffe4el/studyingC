// alloc.cpp : new 를 이용하여 1000개의 char를 위한 메모리를 할당하고
// delete를 이용하여 메모리를 반납한다.
#include <cstdio>
int main(void){
    char *str;

    str = new char [1000];
    if(str == NULL){
        printf("Insufficient memory available\n");
    }
    else {
        printf("Allocated 1000 bytes\n");
        delete[] str;
        printf("Memory freed.\n");
    }
    return 0;
}