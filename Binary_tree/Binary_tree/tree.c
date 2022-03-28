#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "global.h"

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
#if 1
/*
 *加入数组
 */
struct BiTNode* BiTNode_create(struct BiTNode** root, int value)
{
	if (*root == NULL)
	{
		*root = (struct BiTNode*)malloc(sizeof(struct BiTNode));
		if (*root == NULL)
		{
			printf("out of menory, press any key to quie...\n");
			exit(0);
		}

		(*root)->data = value;
		(*root)->lchild = (*root)->rchild = NULL;
		(*root)->arry_order = 0;
	}
	if (value < (*root)->data)
	{
		BiTNode_create(&(*root)->lchild, value);
	}
	else
	{
		BiTNode_create(&(*root)->rchild, value);
	}
	return (*root);
}

static int length = 0;
//获取二叉树总的节点数并返回
int nodeNum(struct BiTNode* root)
{
	if (root != NULL)
	{
		length++;
		nodeNum(root->lchild);
		nodeNum(root->rchild);
	}
	return length;
}
#endif

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

/*
 *删除原则：左边顶上
 */
void delete(struct score_node_st** root, int id)
{
	struct score_node_st** newnode = root;
	struct score_node_st* current_node = NULL;

	while (*newnode != NULL && (*newnode)->data.id != id)
	{
		if (id < (*newnode)->data.id)
		{
			newnode = &(*newnode)->left;
		}
		else
		{
			newnode = &(*newnode)->right;
		}
	}

	if (*newnode == NULL)//means not find
	{
		return;
	}
	
	//if find , do delete
	current_node = *newnode;
	if (current_node->left == NULL)
	{
		*newnode = current_node->right;//right child replace
	}
	else
	{
		*newnode = current_node->left;//left child replace
		find_max(current_node->left)->right = current_node->right;
	}

	free(current_node);
}

/*
 *先序遍历
 */
void travel(struct score_node_st* root)
{
	if (root == NULL)
	{
		return;
	}
	print_s(&root->data);

	travel(root->left);

	travel(root->right);
}

/*中序遍历
*	travel(root->left);
*	print_s(&root->data);
*	travel(root->right);
*/

/*后序遍历
*travel(root->left);
*travel(root->right);
*print_s(&root->data);
*/

/*层序遍历*/
void travel_level(struct score_node_st* root)
{
	QUEUE *ptr = NULL;
	struct score_node_st* current = NULL;
	int ret = 0;

	ptr = Link_Storage_Create(sizeof(struct score_node_st *));
	if (ptr == NULL)
	{
		return;
	}

	Link_Storage_Enter_queue(ptr, &root);

	while (1)
	{
		ret = Link_Storage_Exit_queue(ptr, &current);
		if (ret == -1)
		{
			break;
		}
		global_print_s(&current->data);

		if (current->left != NULL)
			Link_Storage_Enter_queue(ptr, &current->left);

		if (current->right != NULL)
			Link_Storage_Enter_queue(ptr, &current->right);


	}

	Link_Storage_Destory_queue(ptr);
}

/*
static int Binary_Save_(struct score_node_st* root)
{
	printf("(");

	if (root == NULL)//当前为叶子结点
	{
		printf(")");
		return 0;
	}

	

	Binary_Save_(root->left);

	Binary_Save_(root->right);

	printf(")");
}

int Binary_Save(struct score_node_st* root)
{
	if (root == NULL)
		return -1;

	Binary_Save_(root);
}
*/

