#include <unistd.h>
#include <stdio.h>
#include <string.h>

void cat_m(char **res)
{
	char buf[512];
	int fd, n;

	fd = open()

}

void cp_m(char **res)
{
	char buf[512];
	int fd1, fd2, n;

}

int main(void)
{
	char in[50], *res[20] = {0};
	int i;

	while (1)
	{
		printf("> ");
		gets(in);
		i = 0;
		res[i] = strtok(in, " ");
		while (res[i]) 
		{
			i++;
			res[i] = strtok(NULL, " ");
		}
	if (!strcmp(res[0], "cat"))
	{
		cat_m(res);
	}
	else if (!strcmp(res[0], "cp"))
	{
	
	}
	else 
		exit (0);
	}
}
