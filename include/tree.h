#ifndef TREE_H
#define TREE_H

#define NAMESIZE 32
struct score_st
{
	int id;
	char name[NAMESIZE];
	int data1;
	int data2;
};

struct score_node_st
{
	struct score_st data;
	struct score_node_st* left;
	struct score_node_st* right;
};

int insert(struct score_node_st** root, struct score_st* data);
struct score_st* find(struct score_node_st* root, int id);
void print_s(struct score_st* d);
void draw_(struct score_node_st* root, int level);
void draw(struct score_node_st* root);

#endif
