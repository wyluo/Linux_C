#include "key_hal.h"

static KeyStackdef mKeyStackdef;

/*! brief  使用栈相关的操作？ */
/* 入栈 */
static void PushKey_Stack(unsigned short key_id, unsigned key_press, unsigned char param)
{
    mKeyStackdef.KeyInfoArry[mKeyStackdef.PushNum].key_id = key_id;
    mKeyStackdef.KeyInfoArry[mKeyStackdef.PushNum].key_press = key_press;
    mKeyStackdef.KeyInfoArry[mKeyStackdef.PushNum].param = param;
    if(++(mKeyStackdef.PushNum) >= ARRY_MAX_LEN)//防数组溢出
        mKeyStackdef.PushNum = 0;
}

/* 出栈 */
bool PopKey_Stack(T_KEY_PRESS_HANDLE_T *KeyValue)
{
    if(mKeyStackdef.PopNum != mKeyStackdef.PushNum)
    {
        *KeyValue = mKeyStackdef.KeyInfoArry[mKeyStackdef.PopNum];
        if(++(mKeyStackdef.PopNum) >= ARRY_MAX_LEN)//防数组溢出
        {
            mKeyStackdef.PopNum = 0;
        }
        return TRUE;
    }
    return FALSE;
}

