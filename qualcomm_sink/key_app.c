#include "key_app.h"
#include "key_driver.h"

const KEY_MENU_T key_app_menu_table_t[] ={
    {{KEY_ID_FN0,    KEY_DOWN,    0xff}, KEY_POWER},
};

const unsigned char key_app_menu_table_num = sizeof(key_app_menu_table_t) / sizeof(*key_app_menu_table_t);//计算key_app_menu_table_t 的大小

void a_KeyEvtTranslate(void)
{
    T_KEY_PRESS_HANDLE_T key_handle;
    
    if()
}