#ifndef KEY_HAL_H
#define KEY_HAL_H

#include <stdbool.h>
#include "types.h"

#define ARRY_MAX_LEN    (10)

#define KEY_DOWN    0X01

typedef struct T_KEY_HANDLE
{
    unsigned short key_id;
    unsigned char  key_press;
    unsigned char param;
}T_KEY_PRESS_HANDLE_T;

typedef struct
{
    uint8 PopNum;//出栈数量
    uint8 PushNum;//入栈数量
    T_KEY_PRESS_HANDLE_T KeyInfoArry[ARRY_MAX_LEN];
}KeyStackdef;

static void PushKey_Stack(unsigned short key_id, unsigned key_press, unsigned char param);
bool PopKey_Stack(T_KEY_PRESS_HANDLE_T *KeyValue);


#endif