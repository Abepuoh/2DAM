#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <errno.h>
#include <sys/wait.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    int var1,var2,var3,var4;
    bool boolean = true;
    int salir=0,tec=0;
    
    int mainMenu(){
        printf("**************************************************************\n");
        printf("*            BIENVENIDOS AL JUEGO DEL CALAMARS               *\n");
        printf("*              PULSE ENTER PARA CONTINUAR                    *\n");
        printf("*                                                            *\n");
        printf("*       1 PARA SUMAR                  2 PARA RESTAR          *\n");
        printf("*                   3 PARA MULTIPLICAR                       *\n");
        printf("**************************************************************\n");

        scanf("%d", &var1);
        do{
            return var1;
        }while (var1 >= 1 && var1 <=3);
        
    }
    mainMenu();
    switch (var1){
    case 1:
        printf("**************************************************************\n");
        printf("*                    HAS ELEGIDO SUMA                        *\n");
        printf("**************************************************************\n"); 
        srand(time(NULL));
        while(boolean==true){
            var2 = rand()% 101;
            var3 = rand()% 101;
            printf("Primer numero: %d\n Segundo numero: %d\n",var2,var3);
            scanf("%d", &var1);
            if( var1 == (var2+var3)){
                printf("ACERTASTE!\n");    
            }else{
                printf("ERROR\n");
                boolean = false;
            }
        }
        if(boolean == false){
            mainMenu();
            printf("Quieres salir pulsa -1");
            scanf("%d", &var1);
            if(var1 == -1){
                exit(0);
            }
        }   
        break;
    case 2:
        printf("**************************************************************\n");
        printf("*                    HAS ELEGIDO RESTA                       *\n");
        printf("**************************************************************\n"); 
        srand(time(NULL));
        while(boolean==true){
            var2 = rand()% 101;
            var3 = rand()% 101;
            printf("Primer numero: %d\n Segundo numero: %d\n",var2,var3);
            scanf("%d", &var1);
            if( var1 == (var2-var3)){
                printf("ACERTASTE!\n");    
            }else{
                printf("ERROR\n");
                boolean = false;
            }
        }
        if(boolean == false){
            mainMenu();
            printf("Quieres salir pulsa -1");
            scanf("%d", &var1);
            if(var1 == -1){
                exit(0);
            }
        }   
        break;
    case 3:
        printf("**************************************************************\n");
        printf("*                  HAS ELEGIDO MULTIPLICAR                   *\n");
        printf("**************************************************************\n");
        srand(time(NULL));
        while(boolean==true){
            var2 = rand()% 101;
            var3 = rand()% 101;
            printf("Primer numero: %d\n Segundo numero: %d\n",var2,var3);
            scanf("%d", &var1);
            if( var1 == (var2*var3)){
                printf("ACERTASTE!\n");    
            }else{
                printf("ERROR\n");
                boolean = false;
            }
        }
        if(boolean == false){
            mainMenu();
            printf("Quieres salir pulsa -1");
            scanf("%d", &var1);
            if(var1 == -1){
                exit(0);
            }
        }   
        break;    

    }
}