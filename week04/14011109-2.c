#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
	int i;
	char f1[256], f2[256];
	
	scanf("%s", f1);
	scanf("%s", f2);
	
	symlink(f1, f2);

	return (0);
}
