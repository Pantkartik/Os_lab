#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
    pid_t pid1 = fork();
    if(pid1 == 0) {
        sleep(2);
        printf("LOLA\n");
        exit(0);
    }
    pid_t pid2 = fork();
    if(pid2 == 0) {
        sleep(4);
        printf("HOLA\n");
        exit(0);
    }
    pid_t pid3 = fork();
    if(pid3 == 0) {
        sleep(6);
        printf("CHILD 3 COMPLETED\n");
        exit(0);
    }
    waitpid(pid3,NULL,0);
    printf("PARENT AA AGAYA, CHILD 3 HO GAYA\n");
    return 0;
}