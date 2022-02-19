#ifndef LLIST_H
#define LLIST_H

#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2

/*�䳤�νṹ��*/
#define LONG_STRUCT

#define CPP_OOPx

/*���ݽṹ���غͷ�װ*/
#define HIDDEN_STRUCT

typedef void llist_op(const void*);
typedef int llist_cmp(const void*, const void*);//�ȽϺ���

#ifdef HIDDEN_STRUCT
//typedef struct llist_head_st LLIST;
typedef void LLIST;//�˴���void�ٴ����ؽṹ��llist_head_st
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
	char data[1];/*c99��֧�ֳ���Ϊ0�����飬data[1]Ϊ�˼�����*/
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