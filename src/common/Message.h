
#pragma once

#include <string>
#include <optional>
#include <chrono>
#include "User.h"
#include "Id.h"


using Timestamp = std::chrono::time_point<std::chrono::system_clock>;

struct Message
{
    std::wstring text;
    User sender, receiver;
    Timestamp created;
    std::optional<Timestamp> lastEdited;

    bool operator==(const Message& other) const
    {
        return text == other.text
            and sender == other.sender
            and receiver == other.receiver
            and created == other.created
            and lastEdited == other.lastEdited;
    }
};


