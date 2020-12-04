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

union semun
{
	int val;
	struct semid_ds *buf;
	ushort *array;
};
int main(void)
{
	ushort buf[2] = /* semaphore의 초기값 */;
	int i, j, pid, semid;
	key_t key;
	union semun arg;
	struct sembuf p_buf;
	key = ftok("key", 5);
	semid = // semaphore 생성 if (semid==-1){
}
}
}
else
{
}
// semaphore get
// semaphore 값 초기화
pid = getpid();
for (i = 0; i < 3; i++)
{
	// 동기화를 위한 semaphore 연산
	for (j = 0; j < 3; j++)
	{
		printf("%d ... %ld\n", i, pid);
		sleep(1);
	}
// 동기화를 위한 semaphore 연산 return 0;