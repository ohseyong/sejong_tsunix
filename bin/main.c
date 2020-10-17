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

int main(void){
        char name[100], in[50], *res[20]={0};
        int i, status;
	pid_t pid;

        while (1){
		// current working directory의 이름을 출력

        	gets(in);
		if (in[0]=='\0')
			continue;

		i=0;
        	res[i]=strtok(in, " ");
		while (res[i]){
			res[++i]=strtok(NULL, " ");
		}

        	if (strcmp(res[0], "exit")==0){
        		exit(0);
		}
		// 실행파일을 실행하도록 필요한 코드 작성
	}

	return 0;
}
