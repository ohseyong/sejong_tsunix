#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int ch = 'K';
	int fd;
	int i;

	fd = open("test3", O_EXCL | O_WRONLY, 0644);
	for (i = 0; i < 10; i++)
	{
		write(fd, &ch, 1);
	}

	return (0);
}
