
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[3];
int ikan=1,kepiting=1;
int statlohan=100;
int statkep=100;
int pilihan;

void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();

    if(pthread_equal(id,tid[0]))
    {
       	for(statlohan;statlohan>0;)
       	{
          	printf("nyawa lohan %i\n",statlohan);
           	fflush(stdout);
           	sleep(10);
		statlohan-=15;
	}

	printf("\nRIP Lohan");
	ikan=0;
	exit(0);
    }

    else if(pthread_equal(id,tid[1]))
    {
	for(statkep;statkep>0;)
	{
		printf("			nyawa kepiting %i\n",statkep);
		fflush(stdout);
		sleep(20);
		statkep-=10;
	}

	printf("\nRIP Kepiting");
	kepiting=0;
	exit(0);
    }

    if(pthread_equal(id,tid[2]))
    {
	while(statlohan<=100 && statkep<=100)
	{
		scanf("%d",&pilihan);
		if(pilihan==1) 
		{
			statlohan+=10;
			printf ("nyawa lohan menjadi %i\n",statlohan);
		}
		else if(pilihan==2) 
		{
			statkep+=10;
			printf ("			nyawa kepiting menjadi %i\n", statkep);
		}
	}
	printf("Kekenyangan gan\n");
	exit(0);
    }
return NULL;
}

int main(void)
{
	int i=0;
	int err;
	printf ("\nOPSI 	:\n 1. Kasih makan lohan\n 2. Kasih makan kepiting\n\n\n");
	while(i<3)
    	{
        	err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);
        	i++;
    	}
    	pthread_join(tid[0],NULL);
    	pthread_join(tid[1],NULL);
   	pthread_join(tid[2],NULL);
    	return 0;
}
