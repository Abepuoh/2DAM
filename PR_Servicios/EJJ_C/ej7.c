#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/** Pograma con carpeta excep que crea en la carpeta en el directorio home**/

int main(int argc, char const *argv[])
{
    int a = 0;
    pid_t myPid, p;
    printf("\nhola soy %d y mi padre es %d\n ", getpid(), getppid());
    myPid = fork(); //Trabajan de forma concurrente el padre y el hijo.
    if (myPid == 0)
    { // Trabaja el hijo
        printf("\n mi pid es %d y mi padre es %d ****\n ", getpid(), getppid());
    }
    else if (myPid > 0)
    { // Trabaja el padre
        p = wait(NULL);
        printf("\n mi pid es %d y mi padre es %d ****\n ", getpid(), getppid());
    }
    else if (myPid < 0)
    { // ERR0R
        printf("ERROR");
    }
}