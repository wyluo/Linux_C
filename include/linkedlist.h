#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*带头结点的单链表*/

typedef int datatype;

typedef struct single_list_st {
	datatype data;
	struct single_list_st* next;
}list;

list* list_create();
int list_insert(list* me, int location, datatype* data);
int list_order_insert(list* me, datatype* data);
void list_display(list* me);
void list_delete(list* me, datatype* data);
int list_delete_at(list* me, int location, datatype* data);
void list_destory(list* me);

#endif
