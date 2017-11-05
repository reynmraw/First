#include <stdio.h>
#include <algorithm>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void* factorial(void* fac)
{
	int num = *((int *) fac);
	int a=num, i=num;
	while(--i){
		num=num*i;
	}
	printf("Hasil %d!: %d\n", a, num);
}




int main(int argc, char **argv){
	pthread_t t[argc-1];
	int anu=argc-1, k=0;
	int hehe[anu];
	for(int i=1; i<=anu; i++) {
		char lol[256];
		strcpy(lol,argv[i]);
		hehe[i-1]=atoi(lol);
	}
	sort(hehe, hehe+anu);
	while(--argc){
		pthread_create(&t[argc], NULL, &factorial, &hehe[k]);
		pthread_join(t[argc], NULL);
		k++;
	}
	return 0;
}
