#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
	int chk;

	chk = access("data1", F_OK);
	if (chk == 0)
		printf("파일 존재함\n");
	else
		printf("파일이 존재하지 않음\n");
	chk = access("data1", F_OK|R_OK|W_OK);
	if (chk == 0)
		printf("읽기쓰기 가능\n");
	else
		printf("읽기쓰기 불가능\n");

	return (0);
}
