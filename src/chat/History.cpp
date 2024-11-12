
#include "History.h"

#include "Response.h"


namespace Chat {

auto History::Add(const Message& message) -> Response
{
    auto id = Id::Create();
    messages_.insert({id, WrappedMessage::Create(message, id)});

    return Response::CreateSuccess();
}

auto History::Edit(const Id& message_id, const Message& new_message) -> Response
{
    if (auto iter = messages_.find(message_id);
        iter != messages_.end())
    {
        messages_.insert({message_id, WrappedMessage::Create(new_message, message_id)});

        return Response::CreateSuccess();
    }
    return Response::CreateError(L"Failed to find message with such ID");
}

auto History::Delete(const Id& message_id) -> Response
{
    messages_.erase(message_id);

    return Response::CreateSuccess();
}
auto History::GetMessages() const -> std::vector<WrappedMessage>
{
    std::vector<WrappedMessage> result;

    for (const auto& message : messages_)
    {
        result.push_back(message.second);
    }

    return {};
}

auto History::GetMessage(const Id& message_id) const -> std::optional<WrappedMessage>
{
    if (const auto& iter = messages_.find(message_id);
        iter != messages_.end())
    {
        return iter->second;
    }
    return {};
}
} // namespace Chat
