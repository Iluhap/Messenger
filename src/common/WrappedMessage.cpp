
#include "WrappedMessage.h"


auto WrappedMessage::Create(const Message& message, const Id& id) -> WrappedMessage
{
    return WrappedMessage {message, id};
}

WrappedMessage::WrappedMessage(const Message& message, const Id& id)
    :
    message_(message),
    id_(id)
{
}

WrappedMessage::WrappedMessage(Message&& message, Id&& id)
    :
    message_(message),
    id_(id)
{
}
bool WrappedMessage::operator==(const WrappedMessage& other) const
{
    return message_ == other.message_ and id_ == other.id_;
}
