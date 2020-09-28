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
	char f[20], ch[512]={0};
	
	scanf("%s",f);
	readlink(f, ch, 512);
	lstat(f, &buf);
	printf("%o | %ld | %s\n",buf.st_mode&0777, buf.st_size, f);
	stat(f, &buf);
	printf("%o | %ld | %s\n",buf.st_mode&0777, buf.st_size, ch);

	return 0;
}
