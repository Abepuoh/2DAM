#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Funcion de tramamiento de la señal
void Tratamiento1(int numsig)
{
    FILE *fp;
    switch (numsig)
    {
    case SIGINT:
        fp = fopen("señales.txt", "a");
        fprintf(fp, " Proceso %d Señal recibida %d \n", getpid(), numsig);
        fclose(fp);
        ;
    case SIGTSbreakTP:
        printf("Has terminado el proceso %d", getpid());
        exit(0);
    }
}

int main()
{

    // Estamos a la escucha de CTRL+C
    signal(SIGINT, Tratamiento1);
    // Estamos a la escucha de CTRL+Z
    signal(SIGTSTP, Tratamiento1);

    puts(" Proceso activo esperando señales ");

    // Ciclo infinito de espera por una señal
    while (1)
    {   //PARA UN PROCESO HASTA QUE RECIBE LA SEÑAL
        pause();
        // Muestra el caracter + despues de cada señal
        putchar('+');
    }
}