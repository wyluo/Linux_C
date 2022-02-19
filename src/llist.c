#include "../include/llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef HIDDEN_STRUCT
struct llist_node_st {
#ifdef LONG_STRUCT
#else
	void* data;
#endif
	struct llist_node_st* prev;
	struct llist_node_st* next;
#ifdef LONG_STRUCT
	char data[1];/*c99才支持长度为0的数组，data[1]为了兼容性*/
#endif
};

#ifdef HIDDEN_STRUCT
struct llist_head_st {
	int size;
	struct llist_node_st head;
};
#else
typedef struct llist_head
{
	int size;
	struct llist_node_st head;
#ifdef CPP_OOP
	void (*destory)(struct llist_head*);
	int (*insert)(struct llist_head*, const void*, int);
	void (*travel)(struct llist_head*, llist_op*);
	void* (*find)(struct llist_head*, const void*, llist_cmp*);
	int (*delete)(struct llist_head*, const void*, llist_cmp*);
	int (*fetch)(struct llist_head*, const void*, llist_cmp*, void*);
#endif
}LLIST;
#endif
#endif

LLIST *llist_create(int initsize)
{
#ifdef HIDDEN_STRUCT
	struct llist_head_st* newptr;
#else
	LLIST* newptr;
#endif
	newptr = malloc(sizeof(*newptr));
	if (newptr == NULL)
	{
		return NULL;
	}

	newptr->size = initsize;
#ifdef LONG_STRUCT
#else
	newptr->head.data = NULL;
#endif
	newptr->head.next = &newptr->head;
	newptr->head.prev = &newptr->head;

#ifdef CPP_OOP
	newptr->destory = llist_destory;
	newptr->insert = llist_insert;
	newptr->travel = llist_travel;	
	newptr->find = llist_find;
	newptr->delete = llist_delete;
	newptr->fetch = llist_fetch;
#endif

	return newptr;
}

#ifdef HIDDEN_STRUCT
void llist_destory(struct llist_head_st* ptr)
#else
void llist_destory(LLIST* ptr)
#endif
{
	struct llist_node_st *curnode, *nextnode;
	
	for (curnode = ptr->head.next; curnode != &ptr->head; curnode = nextnode)
	{
		nextnode = curnode->next;
#ifdef LONG_STRUCT
#else
		free(curnode->data);
#endif
		free(curnode);
	}
	free(ptr);
}

#ifdef HIDDEN_STRUCT
int llist_insert(struct llist_head_st* ptr, const void* data, int mode)
#else
int llist_insert(LLIST *ptr, const void *data, int mode)
#endif
{
	struct llist_node_st *newnode;
#ifdef LONG_STRUCT
	newnode = malloc(sizeof(*newnode) + ptr->size -4);
#else
	newnode = malloc(sizeof(*newnode));
#endif
	if(newnode == NULL)
		return -1;

#ifdef LONG_STRUCT
#else
	newnode->data = malloc(ptr->size);
	if(newnode->data == NULL)
		return -2;
#endif
	memcpy(newnode->data, data, ptr->size);

	if(mode == LLIST_FORWARD)
	{
		newnode->prev = &ptr->head;
		newnode->next = ptr->head.next;
	}
	else if(mode == LLIST_BACKWARD)
	{
		newnode->prev = ptr->head.prev;
		newnode->next = &ptr->head;
	}
	else
	{
		return -3;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;

	return 0;
}

/*回调函数*/
#ifdef HIDDEN_STRUCT
void llist_travel(struct llist_head_st* ptr, llist_op* op)
#else
void llist_travel(LLIST* ptr, llist_op* op)
#endif
{
	struct llist_node_st* curnode;

	for (curnode = ptr->head.next; curnode != &ptr->head; curnode = curnode->next)
	{
		op(curnode->data);
	}
}

#ifdef HIDDEN_STRUCT
static struct llist_node_st* find_(struct llist_head_st* ptr, const void* key, llist_cmp* cmp)
#else
static struct llist_node_st* find_(LLIST * ptr, const void* key, llist_cmp * cmp)
#endif
{
	struct llist_node_st *cur;

	for (cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
	{
		if(cmp(key, cur->data) == 0)
		{
			break;
		}
	}
	return cur;
}

#ifdef HIDDEN_STRUCT
void* llist_find(struct llist_head_st* ptr, const void* key, llist_cmp* cmp)
#else
void* llist_find(LLIST* ptr, const void* key, llist_cmp* cmp)
#endif
{
#ifdef LONG_STRUCT
	struct llist_node_st *node;
	node = find_(ptr, key, cmp);
	if(node == &ptr->head)
		return NULL;
	return node->data;
#else
	return find_(ptr, key, cmp)->data;
#endif
}

#ifdef HIDDEN_STRUCT
int llist_delete(struct llist_head_st* ptr, const void* key, llist_cmp* cmp)
#else
int llist_delete(LLIST* ptr, const void* key, llist_cmp* cmp)
#endif
{
	struct llist_node_st* node;

	node = find_(ptr, key, cmp);
	if (node == &ptr->head)
		return -1;
	node->prev->next = node->next;
	node->next->prev = node->prev;
#ifdef LONG_STRUCT
#else
	free(node->data);
#endif
	free(node);

	return 0;
}

#ifdef HIDDEN_STRUCT
int llist_fetch(struct llist_head_st* ptr, const void* key, llist_cmp* cmp, void* data)
#else
int llist_fetch(LLIST* ptr, const void* key, llist_cmp* cmp, void *data)
#endif
{
	struct llist_node_st* node;

	node = find_(ptr, key, cmp);
	if (node == &ptr->head || node == NULL)
		return -1;

	node->prev->next = node->next;
	node->next->prev = node->prev;
	if (data != NULL)
	{
		memcpy(data, node->data, ptr->size);
	}
#ifdef LONG_STRUCT
#else
	free(node->data);
#endif
	free(node);

	return 0;
}