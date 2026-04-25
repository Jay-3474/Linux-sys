#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	if(fork() == 0)
	{
		printf("in child pid=%d\n", getpid());
		sleep(10);
		printf("after sleep\n");
		exit(1);
	}
	else
	{
		int r,s;
		printf("In parent ppid=%d\n", getppid());
		r=wait(&s);
		printf("in parent after wait r=%d, s=%d\n", r,s);
		while(1);
	}
	return 0;
}
