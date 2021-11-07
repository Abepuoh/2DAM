#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
/*Desarrolla un programa en C, que cree un proceso hijo y un proceso nieto. 
El proceso hijo debe escribir al padre el mensaje: "Hola papá,¿Hablamos?". 
El proceso nieto debe escribir al abuelo el mensaje: "hola abuelo, ¿Cómo estás?".
El proceso padre debe leer los dos mensajes.
*/

//read-->fd[0]
//write-->fd[1]

int main(int argc, char const *argv[])
{
    int fd1[2], fd2[2];
    char buffer[80], buffer1[80];
    pid_t pid,pid1,status;

    pipe (fd1);
    pipe (fd2);

    char *msnpadre = "Hola papá, ¿Hablamos?";
    char *msnhijo = "Hola abuelo, ¿Cómo estás?";

    pid=fork();

    if(pid==-1){
        printf("ERROR");
    }else if (pid==0){


        pid1=fork();
        if(pid1==-1){
            printf("ERROR");
        }else if (pid1==0){
           close(fd1[0]);
           write (fd1[1], msnhijo, strlen(msnhijo));
           close(fd1[1]); 

        }else{
         waitpid(pid1, &status, 0);
         close(fd2[0]);
         write (fd2[1], msnpadre, strlen(msnpadre));
         close(fd2[1]); 
        }

    }else{
        waitpid(pid, &status, 0);
            read(fd1[0], buffer, sizeof(buffer));
            printf("\n El mensaje que me ha enviado mi hijo es..%s \n", buffer);
            read(fd2[0], buffer1, sizeof(buffer1));
            printf("\n El mensaje que me ha enviado mi nieto es..%s \n", buffer1);
    }
    return 0;
}

