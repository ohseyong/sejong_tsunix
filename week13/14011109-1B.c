#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

int main(void)
{
	char f[2][3] = {"f1", "f2"};
	int i, in, fd[2];
	// “f1”과 “f2” open for (;;){
	for (;;)
	{
		// “f1”에서 정수 읽기 printf("%d\n", in);
		if (in == -1)
			exit(0);
		in = in + 8;
		// “f2”로 정수 보내기}
	}
	return 0;
}
