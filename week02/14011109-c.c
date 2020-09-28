#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int ch = 'Y';
	int fd;
	int i;

	fd = open("test1", O_RDWR | O_CREAT);
	for (i = 0; i < 5; i++)
	{
		write(fd, &ch, 1);
	}

	return (0);
}
