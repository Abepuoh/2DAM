#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   //pid_t
#include <errno.h>    //tratamiento de errores
#include <sys/wait.h> //waits
#include <string.h>

int main(int argc, char const *argv[])
{
    pid_t pid, child_1, child_2, grandson_1; //variables para los pid de los hijos y los nietos
    int status; //variable entera para usar en waitpid()
    
    int ndir;//ndir guardará la cantidad de directorios nuevos que hay que crear
        
    printf("\n Soy el padre con pid %d\n",getpid());
    
    child_1 = fork(); //generamos el primer hijo

    char *ruta = getenv("HOME"); //ruta en un pricipio tiene la ruta del usuario que esté trabajando, por ejemplo /home/mcarmen
    char comando[100]; //esta variable cadena, servirá para generar aquí lo difentes comandos en los diferentes procesos
//    char *comando;
    char sdir[10]; //en esta variable se almacenarán los nombres de los directorios.
      
    sprintf(ruta,"%s/Desktop",ruta); //añadimos a la cadena de la ruta, el escritorio, ejemplo: /home/mcarmen/Desktop
    
      
    if(child_1==-1){
        printf ("Error al realizar la llamada fork \n");
        return -1;
    }else if (child_1 == 0){
        printf("Hijo 1 con pid: %d,con padre:%d, lanza un nuevo terminal con el contenido detallado del directorio actual\n",getpid(),getppid());
        system("gnome-terminal -- sh -c \"ls -l ./; bash\"");
        exit(0);
    }else{
        //estamos en el padre
        child_2 = fork(); //generamos el segundo hijo
        if(child_2==-1){
            printf ("Error al realizar la llamada fork \n");
            return -1;
        }else if (child_2 == 0){//estamos en hijo2
           
            grandson_1 = fork(); //generamos el nieto, hijo de child_2
            
            if(grandson_1==-1){
            	printf ("Error al realizar la llamada fork \n");
            	return -1;
            }else if (grandson_1 == 0){//estamos en nieto
                  printf("Nieto 1 con pid: %d,con padre:%d\n", getpid(), getppid());                
                  
                  printf("\nIntroduce número de directorios: ");
                  scanf("%d",&ndir);
                  
                  for (int i=0;i<ndir;i++){
                        printf("\n Introduce el nombre del directorio %d a crear:\n",i+1);
                        scanf("%s", sdir);                    
                        //comando= (char *) malloc(strlen(ruta)+strlen("mkdir "));
                        //montamos la cadena para pasarle al system en la variable comando(ej: mkdir /home/mcarmen/Desktop/ejemplo
                        sprintf(comando,"mkdir %s/%s",ruta,sdir); 
                        system(comando);  
                  }      
                  
                  exit(0);
            }else{//estamos en hijo 2
                waitpid(grandson_1,&status,0);//esperamos a N1
                
                printf("Hijo 2 con pid: %d,con padre:%d, crea directorio.txt con el contenido del Escritorio\n", getpid(), getppid());
                //montamos la cadena para el comando (ej:ls /home/mcarmen/Desktop >> /home/mcarmen/Desktop/directorio.txt)
                sprintf(comando,"ls %s >> %s/directorio.txt",ruta,ruta);   
                system(comando);
                exit(0);
            }
        }else{
           waitpid(child_2,&status,0);// esperamos a que acabe hijo dos
        }
       
     waitpid(child_1,&status,0); //esperamos a que acabe hijo uno
     printf("\nEl padre con pid = %d, muestra el contenido de directorio.txt\n",getpid());
     sprintf(comando,"gedit %s/directorio.txt",ruta); //generamos la cadena comando para el gedit
     system(comando);
    }
   return 0;
}
