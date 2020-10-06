#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <dirent.h>
#include <string.h>

int flag;
int del_all(const char *name, const struct stat *s, int type)
{
	int cnt = 0;
	DIR *dp;
	struct dirent *d;
	// 이 부분에 필요한 코드 작성
	// 힌트 : 시스템 콜에 오류가 발생하면, ftw 함수 호출이 종료 됨
	// 시스템 콜이 –1을 return하지 않도록 할 것
	// 주의사항 : chdir 명령은 사용하지 말 것
	// chdir은 사용 할 필요가 없습니다. 사용하면 오류 발생 가능.
	return 0; // 이 코드는 삭제하면 안 됨
}
void rmall_m(char **res)
{
	int cnt = 0;
	DIR *dp;
	struct dirent *d;
	dp = opendir(res[1]);
	while ((d = readdir(dp)))
	{
		remove(d->d_name);
	}
}
int main(void)
{
	char name[100], in[50], *res[20] = {0};
	int i;
	while (1)
	{
		getcwd(name, 99);
		printf("%s> ", name);
		gets(in);
		i = 0;
		res[i] = strtok(in, " ");
		while (res[i])
		{
			i++;
			res[i] = strtok(NULL, " ");
		}
		if (!strcmp(res[0], "rmall"))
		{
			rmall_m(res);
		}
		else
			exit(0);
	}
}