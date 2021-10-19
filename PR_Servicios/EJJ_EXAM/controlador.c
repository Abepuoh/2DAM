#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
  int var1;
  pid_t pid;
  printf("Pulsa 1 para ejecutar en exclusivo, pulsa 2 para ejecutar en paralelo o 3 para salir\n");
  scanf("%d", &var1);
  switch(var1){
    case 1:
    if((pid=fork())==0){
    printf("En exclusivo\n");
    system("./juego");
    }else{
      pid = wait(NULL);
        while (pid != -1){
          pid=wait(NULL);
        } 
    }
    break;
    case 2:
    if((pid=fork())==0){
        system ("cmd.exe /c start cmd.exe /c wsl.exe ./juego");
    }else{
      pid = wait(NULL);
        while (pid != -1){
          pid=wait(NULL);
        } 
    }
    case 3: exit(0);
  }
 return 0; 
}