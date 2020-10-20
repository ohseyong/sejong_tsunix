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


void justforsig(int);

void do_child(int i)
{
	int j;
	static struct sigaction act;

	act.sa_handler = justforsig;
	sigaction(SIGUSR1, &act, NULL);

	printf("Child no.%d is created.\n", i);
	pause();

	for (j = 0; j < 3; j++)
	{
		printf("pid: %d\n", getpid());
	}

	exit(i);
}

int main(void)
{
	int i, cid, status;
	pid_t pid[3];
	for (i = 0; i < 3; i++)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			do_child(i);
		}
	}

	for (i = 0; i < 3; i++)
	{
		sleep(1);
		kill(pid[i], SIGUSR1);
	}

	for (i = 0; i < 3; i++)
	{
		cid = wait(&status);
		printf("child id=%d, exit status=%d\n", cid, WEXITSTATUS(status));
	}
	exit(0);
}

void justforsig(int signo)
{
}