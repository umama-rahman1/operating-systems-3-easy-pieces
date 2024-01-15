// measurement
// with this one from ch-6-limited-direct-execution/ch-6-measurement-sol.c:
// // write measurement code here
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>      //pipe()

int main()
{
    int x, i, fd[2], p[2];
    char send    = 's';
    char receive;
    pipe(fd);
    pipe(p);
    struct timeval tv;

    while ((x = fork()) == -1);
    if (x==0) {
        gettimeofday(&tv, NULL);
        printf("Before Context Switch Time %u us\n", tv.tv_usec);
        for (i = 0; i < 10000; i++) {
            read(fd[0], &receive, 1);
            write(p[1], &send, 1);
        }
        exit(0);
    }
    else {
        for (i = 0; i < 10000; i++) {
            write(fd[1], &send, 1);
            read(p[0], &receive, 1);
        }
        gettimeofday(&tv, NULL);
        printf("After Context Switch Time %u us\n", tv.tv_usec);
    }
    return 0;
}