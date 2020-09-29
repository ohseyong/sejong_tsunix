#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <ftw.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>

struct stud{
	int no, id;
	char name[20];
	double score;
};

void vi_m(char **res)
{
	struct stud buf;
	int fd;

	open(res[1], O_RDWR | O_CREAT, 0644);
	scanf("%d", &buf.no);
	getchar();
	while(buf.no > 0)
	{
		//나머지 정보 입력, scanf 사용 가능
		//순번 위치에 입력내용 저장
		scanf("%d", &buf.no);
		getchar();
	}
	lseek(fd, 0, SEEK_SET);
	write(1, res, 99);
}

int main(void)
{
	char in[50], *res[20]={0};
	int i;
	while (1)
	{
		printf("> ");
		gets(in);
		if (!strcmp(in, ""))
		   continue;
		i = 0;
	    res[i] = strtok(in, " ");
		while (res[i])
		{
			i++;
			res[i] = strtok(NULL, " ");
		}
		if (!strcmp(res[0], "vi"))
		{
			vi_m(res);
		}
		else
			exit(0);
	}
}
