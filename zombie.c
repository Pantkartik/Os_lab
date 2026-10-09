#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void) {
    pid_t pid = fork();

    if(pid>0){ //parent
        sleep(20);
        printf("Parent resumes after 20 sec, but child had executed and left already, parent havent collected its exit status\n");
    }
    else if(pid==0){
        printf("Child process running\n");
        printf("Child process executed left\n");
    }
    else {
        printf("Fork failed");
    }
    return 0;
}