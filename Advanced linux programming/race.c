#include <stdio.h>
#include <sys/malloc.h>
#include <pthread.h>
int index = 0;
void* func(void* arg){
	int t=*(int *)arg;
	printf("pid : %d\n",(int)getpid());
	if(t>0){
		index++;
		printf("exec func %d\n",index);
		t--;
		t--;
		sleep(3);
		t++;
		t++;
	}
	return NULL;
}
int main(){
	pthread_t *thread;
	thread = (pthread_t *)malloc(10*sizeof(pthread_t));
	if(thread == NULL){
		fprintf(stderr,"thread malloc error");
		return 1;
	}
	int t=1;
	int i;
	for(i=0;i<10;i++)
		pthread_create(&thread[i],NULL,&func,&t);
	//for(i=0;i<10;i++)
	//	pthread_join(thread[i],NULL);
	return 0;
}
