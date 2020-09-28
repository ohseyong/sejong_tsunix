#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int i, fd, k, k1, data1[10], data2[10];
	
	fd = open("data3", O_RDWR|O_CREAT, 0600);
	for (i=0; i<10; i++)
	{
		scanf("%d", &data1[i]);
	}
	lseek(fd, 0, SEEK_SET);
	write(fd, &data1[0], 4);

	lseek(fd, 4, SEEK_CUR);
	write(fd, &data1[1], 4);

	lseek(fd, 4, SEEK_CUR);
	write(fd, &data1[2], 4);

	lseek(fd, 4, SEEK_CUR);
	write(fd, &data1[3], 4);

	lseek(fd, 4, SEEK_CUR);
	write(fd, &data1[4], 4);

	lseek(fd, 4, SEEK_SET);
	write(fd, &data1[5], 4);

	lseek(fd, 4, SEEK_CUR);
	write(fd, &data1[6], 4);

	lseek(fd, 4, SEEK_CUR);
	write(fd, &data1[7], 4);

	lseek(fd, 4, SEEK_CUR);
	write(fd, &data1[8], 4);

	lseek(fd, 4, SEEK_CUR);
	write(fd, &data1[9], 4);

	lseek(fd, 0, SEEK_SET);
	read(fd, data2, 40);

	for(i=0; i<10; i++)
	{
		printf("%-5d", data1[i]);
	}
	printf("\n");

	for(i=0; i<10; i++)
	{
		printf("%-5d", data2[i]);
	}
	printf("\n");

	return 0;
}
