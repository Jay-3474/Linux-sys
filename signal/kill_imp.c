#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		printf("Usage: ./kill_imp signum pid\n");
		return 0;
	}
	if(kill(atoi(argv[2]), atoi(argv[1])) < 0)
	{
		perror("kill");
		return 0;
	}
	perror("kill");
	return 0;
}
