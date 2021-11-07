#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main()
{   
    int i,a,var,var1;
    int status;
    pid_t pid;

    for (i = 0; i < 3; i++)
    {
        if (fork() == 0)
        {
           
            for (a = 0; a < 2; a++)
            {
                if (fork() == 0)
                {   
                    a++;
                    printf("Soy el nieto %d y padre es el hijo %d\n", getpid(),getppid());
                    exit(0);
                }
                 pid = wait(NULL);
            while (pid != -1)
            {
                pid = wait(NULL);
            }
            }
            i++;
            printf("Soy el hijo %d y mi padre es %d\n", getpid(), getppid());
            exit(0);
           
        }
            pid = wait(NULL);
            while (pid != -1)
            {
                pid = wait(NULL);
            }
    }
     pid = wait(NULL);
            while (pid != -1)
            {
                pid = wait(NULL);
            }
    printf("Soy %d y soy el padre de todos.\n", getpid());
    return 0;
}