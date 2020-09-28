#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int data[10] = {0};
	int fd;
	int i;
	int n;

	fd = open("test2", O_RDONLY);
	if (fd == -1)
	{
		perror("error!");
		return (0);
	}
	n = read(fd, data, 5);
	data[n] = 0;
	printf("%s", data);

	return (0);
}
