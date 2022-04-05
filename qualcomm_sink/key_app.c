#include "key_app.h"
#include "key_driver.h"
#include "trap_api_extra.h"

key_task_t Key_task_T;

const KEY_MENU_T key_app_menu_table_t[] ={
    {{KEY_ID_FN0,    KEY_DOWN,    0xff}, KEY_POWER},
};

const unsigned char key_app_menu_table_num = sizeof(key_app_menu_table_t) / sizeof(*key_app_menu_table_t);//计算key_app_menu_table_t 的大小

void a_KeyEvtTranslate(void)
{
    T_KEY_PRESS_HANDLE_T key_handle;
    
    if(PopKey_Stack(&key_handle) == TRUE)
    {
        //按键table遍历
        for(unsigned char i = 0;
            i < key_app_menu_table_num;
            i++)
        {
            if((key_app_menu_table_t[i].press_handle.param == 0xff)
                || key_app_menu_table_t[i].press_handle.param == key_handle.param)
            {
                if(key_app_menu_table_t[i].press_handle.key_press == key_handle.key_press)
                {
                    if(key_app_menu_table_t[i].press_handle.key_id == key_handle.key_id)
                    {
                        MessageSend(&Key_task_T, key_app_menu_table_t[i].sys_event, 0);
                    }
                }
            }
        }
    }
}