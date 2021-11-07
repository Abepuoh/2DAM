#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>


void manejador(int signum)
{
    switch (signum){
            case SIGUSR1:
                printf("Comienza a escribir\n");
                break;   
            case SIGUSR2 :
                printf("Comienza a leer\n");
                break;
    }
     
}

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;
    char cad1[100];
    char cad2[100];
    int aux = 1;
    FILE *pf;

    pid = fork();
    if(pid==-1) {
        printf("error");
    }else if (pid == 0) {
        kill(getppid(), SIGUSR1);
        pause();
        pf = fopen("ej3.txt", "r");
        printf("%s", cad1);
        fclose(pf);
        exit(EXIT_SUCCESS);

    } else {
        signal(SIGUSR1, manejador);
        pause();
        while(aux != 0) {
            pf = fopen("ej3.txt", "a");
            printf("Introduce Palabra: ");
            scanf("%s", cad2);
            fprintf(pf,"%s",cad2);
            fclose(pf);
            scanf("%d", &aux);
        }
        kill(getppid(), SIGUSR2);
       
    }


    
    
}

