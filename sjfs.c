#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n, at[10], bt[10], ct[10], tat[10], wt[10];
    int p[10], time = 0, done[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter AT and BT of P%d: ", p[i]);
        scanf("%d%d", &at[i], &bt[i]);
    }

    pid_t pid = fork();

    if (pid == 0) {
        for (int count = 0; count < n; count++) {
            int min = -1;
            for (int i = 0; i < n; i++) {
                if (!done[i] && at[i] <= time) {
                    if (min == -1 || bt[i] < bt[min])
                        min = i;
                }
            }

            if (min == -1) {
                time++;
                count--;
                continue;
            }

            time += bt[min];
            ct[min] = time;
            tat[min] = ct[min] - at[min];
            wt[min] = tat[min] - bt[min];
            done[min] = 1;
        }

        printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

        for (int i = 0; i < n; i++)
            printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
                   p[i], at[i], bt[i],
                   ct[i], tat[i], wt[i]);
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Parent: Child completed\n");
    }

    return 0;
}