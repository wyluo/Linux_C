#include <stdio.h>

int main(int argc, char *argv[])
{
    const int *p1;//p1可以指向int类型的地址，但不可以用*p1的方式修改这个内存的值
    int a1 = 109;
    int b1 = 1067;
    int *const p2 = &b1;//p2指向了且只能指向b1的地址，可以通过*p2读写这个变量的值
    //*p1 = 108；//error
    printf("*p1 == %d\n", *p1);

    int arry[19] = {0};
    int *pointer1 = NULL;
    pointer = arry;//当指针变量指向一个数组的时候，c语言语法规定指针变量名可以当数组名使用
    pointer[3] = 18;
    for(int i = 0; i < sizeof(arry)/sizof(arry[0]; i++)
    {
        printf("arry[%d] == %d\n", i, pointer[i]);
    } 
    return 0;
}