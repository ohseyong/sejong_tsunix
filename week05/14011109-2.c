#include <sys/types.h>
#include <ftw.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("PID : %d\n", getpid());
	printf("PGID : %d\n", getpgid(0));
	printf("SID : %d\n", getsid(0));
	return 0;
}
