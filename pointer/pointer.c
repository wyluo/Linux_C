#include <stdio.h>

int main(int argc, char *argv[])
{
    const int *p1;//p1可以指向int类型的地址，但不可以用*p1的方式修改这个内存的值
    int a1 = 109;
    //*p1 = 108；//error
    printf("*p1 == %d\n", *p1);
    return 0;
}