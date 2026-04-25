#include <unistd.h>
#include <stdio.h>

int main()
{
	int i=0;
	if(fork() == 0)
	{
		printf("in child i=%d\n", i);
	}
	else
	{
		printf("in perent i=%d\n", i);
		i=20;
		printf("in perent after i=%d\n", i);
	}
}
