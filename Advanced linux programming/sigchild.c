#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
sig_atomic_t child_exit_status;

void clean_up_child_process(){
	int status;
	printf("process exit\n");
	wait(&status);
	child_exit_status = status;
}

int main(){
	pid_t pid;
	struct sigaction sigchild_action;
	memset(&sigchild_action,0,sizeof(sigchild_action));
	sigchild_action.sa_handler = &clean_up_child_process;
	sigaction(SIGCHLD,&sigchild_action,NULL);

	int i;
	for(i=0;i<3;i++)
		pid = fork();
	if(pid){
		printf("pid: %d\n",getpid());
		sleep(30);
	}
	exit(0);
}
