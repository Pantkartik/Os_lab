#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n, at[10], bt[10], ct[10], tat[10], wt[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("\nChild process calculating FCFS\n");

        int time = 0;

        for (int i = 0; i < n; i++) {
            if (time < at[i])
                time = at[i];

            ct[i] = time + bt[i];
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];

            time = ct[i];
        }

        printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

        for (int i = 0; i < n; i++)
            printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
                   i + 1, at[i], bt[i],
                   ct[i], tat[i], wt[i]);
    }
    else if (pid > 0) {
        // Parent process
        wait(NULL);
        printf("Parent: Child process completed\n");
    }

    return 0;
}