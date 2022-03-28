#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*binary tree
*/
#include "tree.h"

int main(int argc, char* argv[])
{
	int arry[] = { 1,9,6,4,5,7,3 };
	struct score_st t_score_st, *dataptr = NULL;
	struct score_node_st* tree = NULL;
	int i = 0;

	for (i = 0; i < sizeof(arry) / sizeof(*arry); i++)
	{
		t_score_st.id = arry[i];
		snprintf(t_score_st.name, NAME_SIZE, "name:%d", arry[i]);
		t_score_st.data = rand() % 100;

		Insert(&tree, &t_score_st);
	}

	//draw(tree);

	//printf("\n\n");

	//balance(&tree);
	draw(tree);

	printf("\n\n");

	//travel(tree);
	//travel_level(tree);

#if 0
	int tmp_id = 5;
	delete(&tree, tmp_id);
	draw(tree);

	printf("rebalance\n\n");
	balance(&tree);
	draw(tree);
#endif
#if 0
	int tmp_id = 9;
	dataptr = Find(tree, tmp_id);
	if (dataptr == NULL)
	{
		printf("could not find : %d\n", tmp_id);
	}

	print_s(dataptr);
#endif

	return 0;
}