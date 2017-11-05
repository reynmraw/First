#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int p1[16]={},p2[16]={};
int sc1=0,sc2=0;
char player1[100],player2[100];

void hello(){
	printf("Selamat datang di Game Aidil cari MINE\n");
}

int cekmine(){
	int i,cona=0,conb=0;
	for(i=0;i<16;i++) cona+=p1[i];
	for(i=0;i<16;i++) conb+=p2[i];
	if(cona==16&&conb==16) return 1; else return 0;
}

void view(){
	system("clear");
	time_t now;
	now=time(NULL);
	printf("Score pada permainan ini %s\n", ctime(&now));
	printf("Score %s %d\n",player1,sc1);
	printf("Score %s %d\n",player2,sc2);
}

void * turn1(){
	view();
	printf("Giliran %s\n",player1);
	printf("Masukkan nomor lubang yang ingin dipasang ranjau\n");
	printf("ketik ""-1"" untuk mengakhiri pemasangan MINE\n\n\n");
	printf("Masukkan Nomor Lubang : \n");
	int n,con=0;
	while(con<4&&n!=-1){
		scanf("%d",&n);
		if(p1[n-1]==0){
			con++;
			p1[n-1]=1;
		}
		else{
			printf("Mine sudah terpasang masukkan ke lubang lain\n");
			continue;
		}
	}

	system("clear");
	view();
	printf("Saatnya %s menebak MINE\n", player2);
	con=4;
	while(con--){
		scanf("%d",&n);
		if(p1[n-1]==1) sc1++;
		else sc2++;
	}
}

void * turn2(){
	view();
	printf("\n\nGiliran %s\n",player2);
	printf("Masukkan nomor lubang yang ingin dipasang ranjau\n");
	printf("ketik ""-1"" untuk mengakhiri pemasangan MINE\n\n\n");
	printf("Masukkan Nomor Lubang : \n");
	int n,con=0;
	while(con<4&&n!=-1){
		scanf("%d",&n);
		if(p2[n-1]==0){
			con++;
			p2[n-1]=1;
		}
		else{
			printf("Mine sudah terpasang masukkan ke lubang lain\n");
			continue;
		}
	}

	system("clear");
	view();
	printf("Saatnya %s menebak MINE\n", player1);
	con=4;
	while(con--){
		scanf("%d",&n);
		if(p2[n-1]==1) sc2++;
		else sc1++;
	}
}

int main(){
	pthread_t tid[2];
	hello();
	printf("Masukkan Nickname Player 1 : "); scanf("%s",player1);
	printf("Masukkan Nickname Player 2 : "); scanf("%s",player2);

	while(1){
		system("clear");
		view();
		if(sc1==10 || sc2==10 || cekmine()){
		system("clear");
		printf("\n\n\nGame Over :(\n\n\n\n");
		break;
		}
		if(pthread_create(&(tid[0]),NULL,&turn1,NULL)!=0){
			exit(EXIT_FAILURE);
		}
		pthread_join(tid[0],NULL);
		if(pthread_create(&(tid[1]),NULL,&turn2,NULL)!=0){
			exit(EXIT_FAILURE);
		}
		pthread_join(tid[1],NULL);
	}
}

