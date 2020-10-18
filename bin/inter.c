

#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i,j;
	char used[255];

	if (argc == 3)
	{
		i = 0;
		while (i < 255)
		{
			used[i++] = 0;
		}
		i = 1;
		if (i < 3)
		{
			int j = 0;
			while (argv[i][j])
			{
				if (used[(unsigned char)argv[i][j]] == 0)
				{
					used[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
