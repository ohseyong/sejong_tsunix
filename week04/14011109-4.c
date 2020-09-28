#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	struct stat buf;

	stat("data3", &buf);
	printf("%o\n", (unsigned int)buf.st_mode&0777);
	printf("%d\n", (int)buf.st_nlink);
	printf("%d\n", (int)buf.st_size);

	return 0;
}
