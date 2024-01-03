#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("parent (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child: call execl()
        printf("child (pid:%d) calling execl()\n", (int)getpid());
        execl("/bin/ls", "ls", "-l", (char *)NULL);

        // if execl() returns, there was an error
        perror("execl");
        exit(1);
    }
    else
    {
        // parent goes down this path (main)
        int wc = wait(NULL);
        printf("parent (pid:%d) of child (pid:%d)\n", (int)getpid(), rc);

        // call other variants of exec() here if needed
    }
    return 0;
}