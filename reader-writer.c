#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t wrt,mutex;
int b,count;

void *write()
{
	sem_wait(&wrt);
	b++;
	printf("Writer wrote %d.\nWriter is leaving\n",b);
	sem_post(&wrt);
}	

void *read(void *arg)
{
	int *i=(int*)arg;
	sem_wait(&mutex);
	count++;
	if(count==1)
		sem_wait(&wrt);
	sem_post(&mutex);

	printf("Reader %d read %d\nReader %d is leaving\n",*i,b,*i);

	sem_wait(&mutex);
	count--;
	if(count==0)
		sem_post(&wrt);
	sem_post(&mutex);
}

int main()
{
	pthread_t w,r1,r2;int flag=3;
	int rr1=1,rr2=2;
	sem_init(&wrt,0,1);
	sem_init(&mutex,0,1);
  while(flag--)
  {	pthread_create(&w,NULL,write,NULL);
	pthread_create(&r1,NULL,read,(void*)(&rr1));
	pthread_create(&r2,NULL,read,(void*)(&rr2));

	pthread_join(w,NULL);
	pthread_join(r1,NULL);
	pthread_join(r2,NULL);
  }	
	return 0;
}	

