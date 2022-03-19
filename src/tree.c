#include "../include/tree.h"
#include <stdio.h>
#include <stdlib.h>

/*
*插入原则：比上一个数小，放左边；反之，放右边
*/
int insert(struct score_node_st** root, struct score_st* data)
{
	struct score_node_st* newnode = NULL;
	if ((*root) == NULL)
	{
		newnode = malloc(sizeof(*newnode));
		if (newnode == NULL)
		{
			return - 1;
		}
		newnode->data = *data;
		newnode->left = NULL;
		newnode->right = NULL;//防野指针产生

		*root = newnode;
		return 0;
	}

	if (data->id <= (*root)->data.id)
		return insert(&(*root)->left, data);//递归
	return insert(&(*root)->right, data);
}

struct score_st *find(struct score_node_st *root, int id)
{
	if (root == NULL)
		return NULL;

	if (id == root->data.id)
		return &root->data;

	if (id < root->data.id)
		return find(root->left, id);
	else
		return find(root->right, id);
}

void print_s(struct score_st* d)
{
	//printf("%d  %s  %d  %d\n", d->id, d->name, d->data1, d->data2);
	printf("%d\n", d->id);
}

void draw_(struct score_node_st* root, int level)
{
	int i = 0;
	if (root == NULL)
		return ;
	draw_(root->right, level + 1);

	for (i = 0; i < level; i++)
		printf("    ");

	print_s(&root->data);

	draw_(root->left, level + 1);
}

void draw(struct score_node_st* root)
{
	draw_(root, 0);
}
