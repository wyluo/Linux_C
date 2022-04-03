#include "ui_indicator.h"
#include <stdio.h>
#include <stdlib.h>

bool UiIndicator_GetIndexFromMappingTable(const ui_event_indicator_table_t *mapping_table, 
                                            uint16 mappin_gtable_size,
                                            MessageId id,
                                            uint16 *index)
{
    bool found = FALSE;
    for(*index = 0; *index < mappin_gtable_size; (*index)++)
    {
        if(id == mapping_table[*index].sys_event)
        {
            found = TRUE;
            break;
        }
    }
    return found;
}

const ui_ind_data_t *UiIndicator_GetDataForIndex(const ui_event_indicator_table_t *mapping_table, 
                                                    uint16 mapping_table_size, 
                                                    uint16 index)
{
    const ui_ind_data_t *data = NULL;
    PanicFalse(index < mapping_table_size);//PanicFalse ??? means
    data = &mapping_table[index].data;
    PanicFalse(data != NULL);
    return data;
}