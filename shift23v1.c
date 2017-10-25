#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[3];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread
int ikan=1,kepiting=1;
int iter=100;
int jir=100;//inisialisasi jumlah looping
int pilihan;
void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    
    if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {
	
	
       		 system("clear");
       		 for(iter;iter>0;)
       	        {
           	 	printf("\n %i",iter);
           	 	fflush(stdout);
           	 	sleep(1);
		 	iter-=15;
	        }
	
	printf("\nIkannya mati oi");
	ikan=0;
	exit(0);
    }
    else if(pthread_equal(id,tid[1]))
    {
       
		system("clear");
		for(jir;jir>0;)
		{
			printf("\n %i",jir);
			fflush(stdout);
			sleep(2);
			jir-=10;
		}
	
	printf("\nKepitingnya mati Dil");
	kepiting=0;
	exit(0);
    }
 
    else if(pthread_equal(id,tid[2]))
    {


	while(1)
	{
		printf("\n1.Kasih makan lohan\n2.Kasih makan kepiting\n");
		scanf("%d",&pilihan);
		if(pilihan==1) iter+=10;
		else if(pilihan==2) jir+=10;
		if (jir>100 || iter>100)
			{
				printf("kepenuhan kolamnya");
				exit(0);
			}
	}
    }
return NULL;
}
int main(void)
{
    int i=0;
    int err;
    while(i<3)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);//membuat thread
        i++;
    }
    pthread_join(tid[2],NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
