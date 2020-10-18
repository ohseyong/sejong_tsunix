#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<ftw.h>
#include<time.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/sem.h>
#include<sys/shm.h>

void	do_ls_m(void)
{
	char *argv[] = {0};
	execv("./ls_m", argv);
	exit (0);
}

void	do_cat_m(char *argv[])
{
	execv("./cat_m", argv);
	exit (0);
}

void	do_mkdir_m(char *argv[])
{
	execv("./mkdir_m", argv);
	exit (0);
}

void	do_cp_m(char *argv[])
{
	execv("./cp_m", argv);
	exit (0);
}

void	do_cd_m(char *argv[])
{
	printf("yo\n");
	//execv("./cd_m", argv);
	exec("./cd_m", argv);
	exit (0);
}

int	main(void)
{
	char	name[100];
	char	in[500];
	char	*res[20]={0};
	int	i;
	int	status;
	pid_t	pid;
	while (1)
	{
		getcwd(name, 99);
		printf("%s> ", name);
		gets(in);
		if (in[0] == '\0')
			continue;
		i = 0;
		res[i] = strtok(in, " ");
		while (res[i])
		{
			res[++i] = strtok(NULL, " ");
		}
		if (strcmp(res[0], "exit") == 0)
		{
			exit(0);
		}
		else if (strcmp(res[0], "ls_m") == 0)
		{
			pid = fork();
			if (pid == 0)
				do_ls_m();
		}
		else if (strcmp(res[0], "cat_m") == 0)
		{
			char *argv[] = {"./cat_m", res[1]};
			pid = fork();
			if (pid == 0)
				do_cat_m(argv);
		}
		else if (strcmp(res[0], "mkdir_m") == 0)
		{
			char *argv[] = {"./mkdir_m", res[1]};
			pid = fork();
			if (pid == 0)
				do_mkdir_m(argv);
		}
		else if (strcmp(res[0], "cp_m") == 0)
		{
			char *argv[] = {"./cp_m", res[1], res[2]};
			pid = fork();
			if (pid == 0)
				do_cp_m(argv);
		}
		else if (strcmp(res[0], "cd_m") == 0)
		{
			char *argv[] = {"./cd_m", res[1]};
			pid = fork();
			if (pid == 0)
				do_cd_m(argv);
		}
		wait (0);
	}
	return (0);
}
