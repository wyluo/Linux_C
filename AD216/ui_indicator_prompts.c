#include "ui_indicator_prompts.h"
#include "ui_indicator.h"
#include <stdio.h>
#include <stdlib.h>

ui_prompts_task_data_t the_prompts;

static bool uiPrompts_IsUserHandledPromptIndex(MessageId id, size_t *index)
{
    bool result = FALSE;
    for(size_t i = 0; i < the_prompts.num_user_prompts; i++)
    {
        if(the_prompts.user_prompts[i].messager_id == id)
        {
            *index = i;
            result = TRUE;
            break;
        }
    }
    return result;
}

static bool uiPrompts_IsUserHandlePrompt(MessageId id)
{
    bool result;
    size_t dummy;
    result = uiPrompts_IsUserHandledPromptIndex(id, &dummy);
    UNUSED(dummy);
    return result;
}

static bool uiPrompts_GetPromptIndexFromMappingTable(MessageId id, uint16 *prompt_index)
{
    return UiIndicator_GetIndexFromMappingTable(
                the_prompts.sys_event_to_prompt_data_mappings,
                the_prompts.mapping_table_size,
                id,
                prompt_index
    );
}

static bool uiPrompts_IsPromptMandatory(MessageId sys_event)
{
    uint16 prompt_index;
    if(uiPrompts_IsUserHandlePrompt(sys_event))
    {
        const ui_event_indicator_table_t *prompt_to_play = uiPrompts_GetDataForUserEvent(sys_event);
        return prompt_to_play->await_indication_completion;
    }
    else if(uiPrompts_GetPromptIndexFromMappingTable(sys_event, &prompt_index))
    {
        return &UiIndicator_GetDataForIndex(the_prompts.sys_event_to_prompt_data_mappings,
                                            the_prompts.mapping_table_size,
                                            prompt_index)->prompt;
    }
}

static void uiPrompts_SchedulePromptPlay(MessageId sys_event)
{
    const ui_prompt_data_t *config = ui_Prompts_GetDataForPrompt(sys_event);
}

static void uiPrompts_HandleMessage(Task task, MessageId id, Message message)
{
    uint16 prompt_index = 0;

    UNUSED(task);
    UNUSED(message);

    //DEBUG_LOG("uiPrompts_HandleMessage MESSAGE:ui_internal_prompt_messages:0x%04x", id);
}

//处理内部提示音
static void uiPrompts_HandleInternalPrompt(Task task, MessageId sys_event, Message message)
{
    UNUSED(task);
    UNUSED(message);

    /* Mandatory prompts (e.g. indicating shutdown) should always be played,
       regaless of whether we are rendering indications based on the current
       device topology role and any other gating factors. */
    if(the_prompts.generate_ui_events || uiPrompts_IsPromptMandatory(sys_event))
    {
        uiPrompts_SchedulePromptPlay(sys_event);
    }
}




/*! \brief Initialise Ui prompts module */
bool UiPrompts_Init(Task init_task)
{
    UNUSED(init_task);
    
    //DEBUG_LOG("UiPrompts_Init");

    memset(&the_prompts, 0, sizeof(ui_prompts_task_data_t));//结构体the_prompts 初始化为0

    //面向对象写法？
    the_prompts.task.handler = uiPrompts_HandleMessage;
    the_prompts.prompt_task.handler = uiPrompts_HandleInternalPrompt;
    //

    the_prompts.no_repeat_period_in_ms = DEFAULT_NO_REPEAT_DELAY;
    the_prompts.generate_ui_events = TRUE;

    //the_prompts.num_user_prompts = 

    return TRUE;
}