
#include "Vault.h"
#include "Response.h"


namespace Chat {

auto Vault::AddChat(const std::vector<User>& users) -> Response
{
    auto chat_id = Id::Create();

    for (const auto& user : users)
    {
        AddChatForUser(user, chat_id);
    }

    chats_.insert({chat_id, std::make_unique<History>()});

    return Response::CreateSuccess();
}

auto Vault::AddMessage(const User& user,
                       const Id& chat_id,
                       const Message& message) -> Response
{
    if (not IsSender(user, message))
        return Response::CreateError(L"Failed to add message chat: User is not a sender of message");

    if (auto iter = chats_.find(chat_id);
        iter != chats_.end())
    {
        auto& chat = iter->second;
        chat->Add(message);

        return Response::CreateSuccess();
    }

    return Response::CreateError(L"Failed to add message chat: Chat doesn't exist");
}

auto Vault::EditMessage(const User& user,
                        const Id& chat_id,
                        const Id& message_to_edit,
                        const Message& new_message) -> Response
{
    if (not IsSender(user, new_message))
        return Response::CreateError(L"Failed to edit message chat: User is not a sender of message");

    if (auto iter = chats_.find(chat_id);
        iter != chats_.end())
    {
        auto& chat = iter->second;
        return chat->Edit(message_to_edit, new_message);
    }

    return Response::CreateError(L"Failed to edit message chat: Chat doesn't exist");
}

auto Vault::DeleteMessage(const User& user,
                          const Id& chat_id,
                          const Id& message_to_delete) -> Response
{
    if (not IsSender(user, chat_id, message_to_delete))
        return Response::CreateError(L"Failed to edit message chat: User is not a sender of message");

    if (auto iter = chats_.find(chat_id);
        iter != chats_.end())
    {
        auto& chat = iter->second;
        return chat->Delete(message_to_delete);
    }

    return Response::CreateError(L"Failed to delete message chat: Chat doesn't exist");
}

auto Vault::GetChats(const User& user) -> std::optional<std::set<Id>>
{
    if (auto iter = user_chats_.find(user.id);
        iter != user_chats_.end())
    {
        return iter->second;
    }
    return {};
}

auto Vault::GetChatHistory(const User& user, const Id& chat_id) const -> std::optional<History>
{
    if (not ChatBelongs(user, chat_id))
        return {};

    if (auto iter = chats_.find(chat_id);
        iter != chats_.end())
    {
        return *iter->second;
    }
    return {};
}

void Vault::AddChatForUser(const User& user, const Id& chat_id)
{
    if (auto iter = user_chats_.find(user.id);
        iter != user_chats_.end())
    {
        iter->second.insert(chat_id);
    }
}

auto Vault::ChatBelongs(const User& user, const Id& chat_id) const -> bool
{
    if (const auto& iter = user_chats_.find(user.id);
        iter != user_chats_.end())
    {
        return iter->second.contains(chat_id);
    }
    return false;
}
auto Vault::IsSender(const User& user, const Message& message) const -> bool
{
    return user == message.sender;
}

auto Vault::IsSender(const User& user, const Id& chat_id, const Id& message_id) const -> bool
{
    if (auto iter = chats_.find(chat_id);
        iter != chats_.end())
    {
        if (const auto& message = iter->second->GetMessage(message_id); message.has_value())
        {
            return user == message->message().sender;
        }
    }
    return false;
}
} // namespace Chat
