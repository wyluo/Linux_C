#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main(int argc, char* argv[])
{
	queue *t_queue;
	Datatype arry[] = {7, 2, 9, 66};
	int i = 0;
	int tmp = 0;

	t_queue = Create();
	if(t_queue == NULL)
	{
		return 0;
		printf("%s\n", __FILE__);
	}

	printf("%s---%d\n", __FILE__, __LINE__);

	for(i = 0; i < sizeof(arry)/sizeof(*arry); i++)
	{
		Enter_queue(t_queue, &arry[i]);
	}

	Travel_queue(t_queue);

	printf("testing exit queue\n");

	for (i = 0; i < sizeof(arry) / sizeof(*arry); i++)
	{
		Exit_queue(t_queue, &tmp);
		printf("exit_queue data:%d\n\n", tmp);
		Travel_queue(t_queue);
	}

	Travel_queue(t_queue);

	Destory(t_queue);
	
	return 0;
}