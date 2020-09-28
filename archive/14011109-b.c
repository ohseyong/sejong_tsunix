#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int data = 35;
	int fd;
	int i;

	fd = open("test2", O_RDWR | O_CREAT, 0640);
	for (i = 0; i < 10; i++)
	{
		write(fd, &data, 4);
	}

	return (0);
}
