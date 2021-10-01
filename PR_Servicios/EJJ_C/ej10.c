#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int c;
    int a;
    int status;
    pid_t pid;

    printf("Padre con ID %d comienza:\n", getpid());

    for (c = 0; c < 3; c++)
    {
        if (fork() == 0)
        {
            printf("Hijo %d con padre %d\n", (c + 1), getppid());
            printf(" \n Hijo esperando a los subhijos \n");
            pid = wait(NULL);
            while (pid != -1)
            {
                pid = wait(NULL);
            }
            printf("\nTodos los hijos han terminado han terminado\n");

            for (a = 0; a < 3; a++)
            {
                printf("SubHijo %d con padre %d\n", (c + 1), getppid());
            }
            exit(0);
        }
    }

    printf(" \nPadre esperando a los hijos \n");
    pid = wait(NULL);
    while (pid != -1)
    {
        pid = wait(NULL);
    }
    printf("\nTodos los hijos han terminado han terminado\n");

    return 0;
}
