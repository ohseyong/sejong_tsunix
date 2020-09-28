#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <dirent.h>
#include <string.h>

void	cd_m(char **res)
{
	chdir(res[1]);
}

void	ls_m(char **res)
{
	DIR				*dp;
	struct dirent	*d;

	dp = opendir(".");
	d = readdir(dp);
	while (d != NULL)
	{
		printf("%s\n", d->d_name);
		d = readdir(dp);
	}
	return (0);
}

int		main(void)
{ 
	char name[100], in[50], * res[20] = { 0 };
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
		else
			exit(0);
	}
}
