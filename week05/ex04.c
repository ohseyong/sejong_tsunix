#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;

	printf("parent\ngetpid = %ld / getppid = %ld\n", getpid(), getppid());
	printf("getpid = %ld / getpgid = %ld\n", getpgrp(), getpgid(0));

	pid = fork();
	if (pid == 0)
	{
		printf("child before \ngetpid = %ld / getppid = %ld\n", getpid(), getppid());
		printf("getpid = %ld / getpgid = %ld\n", getpgrp(), getpgid(0));

		setpgid(getpid(), getpid());

		printf("child after %ld : %ld\n", getpid(), getppid());
		printf("child after %ld vs %ld\n", getpgrp(), getpgid(0));
	}
	wait(0);
	return 0;
}