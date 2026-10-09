#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
int main(){
    pid_t pid1,pid2,pid3,ter;
    pid1 = fork();
    if(pid1==0) {
        sleep(2);
        printf("Child 1 for 2, ");
        printf("%d\n",getpid());
        exit(0);
    }
    pid2 = fork();
    if(pid2==0) {
        sleep(4);
        printf("Child 2 for 2, ");
        printf("%d\n",getpid());
        exit(0);
    }
    pid3 = fork();
    if(pid3==0) {
        sleep(6);
        printf("child 3 for 2, ");
        printf("%d\n",getpid());
        exit(0);
    }
    ter = wait(NULL);
    printf("firs child pid = %d\n",ter);
    ter = wait(NULL);
    printf("sec child pid = %d\n",ter);
    ter = wait(NULL);
    printf("third child pid = %d\n",ter);

    return 0;
}