#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// Prime check
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int rl, rh;
    printf("Enter range lower range(rl) -> ");
    scanf("%d", &rl);
    printf("Enter range higher range(rh) -> ");
    scanf("%d", &rh);

    FILE *fp;
    int n;
    fp = popen("lscpu | grep '^CPU(s):' | awk '{print $2}'", "r");
    fscanf(fp, "%d", &n);
    pclose(fp);
    printf("Logical CPUs: %d\n", n);
    n += 5;

    int fd = open("prime.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    close(fd);

    int range = rh - rl + 1;

    for (int i = 1; i <= n; i++) {
        printf("\nRunning with %d processes\n", i);

        int fd_head = open("prime.txt", O_WRONLY | O_APPEND);
        char header[100];
        int len = sprintf(header, "\n%d total\n", i);
        write(fd_head, header, len);
        close(fd_head);

        clock_t start = clock();

        int numbers_per_process = range / i;

        // Create children
        for (int j = 0; j < i; j++) {
            pid_t pid = fork();

            if (pid == 0) {
                int start_r = rl + j * numbers_per_process;
                int end_r = (j == i - 1) ? rh
                                         : start_r + numbers_per_process - 1;

                int fd_child = open("prime.txt", O_WRONLY | O_APPEND);

                for (int num = start_r; num <= end_r; num++) {
                    if (isPrime(num)) {
                        char buffer[50];
                        int len = sprintf(buffer, "%d ", num);
                        write(fd_child, buffer, len);
                    }
                }

                close(fd_child);
                exit(0);
            }
        }

        // Parent waits
        for (int j = 0; j < i; j++) {
            wait(NULL);
        }

        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Execution time: %f sec\n", time_taken);

        int fd_time = open("prime.txt", O_WRONLY | O_APPEND);
        char timebuf[100];
        int tlen = sprintf(timebuf, "\nExecution time: %f sec\n", time_taken);
        write(fd_time, timebuf, tlen);
        close(fd_time);
    }

    printf("\nAll results stored in prime.txt\n");
    return 0;
}