#include <pthread.h>
#include <stdio.h>

void* printx(void* unused){
	while(1)
		fputc('x',stderr);
	return NULL;
}

int main(){
	pthread_t thread_id;

	pthread_create(&thread_id,NULL,&printx,NULL);

	while(1)
		fputc('o',stderr);

	return 0;
}
