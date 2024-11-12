
#pragma once

#include "Message.h"


class WrappedMessage
{
public:
    static auto Create(const Message& message, const Id& id) -> WrappedMessage;

    WrappedMessage(const WrappedMessage& other) = default;

    bool operator==(const WrappedMessage& other) const;

private:
    WrappedMessage(const Message& message, const Id& id);
    WrappedMessage(Message&& message, Id&& id);

public:
    auto message() const -> Message { return message_; };
    auto id() const -> Id { return id_; };

private:
    Message message_;
    Id id_;
};
