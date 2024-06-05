#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    pid_t pid;

    pid = fork();

    if(pid < 0){
        fprintf(stderr,"Child Creation  Failed!!");
        return 1;
    }else if(pid == 0){
        printf("I'm a Child!!\n");
    }else{
        wait(NULL);
        printf("Baby, You just finished!!\n");
    }
    return 0;
}