#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

void print_s(void *record)
{
    struct score_node_st *t_score = record;
    printf("%d--%s--%d\n", t_score->id, t_score->name, t_score->data1);
    //printf("%d\n", t_score->id);
}

int always_match(const void *p1, const void *p2)
{
    return 0;
}