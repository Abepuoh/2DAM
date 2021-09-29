#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/** Pograma con carpeta excep que crea en la carpeta en el directorio home**/

int main(int argc, char const *argv[])
{
    int a = 0;
    pid_t myPid;
    printf("\nhola soy el padre %d y mi padre es %d\n ",getpid(),getppid());
    myPid = fork();
    if (myPid == 0){
        printf("\n mi pid es %d y mi padres es %d ****\n ",getpid(),getppid());
    }else if(myPid>0){
       printf("\n mi pid es %d y mi padres es %d ****\n ",getpid(),getppid());
    }else if(myPid <0){
        printf("ERROR");
    }  
    printf("\nhola soy el hijo%d\n",getpid());

}