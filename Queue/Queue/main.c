#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "global.h"

#if 0
/*
 *顺序循环队列的实现
 */
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
#endif

/*
 *链式队列的实现
 */
int main(int argc, char *argv[])
{
	QUEUE *qu = NULL;
	//struct score_node_st t_score;
	SCORE t_score;
	int i = 0, ret = 0;

	qu = Link_Storage_Create(sizeof(SCORE));//(sizeof(struct score_node_st));
	if(qu == NULL)
	{
		exit(1);
	}

	for(i = 0; i < 6; i++)
	{
		t_score.id = i;
		snprintf(t_score.name, NAMESIZE, "name%d", i);
		t_score.data1 = rand() % 100;

		//printf("%d---%s\n", __LINE__, __FILE__);

		if(Link_Storage_Enter_queue(qu, &t_score) != 0)
		{
			break;//enter queue fail
		}
	}

	while(1)
	{
		ret = Link_Storage_Exit_queue(qu, &t_score);
		if(ret != 0)
		{
			break;
		}
		print_s(&t_score);
	}

	Link_Storage_Destory_queue(qu);

	return 0;
}