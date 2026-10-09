#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
    int status;
    pid_t pid = fork();

    if(pid==0){
        printf("Child running and giving exit code as 5\n");
        return 5;
    }

    else if(pid>0){
        wait(&status);
        if(WIFEXITED(status)){
            printf("Child left parent by exit code %d",WEXITSTATUS(status));
        }
    }
    else {
        printf("false");
    }

    return 0;
}