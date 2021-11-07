#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

void manejador(int sig);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USE % s.\n", argv[0], strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (signal(SIGUSR1, manejador) == SIG_ERR)
    {
        fprintf(stderr, "Error en la señal SIGUR1.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (signal(SIGUSR2, manejador) == SIG_ERR)
    {
        fprintf(stderr, "Error en la señal SIGUR2.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (signal(SIGTERM, manejador) == SIG_ERR)
    {
        fprintf(stderr, "Error en la señal SIGTERM.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (signal(SIGINT, SIG_IGN) == SIG_ERR)
    {
        fprintf(stderr, "Error en la señal SIGINT.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    while (1)
        pause();
    return 0;
}

void manejador(int sig)
{
    switch (sig)
    {

    case SIGUSR1:
        if (write(STDOUT_FILENO, "He recibido la señal SIGUSR1.\n", strlen("He recibido la señal SIGUSR1.\n")) == -1)
        {
            fprintf(stderr, "Error en la escritura de la salida estandar.\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
        break;

    case SIGUSR2:
        if (write(STDOUT_FILENO,"He recibido la señal SIGUSR2.\n", strlen("He recibido la señal SIGUSR2")) == -1)
        {
            fprintf(stderr, "Error en la escritura de la salida estandar.\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
        break;

    case SIGTERM:
        if (write(STDOUT_FILENO,"Fin de ejecución.\n", strlen("Fin de ejecución.\n")) == -1)
        {
            fprintf(stderr, "Error en la escritura de la salida estandar.\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
        break;

    default:
        fprintf(stderr,"ERROR, se ha entrado en DEFAULT.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}