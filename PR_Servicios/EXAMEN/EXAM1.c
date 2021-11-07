#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

/**
 *  PROCESO PADRE EJECUTA X HIJOS
 */

int main()
{
    int i;
    int status;
    pid_t pid;

    printf("Padre con ID %d comienza:\n", getpid());

    for (i = 0; i < 3; i++)
    {   
        if(fork()==0){
            
            printf("Hijo %d con padre %d\n", (i + 1), getppid());
            exit(0);
        }
    }
    pid = wait(NULL);
    while (pid != -1)
    {
        pid = wait(NULL);
    }
    printf(" \nPadre esperando a los hijos \n");
    printf("\nTodos los hijos han terminado han terminado\n");
    return 0;
}
