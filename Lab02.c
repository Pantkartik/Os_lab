#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    pid_t pid = fork();
    if(pid<0){
        printf("error");

    }else if(pid==0){
        printf("child process \n");
        sleep(2);
        
    }else{
        wait(NULL);
        printf("parent process\n");
        printf("child process completed ");
        
        
    }
    return 0;
}