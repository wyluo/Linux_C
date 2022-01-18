#include <stdio.h>
#include <stdlib.h>
#include "../include/polynomial.h"

struct Polynomial_list* polynomial_creat(int arry[][2], int length)
{
	struct Polynomial_list* node1;
	struct Polynomial_list* newnode1;
	struct Polynomial_list* cur;
	int tmp;

	node1 = malloc(sizeof(*node1));
	if (node1 == NULL)
		return NULL;
	node1->next = NULL;

	cur = node1;

	for (tmp = 0; tmp < length; tmp++)
	{
		newnode1 = malloc(sizeof(*newnode1));
		if (newnode1 == NULL)
			return NULL;

		newnode1->coef = arry[tmp][0];
		newnode1->exp = arry[tmp][1];
		newnode1->next = NULL;

		cur->next = newnode1;
		cur = newnode1;
	}

	return node1;
}

void polynomial_show(struct Polynomial_list* node1)
{
	struct Polynomial_list* cur = NULL;

	for (cur = node1->next; cur != NULL; cur = cur->next)
	{
		printf("(%d %d)", cur->coef, cur->exp);
	}
	printf("\n");
}

void polynomial_union(polynomial_list* node_ptr1, polynomial_list* node_ptr2)
{
	polynomial_list* node1 = NULL;
	polynomial_list* node2 = NULL;
	polynomial_list* node3 = NULL;

	node1 = node_ptr1->next;
	node2 = node_ptr2->next;
	node3 = node_ptr1;

	printf("%d,%s\n", __LINE__, __FILE__);

	while (node1 && node2)
	{
		if (node1->exp < node2->exp)
		{
			node3->next = node1;
			node3 = node1;
			node1 = node1->next;
		}
		else if (node1->exp > node2->exp)
		{
			node3->next = node2;
			node3 = node2;
			node2 = node2->next;
		}
		else
		{
			node1->coef += node2->coef;
			if (node1->coef)
			{
				node3->next = node1;
				node3 = node1;
			}
			node1 = node1->next;
			node2 = node2->next;
		}
	}
	if (node1 == NULL)
	{
		node3->next = node2;
	}
	else
	{
		node3->next = node1;
	}
}