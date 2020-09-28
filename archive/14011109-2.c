#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char confirm;
	int i, fd1, fd2, buf = 1;
	char fname1[256];
	char fname2[256];
	char buff[4096];

	scanf("%s", fname1);
	scanf("%s", fname2);
	fd1 = open(fname1, O_RDONLY);
	if (fd1 == -1)
	{
		perror("복사할 파일이 없습니다");
		return (0);
	}
	fd2 = open(fname2, O_RDONLY);
	if (fd2 != -1)
	{
		printf("파일이 이미 존재합니다. 덮어씌우시겠습니까? (Y/N)");
		getchar();
		scanf("%c", &confirm);
		if (confirm == 'Y' || confirm == 'y')
			printf("파일을 덮어씌웁니다.\n");
		else	
			return (0);
	}
	fd2 = open(fname2, O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (buf)
	{
		buf = read(fd1, buff, 4095);
		write(fd2, buff, buf);
	}
	printf("복사를 완료하였습니다.\n");
	return (0);
}
