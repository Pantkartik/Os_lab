#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if(pid==0){ //child
        close(fd[0]);
        char mess[] = "Hello from Child";
        write(fd[1],mess,sizeof(mess));
        close(fd[1]);
    }
    else if(pid>0){ //parent
        close(fd[1]);
        char buffer[100];
        read(fd[0],buffer,sizeof(buffer));
        printf("Parent read %s from child",buffer);
        close(fd[0]);
    }
    else {
        printf("Fork failed");
    }
    return 0 ;
}