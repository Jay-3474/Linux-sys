#include <stdlib.h>
#include <unistd.h>

int main()
{
	if(fork() == 0)
	{
		system("ls");
	}
	else
	{
		system("pwd");
	}
	return 0;
}
