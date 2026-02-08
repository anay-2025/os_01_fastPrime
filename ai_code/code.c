// ai generated ---
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Optimized Prime check: Skip even numbers and use i += 6 rule
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    int rl, rh;
    printf("Enter lower range (rl): ");
    scanf("%d", &rl);
    printf("Enter higher range (rh): ");
    scanf("%d", &rh);

    // Get CPU count efficiently
    int n_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Logical CPUs detected: %d\n", n_cpus);
    int max_procs = n_cpus + 5;

    // Clear file once at the start
    int fd_clear = open("prime.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    close(fd_clear);

    int total_range = rh - rl + 1;

    for (int p_count = 1; p_count <= max_procs; p_count++) {
        printf("Running with %d processes... ", p_count);
        fflush(stdout);

        // Record wall-clock time (clock() is bad for multi-process timing)
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        int chunk = total_range / p_count;

        for (int j = 0; j < p_count; j++) {
            pid_t pid = fork();
            if (pid == 0) {
                int start_r = rl + j * chunk;
                int end_r = (j == p_count - 1) ? rh : start_r + chunk - 1;

                // BUFFERED WRITING: Instead of writing every number,
                // build a string in memory and write it once.
                char *local_buf = malloc(chunk * 12); // Estimated space
                int offset = 0;

                for (int num = start_r; num <= end_r; num++) {
                    if (isPrime(num)) {
                        offset += sprintf(local_buf + offset, "%d ", num);
                    }
                }

                if (offset > 0) {
                    int fd_child = open("prime.txt", O_WRONLY | O_APPEND);
                    write(fd_child, local_buf, offset);
                    close(fd_child);
                }
                
                free(local_buf);
                exit(0);
            }
        }

        for (int j = 0; j < p_count; j++) wait(NULL);

        clock_gettime(CLOCK_MONOTONIC, &end);
        double time_taken = (end.tv_sec - start.tv_sec) + 
                           (end.tv_nsec - start.tv_nsec) / 1e9;

        printf("Done. Time: %.6f sec\n", time_taken);

        // Log results
        FILE *f_log = fopen("prime.txt", "a");
        fprintf(f_log, "\n--- Total Processes: %d | Time: %f sec ---\n", p_count, time_taken);
        fclose(f_log);
    }

    return 0;
}
