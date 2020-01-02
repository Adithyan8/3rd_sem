#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
	int fd1;struct flock fvar;
	if(argc!=2)
	{
		printf("Inappropriate number of arguments.\n");exit(0);
	}
	
	fd1=open(argv[1],O_RDWR);
	if(fd1 ==-1)
	{
		printf("Error.\n");exit(0);
	}
	fvar.l_type=F_WRLCK;
	fvar.l_whence=SEEK_SET;
	fvar.l_start=0;
	fvar.l_len=100;

	if((fcntl(fd1,F_SETLK,&fvar))==0)
	{
		printf("Lock Set\n");
		//sleep(1);
	}
	else
	{
		fcntl(fd1,F_GETLK,&fvar);
		printf("Lock already set by process %d.\n",fvar.l_pid);
		return -1;
	}

	printf("Press any key to release the lock");
	getchar();
	fvar.l_type=F_UNLCK;
	fvar.l_whence=SEEK_SET;
	fvar.l_start=0;
	fvar.l_len=100;

	if(fcntl(fd1,F_UNLCK,&fvar)==-1)
	{
		printf("Error");	
		exit(0);
	}
	printf("File has been unlocked.\n");
	close(fd1);return 0;
}	
