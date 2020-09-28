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

int main(void)
{
	printf("%d\n", access("test1.c", F_OK));
	printf("%d\n", access("test2.c", F_OK|R_OK|W_OK));
	chmod("test2.c", 0400);
	printf("%d\n", access("test2.c", F_OK|R_OK|W_OK));

	return 0;
}
