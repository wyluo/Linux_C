#ifndef POLYNOMAIL_H
#define POLYNOMAIL_H

typedef struct Polynomial_list {
	int coef;
	int exp;
	struct Polynomial_list* next;
}polynomial_list;

struct Polynomial_list* polynomial_creat(int a[][2], int length);
void polynomial_show(struct Polynomial_list* node1);
void polynomial_union(polynomial_list* node_ptr1, polynomial_list* node_ptr2);

#endif