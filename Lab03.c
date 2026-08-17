#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    if(pid<0){
        printf("error");
    }else if(pid==0){
        for(int i=1;i<6;i++){
            printf("%d \n",i);
        }
        printf("child processed \n");
        sleep(2);

    }else{
        wait(NULL);
        printf("Parent Completed");
    }
    return 0;
}