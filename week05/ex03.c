//UNIX프로그래밍 5주차 5장 강의 49분 예제

#include <sys/types.h>
#include <ftw.h>
#include <stdio.h>

int main()
{
	printf("%ld : %ld\n", getpid(), getppid());;
	printf("%d vs. %ld\n", getpgrp(), getpgid(0));
	return 0;
}
