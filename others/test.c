#include <stdio.h>
#include <unistd.h>
int		main(void)
{
	int		fd_stdout;
	int		pipe0[2];
	int		pipe1[2];
	int		pipe2[2];
	pipe(pipe0);
	pipe(pipe1);
	pipe(pipe2);
	while(1)
	{
		printf("%d, %d, %d, %d, %d, %d\n", pipe0[0], pipe0[1], pipe1[0], pipe1[1], pipe2[0], pipe2[1]);
	}
}