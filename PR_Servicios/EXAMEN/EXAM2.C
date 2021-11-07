#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

/**
 *  SE CREAN 3 HIJOS y 3 NIETOS
 */
int main()
{   
    int i,a,var,var1;
    int status;
    pid_t pid;

    printf("Introduce el numero de hijos: ");
	scanf("%d",&var);
    printf("Introduce el numero de nietos: ");
	scanf("%d",&var1);
    printf("Padre con ID %d comienza:\n", getpid());

    for (i = 0; i < var; i++)
    {
        if (fork() == 0)
        {
            printf("Hijo %d con padre %d\n", (i + 1), getppid());
           
            for (a = 0; a < var1; a++)
            {
                if (fork() == 0)
                {
                    printf("NIETO %d con padre %d\n", (a + 1), getppid());
                    exit(0);
                }
            }
            exit(0);
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
    }
   
    printf("\nTodos los hijos han terminado han terminado\n");
    return 0;
}
