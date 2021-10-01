/* Realiza un programa en c que cree un proceso ( trendremos un proceso padre y un hijo)
el programa definira una varibale local con valor 6, el proceso padre incrementa el valor de variable en 1 y 
 el prcoeso hijo decrementara en 1 la salida tiene que ser :

SALIDA: 
valor incial  = 6 
varible hija = 5
variable padre = 7 */

#include <sys/types.h> //Para tipo pid_t 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{  
    pid_t Ppid;
    int variable = 6;
    pid_t ChildPid;
          printf("\nHOLA QUE ASE HOY EL VALOR INISIAL %d\n",variable);
    ChildPid = fork();
    if (ChildPid == 0){
         printf("\nHola JUANCARLO %d\n",--variable);
    }else if(ChildPid > 0){
        printf("\nHola JUANCARLO %d",++variable);
        Ppid = wait(NULL);
    }
}

