/*
Ejemplo de señales: función manejador que controla 3 señales distintas.
Enunciado:
Realice un programa en C que, ante las siguientes señales, responda de la siguiente manera:

Al recibir una señal SIGUSR1 muestre el mensaje “Soy el proceso (pid que corresponda) y he recibido la señal SIGUSR1”
Al recibir una señal SIGUSR2 muestre el mensaje “Soy el proceso (pid que corresponda) y he recibido la señal SIGUSR2”
Al recibir una señal SIGTERM muestre el mensaje “Soy el proceso (pid que corresponda) y he terminado mi ejecución” y termine su ejecución.
Para probar lo anterior el programa generará dos hijos:
  - hijo 1 espera la señal SIGUSR1
  - hijo 2 espera la señal SIGUSR2, después genera un bucle infinito mostrando un mesaje diciendo su pid
  - padre: tras 3 segundos de ejecución envía señal SIGUSR1 a hijo1, 
  	    después de otros 3 segundos envía señal SIGUSR2 a hijo2
  	    después de otros 3 segundos manda señal SIGTERM a hijo2
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//manejador para el padre

void manejador(int signum){
	switch (signum){
		case SIGUSR1:
			printf("\nsoy %d y He recibido la señal SIGUSR1\n",getpid());
			break;
		case SIGUSR2:
			printf("\nsoy %d y He recibido la señal SIGUSR2\n",getpid());
			break;
		case SIGTERM:
			printf("\nSoy %d y He terminado mi ejecucion\n",getpid());
			exit(0);
	}
}


int main()
{

	pid_t pidh1,pidh2;
	pid_t miPid=getpid();
	
	pidh1=fork(); //creamos el hijo1
    
    if(pidh1==-1){
        printf("ERROR");
    }else if (pidh1==0) {
    	signal(SIGUSR1, manejador);
		sleep(2);
		pause(); //esperamos recibir señal
    }else{

        pidh2=fork(); //creamos hijo2
        if(pidh2==-1){
            printf("ERROR");
        }else if (pidh2==0)// hijo2 está a la escucha de la señal SIGUSR2
        {
			signal(SIGUSR2, manejador);
			//hijo2 está a la escucha de la señal SIGTERM
			signal(SIGTERM, manejador);
			sleep(2);
			pause();//esperamos recibir señal
			while(1){
			    printf("soy %d\n",getpid());
			    sleep(1);
			}
            
        }
            //MANDO SEÑAL A HIJO1
			sleep(3);
			kill(pidh1,SIGUSR1);
					
			//MANDO SEÑAL A HIJO2
			sleep(3);
			kill(pidh2,SIGUSR2);
					
			//MANDO SEÑAL A HIJO2 PARA QUE TERMINE
			sleep(3);
			kill(pidh2,SIGTERM);        
    }	
	return 0;
}