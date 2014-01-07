#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>

void* re(void* arg){
	return  arg;
}

int main(){
	pthread_t thread;
	int arg = 500;

	pthread_create(&thread,NULL,&re,arg);

	int ans;

	pthread_join(thread,(void *)&ans);

	printf("ans=%d\n",ans);

	return 1;
}

