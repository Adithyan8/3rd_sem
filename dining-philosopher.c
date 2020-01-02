#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>
#include<pthread.h>

enum{think,hungry,eat}state[5];
sem_t mutex,ph[5];
int arr[5]={0,1,2,3,4};

void test(int i)
{
	if(state[i]==hungry && state[(i+1)%5]!=eat && state[(i+4)%5]!=eat)
	{
		state[i]=eat;
		printf("Philosopher %d is eating with sticks %d and %d\n",i,(i+4)%5,i);
		sem_post(&ph[i]);
	}
}	

void pickup(int i)
{
	sem_wait(&mutex);
	state[i]=hungry;
	printf("Philosopher %d is hungry.\n",i);
	test(i);
	sem_post(&mutex);
	if(state[i]!=eat)
		sem_wait(&ph[i]);
}

void putdown(int i)

{
	sem_wait(&mutex);
	state[i]=think;
	printf("Philosopher %d is thinking.\n",i);
	test((i+1)%5);test((i+4)%5);
	sem_post(&mutex);
}	

void *philosopher(void *arg)
{
	while(1)
	{
		int *i=(int*)arg;
		pickup(*i);
		sleep(1);
		putdown(*i);
	}
}

int main()
{
	pthread_t phil[5];int i;
	sem_init(&mutex,0,1);
	for(i=0;i<5;i++)
	{
		state[i]=think;
		printf("Philosopher %d is thinking\n",i);
		sem_init(&ph[i],0,0);
	}
	for(i=0;i<5;i++)
		pthread_create(&phil[i],NULL,philosopher,(void*)(&arr[i]));
	
	for(i=0;i<5;i++)
	{
		pthread_join(phil[i],NULL);
	}	
	return 0;
}
