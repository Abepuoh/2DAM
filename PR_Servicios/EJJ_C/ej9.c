/*Vamos a pedir dos valores
El proceso padre hara la suma y el hijo la resta*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int var1, var2;
    pid_t Ppid, ChildPid;
    printf("Introduce el primer valor");
    scanf("%d", &var1);
    printf("Introduce el sergundo valor");
    scanf("%d", &var2);
    ChildPid = fork();
    if (ChildPid == 0)
    {
        printf("\nEl resultado de la resta es: %d\n", var1 - var2);
    }
    else if (ChildPid > 0)
    {
        Ppid = wait(NULL);
        printf("\nel resutlado de la resta es:  %d\n", var1 + var2);
        Ppid = wait(NULL);
    }
}
