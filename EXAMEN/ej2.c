#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include<string.h>

int main(int argc, char *argv[]) {
    int fd[2],status;
    char *msn,i='1';
    char buffer[80];

    pipe(fd);

    pid_t pid = fork();
    if (pid ==-1) {
        printf("fork error\n");
    }
    if (pid == 0) {
        close(fd[0]);
        //mientras i sea distinto de 0 escribo en el pipe
        while(i=='0'){
            printf("Ingrese mensaje: ");
            scanf("%d",msn);
            write(fd[1],msn,strlen(msn));
            close(fd[1]);
            i = msn;
        }
    }
    else {
        close(fd[1]);
        while(i!='0'){
            read(fd[0], buffer, sizeof(buffer));
            //sino es 0 lo muestra
            printf("\n Soy el padre %d y mi hijo %d me envía estas palabras: %s \n",getpid(),getppid(),buffer);
            i=strcmp(buffer,"0");
                }
    }
    return 0;
}
