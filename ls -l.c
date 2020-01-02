#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<grp.h>
#include<pwd.h>
#include<sys/stat.h>

static char arr[10]="rwxrwxrwx";
int main(int argc,char *argv[])
{
	struct stat statv;
	struct passwd *pw_p;
	struct group *gr_p;
	int st_mode;char mode[10];
	
	if(lstat(argv[1],&statv)==-1)
	{
		printf("Error.\n");
		exit(0);
	}

	st_mode=statv.st_mode;

	switch(st_mode & S_IFMT)
	{
		case S_IFDIR: printf("d");break;
		case S_IFREG: printf("-");break;
		case S_IFLNK: printf("l");break;
	}

	int i=0,j=1<<8;
	for(;i<9;i++,j>>=1)
	{
		if(st_mode & j)
			mode[i]=arr[i];
		else
			mode[i]='-';
	}
	mode[9]='\0';
	printf("%s",mode);

	printf("%d ",(int)statv.st_nlink);

	pw_p=getpwuid(statv.st_uid);
	gr_p=getgrgid(statv.st_gid);
	printf("%s ",pw_p->pw_name);
	printf("%s ",gr_p->gr_name);

	printf("%d ",(int)statv.st_size);
	printf("%s\n\n",argv[1]);
	return 0;
}	
	

