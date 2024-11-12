
#pragma once

#include <unordered_map>
#include <vector>

#include "WrappedMessage.h"


namespace Chat {

class Response;

class History
{
public:
    auto Add(const Message& message) -> Response;
    auto Edit(const Id& message_id, const Message& new_message) -> Response;
    auto Delete(const Id& message_id) -> Response;

    auto GetMessages() const -> std::vector<WrappedMessage>;

private:
    std::unordered_map<Id, WrappedMessage> messages_;
};

} // namespace Chat
