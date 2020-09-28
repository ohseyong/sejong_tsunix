#include <stdio.h>
#include <stdlib.h>

struct st{
	int id;
	char name[30];
};

int add_five(struct st *data)
{
	int i;

	for (i = 0; i < 5; i++)
		(data+i)->id += 5;
}

int main(void)
{
	int i;
	struct st *data;

	data = malloc(sizeof(struct st) + 1);
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &data[i].id);
		scanf("%s", &data[i].name);
	}
	add_five(data);
	for (i = 0; i < 5; i++)
	{
		printf("%-5d", data[i].id);
		printf("-%5s\n", data[i].name);
	}

	return (0);
}
