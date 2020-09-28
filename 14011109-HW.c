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

void	cat_m(char **res)
{
	char buf[512];
	int fd, n;

	fd = open(res[1], O_RDWR);
	while(0 < (n = read(fd, buf, 512)))
		write(1, buf, n);
}

void	cd_m(char **res)
{
	chdir(res[1]);
}

void	mkdir_m(char **res)
{
	mkdir(res[1], 0644);
}

void	ls_m(char **res)
{
	DIR				*dp;
	struct dirent	*d;
	struct stat		*buf;

	dp = opendir(".");
	d = readdir(dp);
	while (d != NULL)
	{
		stat(d->d_name, buf);
		if (S_ISREG(buf->st_mode))
			printf("F ");
		else if (S_ISDIR(buf->st_mode))
			printf("D ");

		printf("%o ", buf->st_mode&0777);
		printf("%d ", buf->st_nlink);
		printf("%d ", buf->st_uid);
		printf("%d ", buf->st_gid);
		printf("%lld %s ", buf->st_size, ctime(&buf->st_mtime));
		printf("%s\n", d->d_name);
		d = readdir(dp);
	}
}

void	cp_m(char **res)
{
	char buf[512];
	int fd1, fd2, n;

	fd1 = open(res[1], O_RDONLY);
	if (fd1 == -1)
	{
		perror("복사할 파일이 없습니다");
	}
	fd2 = open(res[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
	while(0 < (n = read(fd1, buf, 512)))
		write(fd2, buf, n);
}

int		main(void)
{ 
	char name[100], in[50], *res[20] = { 0 };
	int i;

	while (1) 
	{
		getcwd(name, 99);
		printf("%s> ",name);
		gets(in);
		i = 0;
		res[i] = strtok(in, " ");
		while (res[i]) 
		{
			i++;
			res[i] = strtok(NULL, " ");
		}
		if (!strcmp(res[0], "cd")) 
		{
			cd_m(res);
		}
		else if (!strcmp(res[0], "ls")) 
		{
			ls_m(res);
		}
		else if (!strcmp(res[0], "cp")) 
		{
			cp_m(res);
		}
		else if (!strcmp(res[0], "mkdir")) 
		{
			mkdir_m(res);
		}
		else if (!strcmp(res[0], "cat")) 
		{
			cat_m(res);
		}
		else
			exit(0);
	}
}
