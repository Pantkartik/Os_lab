// 1. WAP to find sum of elements in an array within child process
//    and then check whether the given sum is prime or not in parent process.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int arr[] = {2, 3, 5, 7, 6};
    int arrsize=sizeof(arr);
    
    int n = arrsize / sizeof(arr[0]);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;

    } else if (pid == 0) {
        
        int sum = 0;
        printf("Child: Array elements: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
        printf("\nChild: Sum = %d\n", sum);

        if (isPrime(sum)) {
            printf("Child: %d is a PRIME number.\n", sum);
        } else {
            printf("Child: %d is NOT a prime number.\n", sum);
        }

    } else {
        
        wait(NULL);
        printf("Parent: Child process completed.\n");
    }

    return 0;
}