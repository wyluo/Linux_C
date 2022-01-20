#ifndef JOSEPHUS_H
#define JOSEPHUS_H

#define JOSE_NUM 8

typedef struct JosePhus_list {
	int data;
	struct JosePhus_list* next;
}josephus_list;

josephus_list* JosePhus_List_Create(int num);
void JosePhus_List_Show(josephus_list* curr_node);

#endif
