//parent write sum and give the sum to child and child checks whether the sum is prime or not

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int checkPrime(int num) {
    int multiple=0;
    for(int i=1;i<=num;i++){
        if(num%i==0) multiple++;
    }
    if(multiple==2) return 1;
    return 0;
}

int arraySum (int arr[],int n) {
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int arr[] = {1,2,3,4,6};
    int n = 6;
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if(pid>0){ //parent
        close(fd[0]);
        int sum = arraySum(arr,n);
        printf("FROM PARENT : got sum : %d\n",sum);
        write(fd[1],&sum,sizeof(sum));
        close(fd[1]);
    }
    else if(pid==0){ //child
        close(fd[1]);
        int num;
        read(fd[0],&num,sizeof(num));
        printf("FROM CHILD : got sum %d\n",num);
        if(checkPrime(num)){
            printf("FROM CHILD :Its prime\n");
        }
        else {
            printf("FROM CHILD : Its not prime\n");
        }
    }
    else {
        printf("Fork Failed\n");
    }
    return 0;
}