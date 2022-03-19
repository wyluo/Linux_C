#include "../include/josephus.h"
#include <stdio.h>
#include <stdlib.h>

#if 0

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

void JosePhus_List_Kill(josephus_list **curr_node, int location)
{
	josephus_list* curr = *curr_node, * newnode = NULL;
	int tmp = 1;
	
	while (curr != curr->next)
	{
		while (tmp < location)
		{
			newnode = curr;
			curr = curr->next;
			tmp++;
		}
		printf("kill location is == %d\n", curr->data);
		newnode->next = curr->next;
		free(curr);

		curr = newnode->next;
		tmp = 1;
	}

	*curr_node = curr;

	printf("\n");
}
#endif
