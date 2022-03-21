#ifndef __TREE_H
#define __TREE_H

#define NAME_SIZE 32
struct score_st
{
	int id;
	char name[NAME_SIZE];
	int data;
};

struct score_node_st
{
	struct score_st data;
	struct score_node_st* left;
	struct score_node_st* right;
};

int Insert(struct score_node_st** root, struct score_st* data);
struct score_st* Find(struct score_node_st* root, int id);
void print_s(struct score_st* data);
static void draw_(struct score_node_st* root, int level);
void draw(struct score_node_st* root);
static int get_num(struct score_node_st* root);
static struct score_node_st* find_min(struct score_node_st* root);
static void turn_left(struct score_node_st** root);
static struct score_node_st* find_max(struct score_node_st* root);
static void turn_right(struct score_node_st** root);
void balance(struct score_node_st** root);
void delete(struct score_node_st** root, int id);


#endif