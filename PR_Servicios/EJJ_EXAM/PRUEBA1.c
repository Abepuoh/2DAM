#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid1, pid2,pid3;
    int status1, status2, nd;
    printf("Soy el padre\n");
    if ( (pid1=fork()) == 0 ){ /*EL PRIMER HIJO*/
        printf("Soy el primer hijo\n");
        execl("/bin/ls","ls","Cadena ruta ",(char *)NULL);
    }else{ /*ESTAMOS EN EL PADRE */
        if ( (pid2=fork()) == 0 ){ /* EL SEGUNDO HIJO*/
            printf("Soy el segundo hijo\n");
            pid3=fork(); /* EL NIETO*/
            if(pid3 == 0){
                printf("soy el nieto\n");
                printf("¿Cuantos direcctorios quieres crear?\n");
                scanf("%d", &nd);
                execl("/bin/mkadir","mkadir","EJEMPLO",(char *)NULL);
            }
        }else{
            pid2= wait(NULL);
            while (pid2 !=-1){
             pid2 = wait(NULL);   
            }
        }
        pid1=wait(NULL);
        while(pid1 != -1){
            pid1=wait(NULL);
        }
    }
}
