#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t pid;

	int child_status;

	pid = fork();

	if(pid == 0){
		printf("child process\n");
		sleep(2);
	}else{
		wait(&child_status);
		printf("parent process\n");
	}
	return 0;
}
