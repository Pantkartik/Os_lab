#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) { 
        perror("fork failed"); 
    } else if (pid == 0) { 
        printf("child\n");
    } else {
        printf("parent\n");
    }

    return 0;
}