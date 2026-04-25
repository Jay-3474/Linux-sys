#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main()
{
	DIR *dp;
	struct dirent *p;
	dp = opendir(".");
	if(dp == 0)
	{
		perror("opendir");
		return 0;
	}
	while(p = readdir(dp))
	if(p->d_name[0] != '.')
	printf("%s", p->d_name);
	printf("\n");
	return 0;
}
