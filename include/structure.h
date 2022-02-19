#ifndef STRUCTURE_H
#define STRUCTURE_H

#define MAXLENGTH 32

typedef struct Student_st {
	int value1;
	char value2[MAXLENGTH];
	int value3;
	int value4;
}stu_str;

void menu(void);
stu_set(stu_str* ptr1, const stu_str* ptr2);
stu_change(stu_str* ptr1, const char* newvalue);
stu_show(stu_str* ptr1);

#endif
