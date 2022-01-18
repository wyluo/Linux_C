#include <stdio.h>
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