#ifndef UI_INDICATOR_PROMPT_TYPES_H
#define UI_INDICATOR_PROMPT_TYPES_H

#include "types.h"
#include "kymera.h"

/*! Audio prompt configuration */
typedef struct
{
    const char *filename;
    uint32 rate;
    promptFormat format;
    unsigned interuptible : 1;
    unsigned queueable : 1;
    unsigned requires_repeat_delay : 1;
    unsigned local_feedback : 1;        /*! The prompt will only be rendered on the local device */
}ui_prompt_data_t;

#endif