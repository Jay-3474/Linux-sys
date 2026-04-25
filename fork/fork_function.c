#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("hello\n");
	fork();
	printf("Hi\n");
	while(1);
	return 0;
}
