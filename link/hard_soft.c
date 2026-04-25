#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
	struct stat v, v1;
	if(argc != 3)
	{
		printf("Usage: ./hard_soft file1 file2\n");
		return 0;
	}
	
	if(stat(argv[1], &v) < 0)
	{
		perror("stat");
		return 0;
	}
	
	if(stat(argv[2], &v1) < 0)
	{
		perror("stat");
		return 0;
	}
	
	if(v.st_ino == v1.st_ino)
	{
		lstat(argv[1], &v);
		lstat(argv[2], &v1);
		if(v.st_ino == v1.st_ino)
		{
			printf("Hard link....\n");
		}
		else
		{
			printf("soft link...\n");
		}
	}
	else
	{
		printf("no link...\n");
	}
	
	return 0;
}
