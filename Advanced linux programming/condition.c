#include <pthread.h>
int pthread_flag;
pthread_cond_t thread_flag_cv;
pthread_mutex_t thread_mutex_t;

void *thread_func(void *p){
	while(1){
		pthread_mutex_lock(&thread_flag_mutex);
		while(!thread_flag){
			pthread_cond_wait(&pthread_flag_cv,&thread_flag_mutex);
			pthread_mutex_unlock(&thread_flag_mutex);
		}
	}
	return NULL;
}

void set_thread_flag(int flag_value){
	pthread_mutex_lock(&thread_mutex_t);
	pthread_flag = flag_value;
	pthread_cond_signal(&thread_flag_cv);
	pthread_mutex_unlock(&thread_mutex_t);
}