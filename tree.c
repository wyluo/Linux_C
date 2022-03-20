#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct score_node_st* tree = NULL;

/*
*插入原则：比上一个数小，放左边；反之，放右边
*/
int Insert(struct score_node_st** root, struct score_st* data)
{
	struct score_node_st* newnode = NULL;
	if (*root == NULL)
	{
		newnode = malloc(sizeof(*newnode));
		if (newnode == NULL)
		{
			return -1;
		}

		newnode->data = *data;
		newnode->left = NULL;
		newnode->right = NULL;//防野指针产生

		*root = newnode;
		return 0;
	}

	if (data->id <= (*root)->data.id)
		return Insert(&(*root)->left, data);
	else
		return Insert(&(*root)->right, data);
}

struct score_st* Find(struct score_node_st* root, int id)
{
	if (root == NULL)
		return NULL;

	if (id == root->data.id)
		return &root->data;

	if (id < root->data.id)
		return Find(root->left, id);
	else
		return Find(root->right, id);
}

void print_s(struct score_st* data)
{
	printf("%d\n", data->id);
}

/*
*描绘二叉树---往左倒
*/
static void draw_(struct score_node_st* root, int level)
{
	int i = 0;
	if (root == NULL)
		return;
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

/*
 *平衡二叉树---条件：左子树与右子树差值为1
 */
static int get_num(struct score_node_st* root)
{
	if (root == NULL)
		return 0;

	return get_num((root->left)) + 1 + get_num((root->right));
}

static struct score_node_st* find_min(struct score_node_st* root)
{
	if (root->left == NULL)
		return root;

	return find_min(root->left);
}

static void turn_left(struct score_node_st** root)
{
	struct score_node_st* current = *root;

	*root = current->right;
	current->right = NULL;
	find_min(*root)->left = current;
}

static struct score_node_st* find_max(struct score_node_st* root)
{
	if (root->right == NULL)
		return root;

	return find_max(root->right);
}

static void turn_right(struct score_node_st** root)
{
	struct score_node_st* current = *root;

	*root = current->left;
	current->left = NULL;
	find_max(*root)->right = current;
}

void balance(struct score_node_st** root)
{
	int sub = 0;

	if (*root == NULL)
	{
		return;
	}

	while (1)
	{
		sub = get_num((*root)->left) - get_num((*root)->right);
		if (sub >= -1 && sub <= 1)
		{
			break;
		}
		if (sub < -1)
		{
			turn_left(root);
		}
		else
		{
			turn_right(root);
		}
	}

	balance(&(*root)->left);
	balance(&(*root)->right);
}

