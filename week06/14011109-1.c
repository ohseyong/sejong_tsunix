#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <dirent.h>
#include <string.h>

void do_child(void)
{
	printf("%d\n", getpid());
	printf("%d\n", getpgid(getpid()));
	printf("%d\n", getsid(getpid()));	
	// process id, group id, session id 출력
	exit(0); // 이 부분의 코드는 변경 금지
}
int main(int argc, char *argv[])
{
	int num, i;
	pid_t pid;
	// main 함수의 인자를 정수로 변환

	num = atoi(argv[1]);

	for (i = 0; i < num; i++)
	{
		pid = fork();
		// child process 생성
		if (pid == 0)
		{
			do_child();
		}
	}
	for (i = 0; i < num; i++)
	{ // 이 부분의 코드는 변경 금지
		wait(0);
	}
	return 0;
}