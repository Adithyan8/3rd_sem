#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd1,fd2;char buf[20];
	fd1=open(argv[1],O_RDONLY);
	if(fd1==-1)
	{
		printf("Error");
		exit(0);
	}
	
	fd2=open(argv[2],O_WRONLY);
	int n;
	while((n=read(fd1,buf,20))!=0)
	{
		write(fd2,buf,n);
		printf("HI\n");
	}	
	printf("Copying Successful.");

	close(fd1);
	close(fd2);
	return 0;
}	
