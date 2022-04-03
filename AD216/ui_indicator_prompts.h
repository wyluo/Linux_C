#ifndef UI_INDICATOR_PROMPTS_H
#define UI_INDICATOR_PROMPTS_H

#include <stdbool.h>
#include "message_.h"

#define DEFAULT_NO_REPEAT_DELAY    D_SEC(5)
#define UI_PROMPTS_MAX_USER_FUNCTIONS    3

typedef struct
{
    ui_prompts_data_fn user_fn;
    MessageId messager_id;
}ui_prompts_user_config_t;

/*! \brief ui_prompt task structure */
typedef struct
{
    /*! The task. */
    TaskData task;

    /*! Seperate task for handleing conditional message to play prompts */
    TaskData prompt_task;

    /*! This is a hold off time for after a voice prompt is played, in milliseconds. When a voice prompt
    is played, for the period of time specified, any repeat of this prompt will not be played. If the no
    repeat period set to zero, then all prompts will be played, regardless of whether the prompt was
    recently played. */
    Delay no_repeat_period_in_ms;

    /*! Specifies whether the UI Indicator should generate UI Indicarions from System Event messages
    received at the task handler. \note this is not the same as whether indication playback is enabled. */
    unsigned generate_ui_events : 1;

    /*! The configuration table of System Event to prompts to play, passed from the Application. */
    const ui_event_indicator_table_t *sys_event_to_prompt_data_mappings;
    uint8 mapping_table_size;

    size_t num_user_prompts;
    ui_prompts_user_config_t user_prompts[UI_PROMPTS_MAX_USER_FUNCTIONS];

}ui_prompts_task_data_t;

bool UiPrompts_Init(Task init_task);



#endif