#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   //pid_t
#include <errno.h>    //tratamiento de errores
#include <sys/wait.h> //waits
#include <string.h>

int main(int argc, char const *argv[]){

    pid_t pidH1,pidH2,pidG1,pidG2,status,pid;
    printf("Soy el padre con pid: %d y con padre: %d \n", getpid(), getppid()); 
    pidH1 = fork(); 
    if(pidH1 == -1 ){
        printf("ERROR");
        exit(0);
    }else if(pidH1 == 0){ //PRIMER HIJO
       
        pidG1=fork(); //PRIMER NIETO

        if(pidG1 == -1){
            printf("ERROR");
            exit(0);
        }else if (pidG1 == 0){
            printf("NIETO1: %d,CON PADRE:%d\n", getpid(), getppid());  
            system("mkdir ~/NIETO1");
        }else{
            waitpid(pidG1, &status, 0);
            printf("HIJO1: %d,CON PADRE:%d\n", getpid(), getppid());  
            system("ls -l ~/");
        }
        
    }else{
        waitpid(pidH1, &status, 0);
        
        pidH2 = fork();
        if(pidH2 == -1){
            printf("ERROR");
            exit(0);
        }else if (pidH2 == 0){
            pidG2=fork(); //PRIMER NIETO
            if(pidG2==0){
                //System("mkdir ~/NIETO2");
                printf("NIETO2: %d,CON PADRE:%d\n", getpid(), getppid()); 
                system("mkdir ~/NIETO2"); 
            }else{
                waitpid(pidG2, &status, 0);
                printf("HIJO2: %d,CON PADRE:%d\n", getpid(), getppid());  
                system("ls -l  ~/");
            }
        }else{
        exit(0);
        }
        exit(0);
    }
    return (0);
}


