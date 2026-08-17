#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) { //-1 for the error.
        perror("fork failed"); 
    } else if (pid == 0) { // zero for the child
        printf("child\n");
    } else {
        printf("parent\n");// positive for the parent
    }

    return 0;
}