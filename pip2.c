//parent send array of integers to child and child calculated the sum of it
#define SIZE 5
#include<stdio.h>
#include<unistd.h>

int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if(pid>0) { //parent
        close(fd[0]);
        printf("Parent passing array to pipe buffer so that child can take it\n");
        write(fd[1],arr,sizeof(arr));
        close(fd[1]);
    }
    else if(pid==0){ //child
        close(fd[1]);
        int ar[SIZE];
        read(fd[0],ar,sizeof(ar));
        printf("Child read from the pipe : \n");
        for(int i=0;i<SIZE;i++){
            printf("%d ",ar[i]);
        }
        close(fd[0]);
    }
    return 0;
}