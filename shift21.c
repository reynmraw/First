#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

void main()
{
        key_t key = 1234;
	int nambah, pilihan;
	
        int *stock[5]={10,10,10,10,10,10};

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        stock[5] = shmat(shmid, NULL, 0);

	printf("1.Lihat stock\n2.Tambah stock\n");
	scanf("%d",&pilihan);

	if(pilihan==1)
	{
		printf("MP4A1 %d",*stock[1]);
		printf("PM2-V1 %d",*stock[2]);
	}

	else if(pilihan==2)
	{
		scanf("%s %d",&senjata,&nambah);

        shmdt(stock[5]);
        shmctl(shmid, IPC_RMID, NULL);
}
