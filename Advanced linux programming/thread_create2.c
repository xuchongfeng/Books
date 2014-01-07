#include <pthread.h>
#include <stdio.h>

typedef struct p{
	char c;
	int count;
}parms;
void* func(void* parameters){
	parms *f = (parms*)parameters;
	int i;
	for(i=0;i<f->count;i++)
		fputc(f->c,stderr);
	return NULL;
}

int main(){
	pthread_t thread1;
	pthread_t thread2;

	parms p1;
	parms p2;

	p1.c = 't';
	p1.count = 10;

	p2.c = 'f';
	p2.count = 5;

	pthread_create(&thread1,NULL,&func,&p1);
	pthread_create(&thread2,NULL,&func,&p2);

	sleep(20);
	return 0;
}
