#include <stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("data", "r");
	if(fp == 0)
	{
		perror("open");
		return 0;
	}
	else
	{
		perror("open");
	}
	return 0;
}
