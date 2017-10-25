#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[2];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread
int ikan=1,kepiting=1;
int length=100;
int length1=100;//inisialisasi jumlah looping
int pilihan;
void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter,jir;
    if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {
	if(ikan==1)
	{
       		 system("clear");
       		 for(iter=length;iter>0;)
       	        {
           	 	printf("\n %i",iter);
           	 	fflush(stdout);
           	 	sleep(1);
		 	iter-=15;
	        }
	}
	printf("\nIkannya mati oi");
	ikan=0;
	
    }
    else if(pthread_equal(id,tid[1]))
    {
        if(kepiting==1)
	{
		system("clear");
		for(jir=length1;jir>0;)
		{
			printf("\n %i",jir);
			fflush(stdout);
			sleep(2);
			jir-=10;
		}
	printf("\nKepitingnya mati Dil");
	kepiting=0;
	
    }
 
    else if(pthread_equal(id,tid[2]))
    {

	while(1)
	{
		if(ikan==1 || kepiting==1)
		{

			printf("1.Kasih makan lohan\n2.Kasih makan kepiting\n");
			scanf("%d",&pilihan);
			if(pilihan==1) iter+=10;
			else if(pilihan==2) jir+=10;
		}
		
	}
    }
}
int main(void)
{
    int i=0;
    int err;
    while(i<3)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
    return 0;
}
