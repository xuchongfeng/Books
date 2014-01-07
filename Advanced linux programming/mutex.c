#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct job{
	int i;
	struct job *next;
}job;

job *list;

pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *p){
//	job *next_job = *((job *)p);
	
//	pthread_mutex_lock(&job_queue_mutex);
	job * next_job;
	if(NULL == list){
		next_job = NULL;
	}else{
		next_job = list;
		fprintf(stderr,"%d  ",next_job->i);
		list = list->next;
	}
//	pthread_mutex_unlock(&job_queue_mutex);
}


int main(){
	pthread_t pid[10];
	
	job *list_temp = NULL;
	job *cur = NULL;
	
	list = (job *)malloc(sizeof(job));
	assert(list);
	list->i = 0;
	list->next = NULL;
	
	cur = list, list_temp = list;
	int i;
	for(i=1;i<10;i++){
		list_temp = (job*)malloc(sizeof(job));
		assert(list_temp);
		list_temp->i = i;
		list_temp->next = NULL;
		cur->next = list_temp;
		cur = cur->next;
	}
	/* test
	while(list != NULL){
		fprintf(stderr,"%d\n",list->i);
		list = list->next;
	}
	*/
	for(i=0;i<10;i++){
		pthread_create(&pid[i],NULL,thread_func,NULL);
	}
	for(i=0;i<10;i++){
		pthread_join(pid[i],NULL);
	}
	return 0;
}