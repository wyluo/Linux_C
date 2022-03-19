#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/tree.h"

#if 0
#include "../include/polynomial.h"

int main(int argc, char* argv[])
{
	int arry_a[][2] = { {5,0}, {2,1}, {8,8}, {3,16} };
	int arry_b[][2] = { {6,1}, {16,6}, {-8,8} };

	struct Polynomial_list* node_ptr1 = NULL, * node_ptr2 = NULL;

	node_ptr1 = polynomial_creat(arry_a, 4);
	if (node_ptr1 == NULL)
		return 0;
	node_ptr2 = polynomial_creat(arry_b, 3);
	if (node_ptr2 == NULL)
		return 0;

	polynomial_show(node_ptr1);
	polynomial_show(node_ptr2);
	printf("%d\n", __LINE__);

	polynomial_union(node_ptr1, node_ptr2);
	printf("%d\n", __LINE__);
	polynomial_show(node_ptr1);

	return 0;
}
#endif

#if 0
#include "../include/josephus.h"

int main(int argc, char* argv[])
{
	josephus_list* jose_node = NULL;
	int location = 3;

	jose_node = JosePhus_List_Create(JOSE_NUM);
	JosePhus_List_Show(jose_node);

	JosePhus_List_Kill(&jose_node, location);

	printf("current node list is : ");
	JosePhus_List_Show(jose_node);

	return 0;
}
#endif

#if 1
int main(int argc, char* argv[])
{
	int tmp = 0;
	int arry[] = {5,4,9,1,7,3,8,6,2};
	struct score_st score_st_tmp;
	struct score_node_st *score_node_tree = NULL;
	struct score_st* dataptr;

	for (tmp = 0; tmp < sizeof(arry) / sizeof(*arry); tmp++)
	{
		score_st_tmp.id = arry[tmp];
		snprintf(score_st_tmp.name, NAMESIZE, "name:%d",arry[tmp]);
		score_st_tmp.data1 = rand() % 100;
		score_st_tmp.data2 = rand() % 100;

		insert(&score_node_tree, &score_st_tmp);
	}

	draw(score_node_tree);

#if 0
	int tmp_id = 11;
	dataptr = find(score_node_tree, tmp_id);
	if (dataptr == NULL)
	{
		printf("not find id:%d\n", tmp_id);
	}
	print_s(dataptr);
#endif
	return 0;
}
#endif
