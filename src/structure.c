#define _CRT_SECURE_NO_WARNINGS

#include "../include/structure.h"
#include <string.h>
#include <stdio.h>

void menu(void)
{
	printf("\n1 set\n2 show\n3 change name\n\n");
}

stu_set(stu_str* ptr1, const stu_str * ptr2)
{
	*ptr1 = *ptr2;
#if 0
	ptr1->value1 = 100;
	strncpy(ptr1->value2, "AAA", MAXLENGTH);
	ptr1->value3 = 90;
	ptr1->value4 = 80;
#endif
}

stu_change(stu_str* ptr1, const char* newvalue)
{
	strncpy(ptr1->value2, newvalue, MAXLENGTH);
}

stu_show(stu_str* ptr1)
{
	printf("stu1 data is:\n");
	printf("number=%d,name=%s,value3=%d,value4=%d\n", ptr1->value1, ptr1->value2, ptr1->value3, ptr1->value4);
}
