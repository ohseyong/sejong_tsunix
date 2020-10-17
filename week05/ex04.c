// 4장 1강 + 5장 1강 52분 예제

#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;

	printf("parent\ngetpid = %ld / getppid = %ld\n", getpid(), getppid());
	printf("getpgrp = %ld / getpgid = %ld\n", getpgrp(), getpgid(0));

	pid = fork();
	if (pid == 0)
	{
		printf("child before \ngetpid = %ld / getppid = %ld\n", getpid(), getppid());
		printf("getpgrp = %ld / getpgid = %ld\n", getpgrp(), getpgid(0));

		setpgid(getpid(), getpid());

		printf("child after\ngetpid = %ld / getppid = %ld\n", getpid(), getppid());
		printf("getpgrp = %ld / getpgid = %ld\n", getpgrp(), getpgid(0));
	}
	wait(0);
	return 0;
}