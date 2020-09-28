#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int fd, a;
	
	//a
	fd = open("data2", O_RDWR | O_CREAT, 0644);
	write(fd, "XXXXXXXXXX", 10);
	//b
	a = lseek(fd, 0, SEEK_SET);
	write(fd, "Y", 1);
	//c
	a = lseek(fd, 0, SEEK_END);
	write(fd, "Y", 1);
	//d
	a = lseek(fd, 1, SEEK_SET);
	write(fd, "Z", 1);
	a = lseek(fd, 3, SEEK_SET);
	write(fd, "Z", 1);
	a = lseek(fd, 5, SEEK_SET);
	write(fd, "Z", 1);
	a = lseek(fd, 7, SEEK_SET);
	write(fd, "Z", 1);
	//e
	a = lseek(fd, 15, SEEK_SET);
	write(fd, "T", 1);
	//f
	a = lseek(fd, -2, SEEK_END);
	write(fd, "S", 1);
	//g
	a = lseek(fd, -2, SEEK_CUR);
	write(fd, "W", 1);

	return 0;
}
