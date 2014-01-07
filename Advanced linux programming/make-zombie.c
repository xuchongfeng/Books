#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
int main(){
	pid_t pid;

	pid = fork();

	if(pid == 0){
		printf("child process: %d\n",getpid());
		exit(0);
	}else{
		sleep(60);
	}
	return 0;
}
