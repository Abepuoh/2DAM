#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t Ppid, ChildPid, ChildPid1, ChildPid2;
    ChildPid = fork();
    if (ChildPid == 0)
    {
        printf("\nEl hijo%d y el padre %d", getpid(), getppid());
    }
    else if (ChildPid > 0)
    {
        Ppid = wait(NULL);
        printf("\n P %d", getpid());
        Ppid = wait(NULL);
        ChildPid1 = fork();
        if (ChildPid == 0)
        {
            printf("\nEl hijo2%d y el padre %d", getpid(), getppid());
        }
        ChildPid2 = fork();
        if (ChildPid == 0)
        {
            printf("\nEl hijo3%d y el padre %d", getpid(), getppid());
        }
    }
}
