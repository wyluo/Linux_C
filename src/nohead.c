#include <stdio.h>
#include <stdlib.h>
#include "../include/nohead.h"

#if 0
struct Single_list* single_list_create(struct Single_list* list, struct Data_st* data)
{
	struct Single_list *list_node = list;
	if (list_node == NULL)
		return NULL;

	if (list_node)
	{
		list_node = list_node->next;
	}
}
#endif

/*头部插入*/
struct Single_list* single_list_insert(struct Single_list* list, struct Data_st* data)
{
	struct Single_list* newnode = NULL;

	newnode = malloc(sizeof(*newnode));
	if (newnode == NULL)
		return NULL;

	newnode->data = *data;
	newnode->next = NULL;
	newnode->next = list;
	list = newnode;

	return list;
}

/*二级指针用法*/
int singlelist_insert(struct Single_list** list, struct Data_st* data)
{
	struct Single_list* newnode = NULL;

	newnode = malloc(sizeof(*newnode));
	if (newnode == NULL)
		return -1;

	newnode->data = *data;
	newnode->next = *list;
	*list = newnode;

	return 0;
}

int singlelist_delete(struct Single_list** list)
{
	struct Single_list* cur = NULL;

	if (*list == NULL)
		return -1;

	cur = *list;
	*list = (*list)->next;
	free(cur);

	return 0;
}

void list_show(struct Single_list* list)
{
	struct Single_list* current = NULL;

	for (current = list; current != NULL; current = current->next)
		printf("%d  %s  %d  %d\n",
			current->data.id,
			current->data.name,
			current->data.value1,
			current->data.value2);
}

int single_list_find(struct Single_list* list, int id)
{
	struct Single_list* cur = NULL;

	for (cur = list; cur != NULL; cur = cur->next)
	{
		if (cur->data.id == id)
		{
			printf("%d  %s  %d  %d\n",
				cur->data.id,
				cur->data.name,
				cur->data.value1,
				cur->data.value2);
			return 0;
		}
	}
	return -1;
}

struct Data_st* ptr_find(struct Single_list* list, int id)
{
	struct Single_list* cur = NULL;

	for (cur = list; cur != NULL; cur = cur->next)
	{
		if (cur->data.id == id)
			return &cur->data;
	}

	return NULL;
}

void singlelist_destory(struct Single_list* list)
{
	struct Single_list* cur = NULL;

	if (list == NULL)
		return;

	for (cur = list; cur != NULL; cur = list)
	{
		list = cur->next;
		free(cur);
	}
}

/*Josephus problem*/
jose_list* Jose_list_creat(int num)
{

	return 0;
}

void Jose_list_show(jose_list* Jose_node)
{

}

