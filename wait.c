#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        // Child Process
        printf("Child: PID = %d\n", getpid());
        printf("Child is running...\n");
        sleep(2); // Child works for 2 seconds
        printf("Child finished.\n");
    }
    else {
        // Parent Process
        printf("Parent: PID = %d\n", getpid());

        wait(NULL);   // Parent waits until child finishes

        printf("Parent resumes after child finishes.\n");
    }

    return 0;
}