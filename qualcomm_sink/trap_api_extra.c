#include "trap_api_extra.h"

/*!
    @brief Send a message to the corresponding task immediately.
    The message will be passed to free after delivery.

    @param task The to deliver the message to.
    @param id The message type identifier.
    @param message The message data (if any).
*/
void Message(Task task, MessageId id, void *message)
{
    MeaasgeSendLater(task, id, message, D_IMMEDIATE);
}