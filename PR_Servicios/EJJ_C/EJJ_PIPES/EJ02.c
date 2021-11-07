#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#define FILE_NAME "file.txt"


int main(int argc, char const *argv[])
{
    int fdh[2],file;
    pid_t pid, pid1, status;


    pipe(fdh);

    pid = fork();

    if (pid == -1){
        printf("ERROR");
    }
    else if (pid == 0){
        close(fdh[0]);
        dup2(fdh[1], STDOUT_FILENO); 
        close(fdh[1]);
        //system("ls -l");
        system("ls -l");
    }
    else{

        pid1 = fork();
        if (pid1 == -1){
            printf("ERROR");
        }
        else if (pid1 == 0){
            close(fdh[1]);
            file = open(FILE_NAME, O_WRONLY);
            dup2(fdh[0],STDIN_FILENO); 
            close(fdh[0]);
            dup2(file,STDOUT_FILENO);
            // dup2(FILE_NAME, STDOUT_FILENO);
            //system("wc");
            system("wc");
           
        }else{
            waitpid(pid, &status, 0);
           
        }
    }
}
