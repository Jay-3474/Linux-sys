#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int a[5];
	srand(getpid());
	for(int i=0;i<5;i++)
	{
		a[i] = rand() % 100;
	}
	for(int i=0;i<5;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
