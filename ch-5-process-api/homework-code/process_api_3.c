#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?
    printf("hello (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child
        printf("child (pid:%d) says: 'hello'\n", (int)getpid());
    }
    else
    {
        // parent
        // int rc_wait = wait(NULL);

        // wait for child to finish without wait()
        for (int i = 0; i < 100000; i++)
        {
            ;
        }
        printf("parent (pid:%d) says: 'goodbye'\n", (int)getpid());
    }
}