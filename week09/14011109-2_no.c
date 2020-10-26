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


void justforsig(int signo)
{
}

void do_child(int i, int *cid)
{
	int		j, status;
	pid_t	pid;
	// SIGUSR1 signal 처리가 가능 하도록 설정
	///밑에 맞는지 봐주세열~~~~
	static struct sigaction act;

	act.sa_handler=justforsig;
	sigaction(SIGINT, &act, NULL);
	/////
	
	// 자신의 출력 순서가 될 때 까지 대기
	//
	//wait(&status); 나 pause(); 를 쓰는건가요??? 잘 모르겠습니다 ㅠㅠ

	pid = getpid();
	for (j = 0; j < 5; j++)
	{
		printf("child %d ... \n", pid);
		sleep(1);
	}
	// 출력 완료 후 다음 출력 순서의 child에게 출력 시작을 알림
	/// 밑에도 맞는지 봐주세열 ~~~~
	kill(pid, SIGUSR1);
	///
	exit(0);
}

int main(void)
{
	int i, status;
	pid_t pid[5];
	
	for (i = 0; i < 5; i++)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			do_child(i, pid);
		}
	}

	for (i = 0; i < 3; i++)
	{
		wait(&status);
	}

	exit(0);
}
