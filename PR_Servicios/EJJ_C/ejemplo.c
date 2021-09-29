
int main(){
    int integer;
    printf("\nINSERT A NUMBER: ");
    scanf("%d",&integer);
     for(int aux = 0;aux<=integer;aux++){
         if(aux%2==0){
             printf("%d \n",aux);
         }
    }
    return 0;
}

/**
 *  SCANF( "%d %d %d", &integer,&integer1,&integer2 )
 *
 **/