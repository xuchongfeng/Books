#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <assert.h>

typedef struct job{
	int i;
	struct job *next;
}job;

job * job_queue;

pthread_mutex_t  job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t job_queue_count;

void* dojob(void *p){
	while(1){
		job *next_job;
		sem_wait(&job_queue_count);
		
		pthread_mutex_lock(&job_queue_mutex);
		fprintf(stderr,"do job: %d\n",job_queue->i);
		next_job = job_queue;
		job_queue = job_queue->next;
		pthread_mutex_unlock(&job_queue_mutex);
	}
	return NULL;
}

void* enqueue(void *p){
	while(1){
	job *new_job = (job *)malloc(sizeof(new_job));
	assert(new_job);
	
	pthread_mutex_lock(&job_queue_mutex);
	new_job->i = rand()%100;
	new_job->next = job_queue;
	job_queue = new_job;
	fprintf(stderr,"add new job: %d\n",new_job->i);
	sem_post(&job_queue_count);
	pthread_mutex_lock(&job_queue_mutex);
}	
}

int main(){
	pthread_t pid1,pid2;
	job_queue = NULL;
	sem_init(&job_queue_count,0,0);
	pthread_create(&pid1,NULL,dojob,NULL);
	pthread_create(&pid2,NULL,enqueue,NULL);
	pthread_join(pid1,NULL);
	pthread_join(pid2,NULL);
	return 0;
}