// write measurement code here
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>

#define ITERATIONS 1000000

void measure_syscall_cost()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    for (int i = 0; i < ITERATIONS; i++)
    {
        read(0, NULL, 0);
    }
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
    printf("System call cost: %f microseconds\n", elapsed * 1e6 / ITERATIONS);
}

void measure_context_switch_cost()
{
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);
    if (fork() == 0)
    {
        // Child process
        for (int i = 0; i < ITERATIONS; i++)
        {
            read(pipe1[0], NULL, 0);
            write(pipe2[1], "", 1);
        }
    }
    else
    {
        // Parent process
        struct timeval start, end;
        gettimeofday(&start, NULL);
        for (int i = 0; i < ITERATIONS; i++)
        {
            write(pipe1[1], "", 1);
            read(pipe2[0], NULL, 0);
        }
        gettimeofday(&end, NULL);
        long seconds = end.tv_sec - start.tv_sec;
        long microseconds = end.tv_usec - start.tv_usec;
        double elapsed = seconds + microseconds * 1e-6;
        printf("Context switch cost: %f microseconds\n", elapsed * 1e6 / ITERATIONS);
    }
}

int main()
{
    // measure_syscall_cost();
    measure_context_switch_cost();
    return 0;
}