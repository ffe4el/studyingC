#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

void main(){
    int pid;
    int i = 0;
    pid = fork();

    if(pid < 0){
        printf("Fail to create child!");
        exit(-1);
    }
    else if(pid == 0){
        for(i = 0; i < 2; i++)
        execlp("/home/bull/ch03/fork/hello", "hello", NULL);        
//      exit(0);
    }else{
        for(i = 0; i < 3; i++)
            printf("I'm parent!!!\n");
  //      exit(0);    
    }
}