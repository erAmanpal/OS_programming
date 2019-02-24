#include<pthread.h>
#include<stdio.h>
int x=0;  // critical section
void* fun1()
{
	x++;
	printf("fun1=%d\t",x);
}

void* fun2()
{
	x--;
	printf("fun1=%d\t",x);
}

int main()
{
	int i;
	pthread_t t1,t2;
	for(i=1;i<1000;i++)
	{
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	
	pthread_join(t1,NULL);	
	pthread_join(t2,NULL);
	}

}
