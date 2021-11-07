
#include <signal.h>
#include <stdio.h>
#include <unistd.h>   
#include <errno.h>    
#include <sys/wait.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 


void manejador(int signum)
{
    switch (signum)
    {
    case SIGUSR1:
        printf("He recibido la señal ejecuto P1 \n");
        break;
    case SIGUSR2:
        printf("He recibido la señal ejecuto P2 \n");
        break;
    }
}

int main(int argc, char const *argv[])
{
    
    pid_t pid1,pid2,pid3,pid4,pid5,pid6;
    
    pid1=fork();
    if(pid1 == -1){
        printf("ERROR");
        exit(0);
    }else if (pid1 == 0){

        pid2=fork();
        if(pid2 == -1){
            printf("ERROR");
            exit(0);
        }else if (pid2==0){
            printf("Pulsa 1 para generar nuevo hijo, pulsa 2 para salir \n");
            scanf("%d", &var1);
             switch(var1){
                case 1:
                    do{
                        pid3=fork();
                        if(pid3==-1){
                        }else if (pid3==0){
                            printf("Soy el hijo generado\n");
                        }else{
                            waitpid(pid3, &status, 0); 
                            printf("Pulsa 1 para generar nuevo hijo, pulsa 2 para volver al menu\n");
                            scanf("%d", &var1);
                        }
                    }while(var1 == 1);
                break;
                case 2:
                
                break;
            }  
        }else{
            waitpid(pid2, &status, 0); 
        }      

        pid3=fork();
        if(pid3==-1){
            printf("ERROR");
            exit(0);
        }else if (pid3==0){
           waitpid(pid2, &status, 0);  
        }
        

    }else{
       waitpid(pid1, &status, 0);
       printf("Soy el padre, he generado un hijo, un nieto, ellos han creado otros procesos, yo me he esperado hasta el final, se han muerto y aquí sigo yo. Saludo");
    }

    return 0;
}
