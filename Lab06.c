// 2. WAP to read string from the user within child process and then
//    print all the permutations of characters of the given string in parent process.

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int permCount = 0;

void permute(char *str, int left, int right) {
    if (left == right) {
        printf("  %d: %s\n", ++permCount, str);
        return;
    }
    for (int i = left; i <= right; i++) {
        swap(&str[left], &str[i]);
        permute(str, left + 1, right);
        swap(&str[left], &str[i]);
    }
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;

    } else if (pid == 0) {
        char str[100];
        printf("Child: Enter a string: ");
        fflush(stdout);
        scanf("%s", str);
        printf("Child: String read = \"%s\"\n", str);
        printf("Child: All permutations of \"%s\":\n", str);
        permute(str, 0, strlen(str) - 1);
        printf("Child: Total permutations = %d\n", permCount);

    } else {
        wait(NULL);
        printf("Parent: Child process completed.\n");
    }

    return 0;
}