#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define size 5

sem_t empty,full,mutex;
int arr[size];
int flag=2,count;

void *prod()
{
	int var;
	while(flag--)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		arr[count++]=rand()%20;
		printf("Producer has produced %d\n",arr[var]);
		sem_post(&mutex);
		sem_post(&full);
	}
}	

void *cons()
{
	int var;
	while(flag--)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		printf("Consumer has consumed %d\n",arr[--count]);
		sem_post(&mutex);
		sem_post(&empty);
	}
}

int main()
{
	pthread_t p[10],c[10];
	sem_init(&mutex,1,1);
	sem_init(&empty,1,size);
	sem_init(&full,1,0);
	int np,nc,i;
	printf("Enter the number of producer and consumers :");
	scanf("%d%d",&np,&nc);
	for(i=0;i<np;i++)
		pthread_create(&p[i],NULL,prod,NULL);
	for(i=0;i<nc;i++)
		pthread_create(&c[i],NULL,cons,NULL);

	for(i=0;i<np;i++)
                pthread_join(p[i],NULL);
        for(i=0;i<nc;i++)
                pthread_join(c[i],NULL);

	return 0;
}	
