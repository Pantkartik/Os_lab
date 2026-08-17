#include <stdio.h>
#include <unistd.h>
int main(){
    pid_t pid = fork();
    if(pid<0){
        printf("failed");
    }else if(pid==0){
        printf("childID : %d parentID :%d \n",getpid(),getppid());

    }else{
        printf("parentID :%d childId :%d",getpid(),pid);
    }
    return 0;
}