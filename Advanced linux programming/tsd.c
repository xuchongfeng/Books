#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define thread_num 5

static pthread_key_t thread_log_key;

void write_to_thread_log(const char *message){
	FILE *thread_log = (FILE *)pthread_getspecific(thread_log_key);
	fprintf(thread_log,"%s\n",message);
}

void close_thread_log(void *thread_log){
	fclose ( (FILE *)thread_log);
}

void *thread_func(void *args){
	char thread_file_name[20];
	FILE *thread_log;
	
	sprintf(thread_file_name,"thread%d.log",(int)pthread_self());
	thread_log = fopen(thread_file_name,"w");
	pthread_setspecific(thread_log_key,thread_log);
	
	write_to_thread_log("thread starting.");
	
	return NULL;
}


int main(){
	pthread_t pid[thread_num];
	
	pthread_key_create(&thread_log_key,close_thread_log);
	int i;
	for(i=0;i<thread_num;i++){
		pthread_create(&pid[i],NULL,thread_func,NULL);
	}
	for(i=0;i<thread_num;i++){
		pthread_join(pid[i],NULL);
	}
	return 0;
}