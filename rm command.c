#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	if(unlink(argv[1])==0)
		printf("Success");
	else
		printf("Unsuccessful");
	return 0;
}
