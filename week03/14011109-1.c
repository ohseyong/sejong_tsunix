#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
	int i, fd, data1[10], data2[10];

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &data1[i]);
	}
	fd = open("data1", O_RDWR | O_CREAT , 0644);
	write(fd, data1, sizeof(int) * 10);
	lseek(fd, 0, SEEK_SET);
	read(fd, data2, sizeof(int) * 10);
	for (i = 0; i < 10; i++)
	{
		printf("%-5d", data1[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%-5d", data2[i]);
	}
	printf("\n");

	return (0);
}
