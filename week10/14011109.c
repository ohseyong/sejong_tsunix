#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

void do_child(void)
{
	int i, in, fd;
	// “data1” 파일을 쓰기 가능하게 open
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &in);
		// “data1” 파일에 정수를 하나 쓰기
		printf("child writes %d\n", in);
		// parent에게 SIGUSR1 signal 보내기
	}
	exit(0);
}
int main(void)
{
	int i, in, fd, status;
	pid_t pid;
	// SIGUSR1 signal 처리 설정
	if ((pid = fork()) == 0)
	{
		do_child();
	}
	// “data1” 파일을 읽기 가능하게 open
	for (i = 0; i < 5; i++)
	{
		// child의 signal을 받고, “data1” 파일에서 정수를 하나 읽기
		printf("parent reads %d\n", in);
	}
	wait(&status);
	exit(0);
}