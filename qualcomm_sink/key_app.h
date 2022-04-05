#ifndef KEY_APP_H
#define KEY_APP_H

#include "key_hal.h"

typedef enum
{
    KEY_POWER = 0x01,
    KEY_POWER_SHORT
}KEY_SYS_EVENT_TYPE_E;

typedef struct
{
    T_KEY_PRESS_HANDLE_T press_handle;
    unsigned int sys_event;//按键行为对应的系统事件
}KEY_MENU_T;

#endif