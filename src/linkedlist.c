#include "../include/linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

list* list_create()
{
	list* me;
	me = malloc(sizeof(*me));
	if (me == NULL)
		return NULL;
	me->next = NULL;
	return me;
}

int list_insert(list* me, int location, datatype* data)
{
	printf("%s %d\n", __FILE__, __LINE__);
	int tmp = 0;
	list* node = me,*newnode;

	if (location < 0)
		return -1;

	while ((tmp < location) && (node != NULL))
	//for(tmp = 0; tmp < location && node != NULL; tmp++)
	{
		printf("%s %d\n", __FILE__, __LINE__);
		node = node->next;
		printf("%p\n", node);
		tmp++;
		printf("%d\n", tmp);
	}
	
	if (node)
	{
		printf("%s %d\n", __FILE__, __LINE__);
		newnode = malloc(sizeof(*newnode));
		if (newnode == NULL)
			return -2;

		newnode->data = *data;
		newnode->next = NULL;
		newnode->next = node->next;
		node->next = newnode;
		return 0;
	}
	else
		return -3;
}

int list_order_insert(list* me, datatype* data)
{
	list* node = me, * newnode;

	while (node->next && node->next->data < *data)
		node = node->next;

	newnode = malloc(sizeof(*newnode));
	if (newnode == NULL)
	{
		return -1;
	}

	newnode->data = *data;
	newnode->next = NULL;
	newnode->next = node->next;
	node->next = newnode;

	return 0;
}

int list_isempty(list* me)
{
	if (me->next == NULL)
		return 0;
	return 1;
}

void list_display(list* me)
{
	//printf("%s %d\n", __FILE__, __LINE__);
	list* node = me->next;

	if (list_isempty(me) == 0)
		return;

	while (node != NULL)
	{
		//printf("%s %d\n", __FILE__, __LINE__);
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
	return;
}

void list_delete(list* me, datatype* data)
{
	list* node = me, *node1;

	while (node->next && node->next->data != *data)
		node = node->next;

	if (node->next == NULL)
		//return -1;
		return;
	else
	{
		node1 = node->next;
		node->next = node1->next;
		free(node1);
		node1 = NULL;
	}
	//return 0;
	return;
}

int list_delete_at(list* me, int location, datatype* data)
{
	int tmp = 0;
	list* node = me, *tmpnode;

	*data = -1;

	if (location < 0)
		return -1;

	while (tmp < location && node)
	{
		node = node->next;
		tmp++;
	}

	if (node)
	{
		tmpnode = node->next;
		node->next = tmpnode->next;
		*data = tmpnode->data;
		free(tmpnode);
		tmpnode = NULL;
		return 0;
	}
	else
		return -2;
}

void list_destory(list* me)
{
	list* node;
	list* nextnode;

	for (node = me->next; node != NULL; node = nextnode)
	{
		nextnode = node->next;
		free(node);
	}
	free(me);
	return;
}