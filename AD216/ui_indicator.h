#ifndef INDICATOR_H
#define INDICATOR_H

#include "message_.h"
#include <stdbool.h>
#include "ui_indicator_prompt_types.h"

typedef union
{
    //ui_tone_data_t tone;
    ui_prompt_data_t prompt;
    //ui_led_data_t led;
}ui_ind_data_t;

typedef struct
{
    /*! System Event that should cause a UI Event to be indicated */
    MessageId sys_event;

    /*! Data about the UI Indication associated with the System Event */
    ui_ind_data_t data;

    /*! Determines whether the UI Indicator should receive notification
        once the indication has completed. */
        bool await_indication_completion;
}ui_event_indicator_table_t;

bool UiIndicator_GetIndexFromMappingTable(const ui_event_indicator_table_t *mapping_table, 
                                            uint16 mappin_gtable_size,
                                            MessageId id,
                                            uint16 *index);

const ui_ind_data_t *UiIndicator_GetDataForIndex(const ui_event_indicator_table_t *mapping_table, 
                                                    uint16 mapping_table_size, 
                                                    uint16 index);                                           

#endif