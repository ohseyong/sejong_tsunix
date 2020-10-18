#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <dirent.h>
#include <string.h>

void rm_m(char **res)
{
	char buf[501];
	int cnt;
	int rtn;
	struct stat s;
	struct dirent *d1, *d2;
	DIR *dp1, *dp2;
	dp1 = opendir(res[1]);
	chdir(res[1]); // 두 문장 변경하지 말 것
				   // 여기에 필요한 코드 작성
				   // 여기서는 chdir 명령 사용 절대 금지
	while ((d1 = readdir(dp1)))
	{
		unlink(d1->d_name);
		rtn = rmdir(d1->d_name);
		if (rtn == -1)
		{
			cnt = 0;
			dp2 = opendir(d1->d_name);
			while ((d2 = readdir(dp2)))
			{
				cnt++;
			}
			printf("%s has %d files or directories", d1->d_name, cnt);
		}
		stat(d1->d_name, &s);
	}

	chdir("..");   // 세 문장 변경하지 말 것
	if (rmdir(res[1]) == -1)
		printf("cannot remove %s\n", res[1]);
}
int main(void)
{ // main 함수 변경하지 말 것
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
		if (!strcmp(res[0], "rm"))
		{
			rm_m(res);
		}
		else
			exit(0);
	}
}