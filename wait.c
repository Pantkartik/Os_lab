#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        
        printf("Child: PID = %d\n", getpid());
        printf("Child is running...\n");
        sleep(2); 
        printf("Child finished.\n");
    }
    else {
        printf("Parent: PID = %d\n", getpid());

        wait(NULL);   

        printf("Parent resumes after child finishes.\n");
    }

    return 0;
}