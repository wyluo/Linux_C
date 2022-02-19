#ifndef NOHEAD_H
#define NOHEAD_H

/*单链表 无头结点*/
#define NAMESIZE 32

struct Data_st {
	int id;
	char name[NAMESIZE];
	int value1;
	int value2;
};

struct Single_list {
	struct Data_st data;
	struct Single_list* next;
};

//struct Single_list* single_list_create(struct Single_list* list, struct Data_st* data);
struct Single_list* single_list_insert(struct Single_list* list, struct Data_st* data);
int singlelist_insert(struct Single_list** list, struct Data_st* data);
int singlelist_delete(struct Single_list** list);
void list_show(struct Single_list* list);
int single_list_find(struct Single_list* list, int id);
struct Data_st* ptr_find(struct Single_list* list, int id);
void singlelist_destory(struct Single_list* list);

/*约瑟夫算法*/
/*Josephus problem*/

#define JOSE_NUM 8

typedef struct Jose_list {
	int data;
	struct Jose_list* next;
}jose_list;

jose_list* Jose_list_creat(int num);
void Jose_list_show(jose_list * Jose_node);

#endif