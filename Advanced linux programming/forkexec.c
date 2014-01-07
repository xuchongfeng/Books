#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
	pid_t pid;

	char *program = "ls";
	char *arg_list[]={
		"ls",
		"-l",
		"/",
		NULL
	};

	pid = fork();
	
	if(pid == 0){
		printf("child process\n");
		execvp(program,arg_list);
		fprintf(stderr,"error execvp\n");
		abort();
	}

	printf("parent process\n");

	return 0;
}
