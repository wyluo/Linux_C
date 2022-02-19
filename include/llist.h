#ifndef LLIST_H
#define LLIST_H

#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2

/*变长形结构体*/
#define LONG_STRUCT

#define CPP_OOPx

/*数据结构隐藏和封装*/
#define HIDDEN_STRUCT

typedef void llist_op(const void*);
typedef int llist_cmp(const void*, const void*);//比较函数

#ifdef HIDDEN_STRUCT
//typedef struct llist_head_st LLIST;
typedef void LLIST;//此处用void再次隐藏结构体llist_head_st
#endif

#ifdef HIDDEN_STRUCT
#else
struct llist_node_st{
#ifdef LONG_STRUCT
#else
	void *data;
#endif
	struct llist_node_st *prev;
	struct llist_node_st *next;
#ifdef LONG_STRUCT
	char data[1];/*c99才支持长度为0的数组，data[1]为了兼容性*/
#endif
};


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
	int (*fetch)(struct llist_head*, const void *, llist_cmp*, void *);
#endif
}LLIST;
#endif

LLIST* llist_create(int initsize);
void llist_destory(LLIST* ptr);
int llist_insert(LLIST* ptr, const void* data, int mode);
void llist_travel(LLIST* ptr, llist_op* op);
static struct llist_node_st* find_(LLIST* ptr, const void* key, llist_cmp* cmp);
void* llist_find(LLIST* ptr, const void* key, llist_cmp* cmp);
int llist_delete(LLIST* ptr, const void* key, llist_cmp* cmp);
int llist_fetch(LLIST* ptr, const void* key, llist_cmp* cmp, void* data);



#endif