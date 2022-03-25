#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"

void global_print_s(void *record)
{
    GLOBAL *t_global = record;
    printf("%d--%s--%d\n", t_global->id, t_global->name, t_global->data);
}

int always_match(const void *p1, const void *p2)
{
    return 0;
}