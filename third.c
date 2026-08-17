#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); //execlp() //wait()

    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
    } else {
        wait(NULL);
        printf("Child finished, parent exiting\n");
    }
    return 0;
}