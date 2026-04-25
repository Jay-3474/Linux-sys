#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char** argv)
{
	struct stat v;
	if(argc != 2)
	{
		printf("Usage: ./file_stat fname\n");
		return 0;
	}
	if(stat(argv[1], &v) < 0)
	{
		perror("stat");
		return 0;
	}
	printf("f_size = %ld\n", v.st_size);
	printf("i_nod = %ld\n", v.st_ino);
	printf("permission = %o\n", v.st_mode);
	
	if(S_ISREG(v.st_mode))
	{
		printf("regular...\n");
	}
	else if (S_ISDIR(v.st_mode))
	{
		printf("Dir...\n");
	}
	
	printf("st_atime = %lu\n", v.st_atime);
	printf("st_mtime = %lu\n", v.st_mtime);
	printf("st_ctime = %lu\n", v.st_ctime);
	
	return 0;
}
