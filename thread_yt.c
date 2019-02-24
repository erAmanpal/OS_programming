#include<pthread.h>
#include<stdio.h>
int x=0;
void* fun1()
{
	x++;
	printf("output from fun1  %d\n",x);
}

void* fun2()
{
	x--;
	printf("output from fun2  %d\n",x);
}

int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	
	pthread_join(t1,NULL);	
	pthread_join(t2,NULL);
}
