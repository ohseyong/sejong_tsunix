#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int		num;
	int		i;
	int		fd;
	pid_t	pid;
	char	buf[3];

	num = atoi(argv[2]);
	fd = open(argv[1], O_RDONLY, 644);
	for (i = 0; i < num; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("process id : %d\n", getpid());
			if (read(fd, buf, 2) == 0)
				break;
			buf[2] = '\0';
			printf("%s\n", buf);
		}
	}
	for (i = 0; i < num; i++)
	{
		wait(0);
	}
	return (0);
}