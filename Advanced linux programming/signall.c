#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig){
	pid_t pid;
	while((pid = waitpid(-1,NULL,0)) > 0){
		//fprintf(stderr,"waitpid error\n");
		fprintf(stderr,"Handler reaped from child %d\n",pid);
	}
	sleep(2);
	return;
}

int main(){
	if(signal(SIGCHLD,handler) == SIG_ERR){
		fprintf(stderr,"signal error");
		exit(0);
	}
	
	int i;
	for(i=0;i<4;i++){
		if(fork() == 0){
			fprintf(stderr,"child process:%d\n",getpid());
			sleep(1);
			exit(0);
		}
	}
	
	char buf[100];
	if(read(STDIN_FILENO,buf,sizeof(buf)) < 0){
		fprintf(stderr,"read error\n");
	}
	
	fprintf(stderr,"Parent processing input\n");
	while(1);
	exit(0);
}