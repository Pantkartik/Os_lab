#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int fact(int num){
    int temp = num;
    int mul = 1;
    while(temp>0){
        mul = mul*temp;
        temp--;
    }
    return mul;
}
int main(){
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);
    int num=5;
    pid_t pid = fork();
    if(pid>0) { //parent
        close(fd1[0]); //red of
        close(fd2[1]); // write 
        printf("Parent send integer %d to child\n",num);
        write(fd1[1],&num,sizeof(num));
        wait(NULL);
        int numm;
        read(fd2[0],&numm,sizeof(numm));
        printf("Parent got %d from pipeee",numm);
        close(fd2[0]);
    }
    else if(pid==0)  {//child
        close(fd1[1]);
        close(fd2[0]);
        int num;
        read(fd1[0],&num,sizeof(num));
        int factorial = fact(num);
        printf("Child calculates factorial of %d as %d and put it in pipe\n",num,factorial);
        close(fd1[0]);
        write(fd2[1],&factorial,sizeof(factorial));
        close(fd2[1]);
    }

    return 0;
}