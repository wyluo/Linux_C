#ifndef GLOBAL_H
#define GLOBAL_H

#define NAMESIZE 64

typedef struct Global_node_st
{
    int id;
    char name[NAMESIZE];
    int data;
}GLOBAL;

void global_print_s(void *record);
int always_match(const void *p1, const void *p2);

#endif