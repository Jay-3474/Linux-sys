#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main()
{
	struct rlimit v;
	if(getrlimit(RLIMIT_STACK, &v) < 0)
	{
		perror("getlimit");
		return 0;
	}
	printf("pid = %d\n", getpid());
	printf("soft limit = %ld\n", v.rlim_cur);
	printf("Hardlimit = %ld\n", v.rlim_max);
	
	v.rlim_cur = 10000;
	setrlimit(RLIMIT_STACK, &v);
	getrlimit(RLIMIT_STACK, &v);
	
	printf("soft limit = %ld\n", v.rlim_cur);
	printf("Hardlimit = %ld\n", v.rlim_max);
	return 0;
}
