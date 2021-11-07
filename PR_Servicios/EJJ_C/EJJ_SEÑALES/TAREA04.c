
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
    pid_t p1,p2,p3,p4,p5,status;
    bool validador = true;
    int var1;

    p1=fork();
    if(p1 == -1){
        printf("ERROR");
        exit(0);
    }else if (p1 == 0){
        p2=fork();
         if(p2 == -1){
            printf("ERROR");
            exit(0);
        }else if (p2==0){
            do
            {
               printf("Pulsa 1 para generar nuevo hijo, pulsa 2 para salir \n");
               scanf("%d", &var1);
               switch (var1){          
                    case 1:
                    p3=fork();
                    if(p3==-1){
                        }else if (p3==0){
                            printf("Soy el hijo generado\n");
                            exit(EXIT_SUCCESS);
                        }else{
                           waitpid(p3, &status, 0);
                        }
                        break;
                    case 2:
                    validador = false;
                    break;
               }
            } while (validador==true); 
            kill(getppid(), SIGUSR2);
            exit(EXIT_SUCCESS);  
        }else{
            
            signal(SIGUSR2, manejador);
            pause();

            bool validador = true;
            do{
                printf("Pulsa 1 para generar nuevo nieto, pulsa 2 para salir \n");
                scanf("%d", &var1);
                switch (var1){
                    
                case 1:
                  
                    p4 = fork();
                    if (p4 == 0){

                        p5 = fork();
                        if (p5 == 0){
                            printf("Soy el hijo nieto con pid: %d,con padre:%d\n", getpid(), getppid());
                            exit(EXIT_SUCCESS);
                        }else{
                            // p2child code
                            printf("Soy el hijo generado con pid: %d,con padre:%d\n", getpid(), getppid());
                            waitpid(p5, &status, 0);
                            exit(EXIT_SUCCESS);
                        }
                    }else{
                        waitpid(p4, &status, 0);
                    }
                    break;

                case 2:
                    validador = false;
                    break;
                }
            }while (validador);
            //PID DEL RECEPTOR Y SEÑAL
            kill(getppid(), SIGUSR1);
            exit(EXIT_SUCCESS);
        }

    }else{
        signal(SIGUSR1, manejador);
        pause();
        printf("Soy el padre, he generado un hijo,\n un nieto,ellos han creado otros procesos, \nyo me he esperado hasta el final,\n se han muerto y aquí sigo yo. Saludo");
    }

    return 0;
}
