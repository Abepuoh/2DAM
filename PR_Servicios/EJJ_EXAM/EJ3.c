#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h> 
#include<string.h>
int main(int argc, char const *argv[])
{
	pid_t mipid;
	int i = 0;
	mipid = fork();
	if(mipid>0){
		for (i = 0; i < 1; i++)
		{		
				printf("mipid es: %d y mi padre es: %d\n",mipid,getppid());
			mipid=fork();
			if(mipid>0){
				printf("mipid es: %d y mi padre es: %d\n",mipid,getppid());
				mipid= fork();
			}
		}

		
	}

	return 0;
}