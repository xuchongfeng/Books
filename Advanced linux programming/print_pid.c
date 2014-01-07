#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t pid;
	printf("process id: %d\n",(int)getpid());
	printf("parent process id: %d\n",(int)getppid());
	while(1){}
	return 0;
}
