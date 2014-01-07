#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void alarm_handler(int sig){
	fprintf(stderr,"alarm\n");
	exit(0);
}

int main(int argc,char **argv,char **envp){
	//syscall:getpid && getppid
	fprintf(stderr,"pid: %d\n",getpid());
	fprintf(stderr,"ppid: %d\n",getppid());
	//syscall:fork,return child pid in parent process , 0 in child process.
	pid_t pid;
	pid = fork();
	if(pid == 0){
		//sleep(5);
		fprintf(stderr,"this is child process: %d\n",getpid());
		exit(0);
	}
	//syscall:waitpid
	waitpid(pid,NULL,0);
	fprintf(stderr,"this is parent process\n");
	//syscall:execve
	//execve("/Users/busyfisher/Desktop/syscall.c.out",NULL,NULL);
	/*while(*envp != NULL){
		fprintf(stderr,"%s\n",*envp);
		envp++;
	}*/
	//syscall:getpgrp
	fprintf(stderr,"groupid: %d\n",getpgrp());
	//syscall.setpgid,
	//setpgid(pid_t pid,pid_t pgid)
	//set pid group as pgid
	setpgid(0,0);
	fprintf(stderr,"groupid: %d\n",getpgrp());
	//syscall:kill
	//kill(getpid(),SIGKILL);
	//fprintf(stderr,"the process had been killed\n");
	
	//syscall:signal,alarm
	if(signal(SIGALRM,alarm_handler) == SIG_ERR){
		fprintf(stderr,"signal error\n");
	}
	alarm(1);
	//waiting....
	pause();
	exit(0);
}