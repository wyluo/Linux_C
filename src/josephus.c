#include "../include/josephus.h"
#include <stdio.h>
#include <stdlib.h>

josephus_list* JosePhus_List_Create(int num)
{
	josephus_list* curr_node = NULL, *newnode = NULL, *node = NULL;

	int tmp_data = 1;
	
	curr_node = malloc(sizeof(*curr_node));
	if (curr_node == NULL)
		return NULL;

	curr_node->data = tmp_data;
	curr_node->next = curr_node;
	tmp_data++;

	node = curr_node;

	for (; tmp_data <= num; tmp_data++)
	{
		newnode = malloc(sizeof(*newnode));
		if (newnode == NULL)
			return NULL;

		newnode->data = tmp_data;
		newnode->next = curr_node;

		node->next = newnode;
		node = newnode;
	}
	return curr_node;
}

void JosePhus_List_Show(josephus_list* curr_node)
{
	josephus_list* newnode = NULL;

	for (newnode = curr_node; newnode->next != curr_node; newnode = newnode->next)
	{
		printf("%d ", newnode->data);
	}
	printf("%d\n", newnode->data);
}