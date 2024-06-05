#include <unistd.h>
#include <stdio.h>

int main(void){
    pid_t pid;
    
    printf("Before fork()\n");
    
    pid = fork();

    printf("Hello, FORK\n");
    printf("After fork() :PID=%d\n", pid);
}