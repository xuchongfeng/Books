#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define size 100

int account[size];

typedef struct transfer{
	int from;
	int to;
	int money;
}transfer;

void *transaction(void *p){
	transfer data = *((transfer *)p);
	int old_cancel_state;
	if(account[data.from] < data.money){
		return 0;
	}
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&old_cancel_state);
	account[data.from] -= data.money;
	account[data.to] += data.money;
	pthread_setcancelstate(old_cancel_state,NULL);
	
	return 1;
}

int main(){
	pthread_t pid[10];
	int i;
	for(i=0;i<10;i++){
		transfer *temp = (transfer *)malloc(sizeof(transfer));
		temp->from = i;
		temp->to = i+1;
		temp->money = -rand()%100;
		if(temp == NULL){
			fprintf(stderr,"malloc error\n");
			exit(0);
		}
		pthread_create(&pid[i],NULL,transaction,temp);
	}
	for(i=0;i<10;i++){
		pthread_join(pid[i],NULL);
		fprintf(stderr,"%d\n",account[i]);
	}
	return 0;
}