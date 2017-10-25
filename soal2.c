
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[3];
char n1,n2;
int bom[17], bom2[17];
int pasang;
int f,g;
int main1=1, main2=0;
int tebak1=0, tebak2=0;
int poin1=0, poin2=0;

void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();


//THREEEAEADDD1111
    if(pthread_equal(id,tid[0]))
    {
       	while (main1=1)
       	{
          	printf("letakkan bomb pada lubang 1-16\n");
		for (int i=0;i<4;i++){
			printf ("masang?");
			scanf ("%d",&pasang);
			if (pasang = 1){
				printf ("pasang dimana");
				scanf ("%d", &f);
				bom[f]=1;
			}

		}
		main1=0;
		tebak2=1;
	}

        while (tebak1=1);
        {
                printf ("tebak bom1");
                for (int r=0;r<4;r++){
                        scanf ("%d", &teb2);
                        if (bom1[teb2]==1){
                                poin1+=1;
                        }
                        else if (bom1[teb2]==0){
                                poin2+=1;
                        }
                }
	tebak1=0;
	}

	exit(0);
    }



//THREADDDD2

    else if(pthread_equal(id,tid[1]))
    {
	while (main2=1)
	{
		printf ("letakkan bomb pada lubang 1-16\n");
		for (int i=0;i<4;i++){
			printf ("masang?");
			scanf ("%d, &pasang);
			if (pasang = 1){
				printf ("pasang dimana");
				scanf ("%d", &g);
				bom2[g]=1;
			}
		}
		main2=0;
	}



	while (tebak2=1);
	{
		printf ("tebak bom1");
		for (int r=0;r<4;r++){
			scanf ("%d", &teb2);
			if (bom1[teb2]==1){
				poin1+=1;
			}
			else if (bom1[teb2]==0){
				poin2+=1;
			}
		}
	tebak2=0;
	main2=1;
	}
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
