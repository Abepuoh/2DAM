#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fdh[2],fdh1[2];
    pid_t pid,pid1,pid2,status;


    pipe(fdh);  //pipe de LS y GREP
    pipe(fdh1); // Pipe de GREP y WC 

    pid = fork();

    if (pid == -1){
        printf("ERROR");
    }
    else if (pid == 0){               /* Abrimos el primer hijo */
        close(fdh[0]);                /* Cerramos extremo de lectura */
        dup2(fdh[1], STDOUT_FILENO);  /* Escribimos el fichero de Salida */
        close(fdh[1]);                      
        execlp("/bin/ls", "ls", "-l", NULL);    /* Ejecutamos el comando de ls */
    }
    else{
        close(fdh[1]); 

        pid1 = fork();              
        if (pid1 == -1){
            printf("ERROR");
        } 
        else if (pid1 == 0){            /* Abrimos el segundo hijo */
            dup2(fdh[0],STDIN_FILENO);      
            close(fdh[0]);
            close(fdh1[0]);
            dup2(fdh1[1], STDOUT_FILENO); 
            close(fdh1[1]);
            execlp("/bin/grep","grep", "e",NULL);
           
        }else{
            
            close(fdh1[1]);

            pid2=fork();

            if (pid2 == -1){
             printf("ERROR");
            }
            else if (pid2 == 0){                /* Abrimos el tercer  hijo */
                dup2(fdh1[0],STDIN_FILENO); 
                close(fdh1[0]);			
	            execlp("/usr/bin/wc","wc", "-l",NULL); 
            }else{
            waitpid(pid, &status, 0);
            waitpid(pid1, &status, 0);
            waitpid(pid2, &status, 0);
            }
        }
    }
}

