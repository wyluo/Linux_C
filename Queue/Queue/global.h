#ifndef GLOBAL_H
#define GLOBAL_H

#define NAMESIZE 64

typedef struct score_node_st
{
    int id;
    char name[NAMESIZE];
    int data1;
}SCORE;

void print_s(void *record);
int always_match(const void *p1, const void *p2);

#endif