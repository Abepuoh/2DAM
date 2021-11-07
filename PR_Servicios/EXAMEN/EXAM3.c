/*
Desarrolla un programa que cree un solo proceso hijo y un solo proceso nieto (hijo del proceso hijo).
El proceso nieto: pedirá el nombre de un directorio, y lo creará en el directorio HOME de cualquier usuario.
El proceso hijo: mostrará el contenido del HOME (debe mostrar el directorio que creó el hijo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
  int c;
  int status;
  pid_t pid,pid2;
  
  printf("Padre con ID %d comienza:\n",getpid());

  pid=fork();

  if (pid==0)
  {
	  printf("Hijo %d con padre %d\n", getpid(), getppid());
	  //execl("/bin/ls","ls","-l",(char *)NULL);
	  pid2=fork();
	  
	  char *ruta = getenv("HOME");
	  
	  if (pid2==0)
	  {
		  printf("Nieto %d con padre %d\n", getpid(), getppid());
		  
		  char dir[10];
		  printf("Introduce nombre del nuevo directorio: ");
		  scanf("%s",dir);
		  ruta=strcat(ruta,"/");
		  ruta=strcat(ruta,dir);
		  execl("/bin/mkdir","mkdir", ruta,(char *) NULL);
		  exit(0);
	  }
	  pid = wait(NULL);
	  while (pid != -1)
  	  {
		pid=wait(NULL);
  	  }
	   	 
	 execl("/bin/ls","ls","-l",ruta,(char *)NULL);
	 exit(0); 
  }
  
  printf(" \nPadre esperando a los hijos \n");
  pid = wait(NULL);
  while (pid != -1)
  {
  	pid=wait(NULL);
  
  printf("\nTodos los hijos han terminado han terminado\n");
  
 return 0;
}
