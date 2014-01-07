#include <stdio.h>
#include <pthread.h>

int main(){
	pthread_t tid;
	pthread_create(&tid,NULL,thread,NULL);
	pthread_join(tid,NULL);
	exit(0);
}

void *thread(void *vargp){
	fprintf(stderr,"hello\n");
	return NULL;
}