#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t pid;
	printf("parent process id: %d\n",(int)getppid());
	printf("process id: %d\n",(int)getpid());

	pid = fork();

	if(pid == 0){
		printf("this is the child\n");
		printf("child process id: %d\n",(int)getpid());
		printf("parent process id: %d\n",(int)getppid());
	}else{
		/*一般都是先执行父进程再执行子进程，那么子进程
		 * 就会被init进程领养，其父进程号为1，这里让父
		 * 进程睡眠1秒，让子进程先执行*/
		sleep(1);
		printf("this is the parent\n");
	}

	return 0;
}
