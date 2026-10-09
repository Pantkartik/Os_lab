#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int status;
    pid_t pid = fork();
    if(pid==0) { //child
        printf("Child is curently running, and exiting with status 10...\n");
        exit(10);
    }
    else if(pid>0) { //parent
        wait(&status);
        printf("PArent is currently running\n");
        if(WIFEXITED(status)) {
            printf("Child exited with exit status : %d",WEXITSTATUS(status));
        }
    }
    else{
        printf("Fork failes!!!");
    }

    return 0;
}