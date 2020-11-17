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

void backup(char **res)
{
	static char f1[512], f2[512] = "TEMP/";
	char buf[512];
	int fd1, fd2, n;
	if (res != NULL)
	{
		mkdir("TEMP", 0700);
		strcpy(f1, res[1]);
		strcat(f2, res[1]);
	}
	fd1 = open(f1, O_RDONLY);
	if (fd1 == -1)
		return;
	fd2 = open(f2, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	while ((n = read(fd1, buf, 512)) > 0)
		write(fd2, buf, n);
}

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

void	do_cd_m(char *path)
{
	chdir(path);
}

void	do_rm_m(char *argv[])
{
	execv("./rm_m", argv);
	exit (0);
}

void	do_res_m(char *res[])
{	
	execv(res[0], res);
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
	int		space_count;

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
			if ((pid = fork()) == 0)
				do_ls_m();
			else if (pid >0)
				wait(&status);
		}
		
		else if (strcmp(res[0], "cat_m") == 0)
		{
			char *argv[] = {"./cat_m", res[1]};
			if ((pid = fork()) == 0)
				do_cat_m(argv);
			else if (pid >0)
				wait(&status);
		}
		
		else if (strcmp(res[0], "mkdir_m") == 0)
		{
			char *argv[] = {"./mkdir_m", res[1]};
			if ((pid = fork()) == 0)
				do_mkdir_m(argv);
			else if (pid >0)
				wait(&status);
		}
		
		else if (strcmp(res[0], "cp_m") == 0)
		{
			char *argv[] = {"./cp_m", res[1], res[2]};
			if ((pid = fork()) == 0)
				do_cp_m(argv);
			else if (pid >0)
				wait(&status);
		}
		else if (strcmp(res[0], "backup") == 0)
		{
			printf("..... backup .....\n");
			sleep(10);
			printf("..... backup .....\n");
			sleep(10);
			printf("..... backup .....\n");
			sleep(10);	
		}
		else if (strcmp(res[0], "cd_m") == 0)
		{
			do_cd_m(res[1]);
		}
		
		else if (strcmp(res[0], "rm_m") == 0)
		{
			char *argv[] = {"./rm_m", res[1]};
			if ((pid = fork()) == 0)
				do_rm_m(argv);
			else if (pid > 0 )
				wait(&status);
		}
		else if (strlen(res[0]) > 0)
		{
			if ((pid = fork()) == 0)
				do_res_m(res);
			else if (pid > 0 )
				wait(&status);
		}
	}
	return (0);
}
