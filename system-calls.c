#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int pid=fork();
	if(pid<0)
	{
		printf("error\n");
		exit(0);
	}
	else if(pid==0)
	{
		printf("Child process - pid : %d\n",getpid());
		execl("./add","add.c",NULL);
	}
	else
	{
		wait(NULL);
		printf("Parent process - pid %d\n",getpid());
		execl("./sub","sub.c",NULL);
	}
	return 0;
}
