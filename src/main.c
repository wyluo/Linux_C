#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#if 0
/*单链表 无头结点*/
#include "../include/nohead.h"

int main(int argc, char* argv[])
{
	struct Single_list* list = NULL;
	struct Data_st data;
	struct Data_st* ptr_data = NULL;
	int tmp, ret;
	int id = 15;

	for (tmp = 0; tmp < 7; tmp++)
	{
		data.id = tmp;
		snprintf(data.name, NAMESIZE, "std%d", tmp);
		data.value1 = rand() % 100;
		data.value2 = rand() % 100;

#if 0
		list = single_list_insert(list, &data);
#else
		/*使用二级指针*/
		ret = singlelist_insert(&list, &data);
		if (ret)
			exit(1);
#endif
	}
	list_show(list);

	printf("\r\n");
#if 0
	single_list_find(list, id);
#else
	ptr_data = ptr_find(list, id);
	if (ptr_data == NULL)
	{
		printf("can not find\n");
		exit(1);
	}
	printf("%d  %s  %d  %d\n",
		ptr_data->id,
		ptr_data->name,
		ptr_data->value1,
		ptr_data->value2);
#endif

	/*
	printf("\r\n");
	singlelist_delete(&list);
	list_show(list);
	*/

	singlelist_destory(list);

	exit(1);
}
#endif

#if 0
/*单链表 带头结点*/
#include "../include/linkedlist.h"

int main(int argc, char* argv[])
{
	list* single_list;
	datatype arr[] = { 12,1,23,99,34,15,44,27 };
	int tmp;
	int value = 12;
	int value1 = 0;
	int err = 0;

	single_list = list_create();
	if (single_list == NULL)
	{
		printf("%s %d\n", __FILE__,__LINE__);
		exit(1);
	}
	//list_display(single_list);

	//printf("%s %d\n", __FILE__, __LINE__);

	for (tmp = 0; tmp < (sizeof(arr) / sizeof(*arr)); tmp++)
	{
		//if (list_insert(single_list, 0, &arr[tmp]))
		if(list_order_insert(single_list,&arr[tmp]))
		{
			printf("%s %d\n", __FILE__, __LINE__);
			exit(1);
		}
	}

	list_display(single_list);

	err = list_delete_at(single_list, 3, &value1);
	if (err)
	{
		exit(1);
	}
	list_display(single_list);
	printf("delete value == %d\n", value1);

#if 0
	list_delete(single_list, &value);
	list_display(single_list);
#endif

	list_destory(single_list);
	
	exit(1);
}

#endif

#if 0
#include "../include/structure.h"

int main(int argc, char* argv[])
{
	stu_str stu1, temp;
	char newName[MAXLENGTH];
	int choise;
	int ret;

	do 
	{
		menu();
		ret = scanf("%d", &choise);
		if (ret != 1)
			break;
		switch (choise)
		{
			case 1:
				printf("input number:");
				//scanf("%d %s %d %d", &temp.value1, temp.value2, &temp.value3, &temp.value4);
				scanf("%d", &temp.value1);
				printf("\n");

				printf("input name(string data):");
				scanf("%s", temp.value2);
				printf("\n");

				printf("input value3):");
				scanf("%d", &temp.value3);
				printf("\n");

				printf("input value4:");
				scanf("%d", &temp.value4);
				printf("\n");

				stu_set(&stu1, &temp);
				break;

			case 2:
				stu_show(&stu1);
				break;

			case 3:
				printf("input new name(string):");
				scanf("%s", newName);
				printf("\n");
				stu_change(&stu1, newName);
				break;

			default:
				break;
		}
	} while (1);

#if 0
	printf("input data:\n");
	scanf("%d %s %d %d",&temp.value1, temp.value2, &temp.value3, &temp.value4);

	stu_set(&stu1, &temp);
	stu_show(&stu1);

	printf("input new value:\n");
	scanf("%s", newName);
	stu_change(&stu1, newName);
	stu_show(&stu1);
#endif
	return 0;
}

#endif

#if 0
/*Josephus problem*/
#include "../include/nohead.h"

int main(int argc, char* argv[])
{
	jose_list* Jose_node = NULL;

	Jose_list_creat(JOSE_NUM);
	Jose_list_show(Jose_node);

	return 0;
}

#endif

#if 1
#include "../include/llist.h"

#define NAMESIZE 32

struct score_st {
	int id;
	char name[NAMESIZE];
	int data1;
	int data2;
};

static void print_s(const void* record)
{
	const struct score_st* r = record;
	printf("%d  %s  %d   %d\n",
		r->id,
		r->name,
		r->data1,
		r->data2);
}

static int id_cmp(const void* key, const void* record)
{
	const int* k = key;
	const struct score_st* r = record;

	return (*k - r->id);
}

static int name_cmp(const void* key, const void* record)
{
	const char* k = key;
	const struct score_st* r = record;

	return strcmp(k, r->name);
}

/*双向链表*/
int main(int argc, char* argv[])
{
	LLIST* handler;
	int tmp = 0, ret = 0;
	struct score_st tmp_st;

	int id = 2;
	char* del_name = "std1";

	struct score_st* ret1;

	handler = llist_create(sizeof(struct score_st));
	if (handler == NULL)
	{
		return 0;
	}

	for (tmp = 0; tmp < 7; tmp++)
	{
		tmp_st.id = tmp;
		snprintf(tmp_st.name, NAMESIZE, "std%d", tmp);
		tmp_st.data1 = rand() % 100;
		tmp_st.data2 = rand() % 100;
#ifdef CPP_OOP
		ret = handler->insert(handler, &tmp_st, LLIST_FORWARD);
#else
		ret = llist_insert(handler, &tmp_st, LLIST_BACKWARD);
#endif
		if (ret)
		{
			return 0;
		}
	}
#ifdef CPP_OOP
	handler->travel(handler, print_s);
#else
	llist_travel(handler, print_s);
#endif

	printf("\n\n");

	//ret = llist_delete(handler, &id, id_cmp);
#ifdef CPP_OOP
	ret = handler->delete(handler, del_name, name_cmp);
#else
	ret = llist_delete(handler, del_name, name_cmp);
#endif
	if (ret)
		printf("delete fail\n");
#ifdef CPP_OOP
	handler->travel(handler, print_s);
#else
	llist_travel(handler, print_s);
	printf("\n");
#endif

#ifdef CPP_OOP
	ret1 = handler->find(handler, &id, id_cmp);
#else
	ret1 = llist_find(handler, &id, id_cmp);
#endif
	if (ret1 == NULL)
	{
		printf("no find\n");
	}
	else
	{
		print_s(ret1);
	}

#ifdef CPP_OOP
	handler->destory(handler);
#else
	llist_destory(handler);
#endif
	return 0;
}
#endif
