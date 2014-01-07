#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

unsigned int snooze(unsigned int seconds){
	unsigned int r = sleep(seconds);
	fprintf(stderr,"Slept for %d of %d secs.\n",seconds-r,seconds);
	return r;
}

void handler(int sig){
	return;
}

int main(int argc,char **argv){
	if(argc != 2){
		fprintf(stderr,"argument fault, do not froget the time\n");
		exit(0);
	}
	signal(SIGINT,handler);
	snooze(atoi(argv[1]));
	exit(0);
}