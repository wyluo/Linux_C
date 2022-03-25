#ifndef LLIST_H
#define LLIST_H

#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2

typedef int llist_cmp(const void*, const void*);

struct llist_node_st
{
    void *data;
    struct llist_node_st *prev;
    struct llist_node_st *next;
};

typedef struct llist_head
{
    int size;
    struct llist_node_st head;
}LLIST;

LLIST *llist_create(int initsize);
int llist_insert(LLIST *ptr, const void *data, int mode);
static struct llist_node_st *find_(LLIST *ptr, const void *key, llist_cmp *cmp);
int llist_fetch(LLIST *ptr, const void *key, llist_cmp* cmp, void *data);
void llist_destory(LLIST *ptr);


#endif