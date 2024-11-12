
#include "Vault.h"
#include "Response.h"


namespace Chat {

auto Vault::AddChat(const User& first, const User& second) -> Response
{
    auto chat_id = Id::Create();

    AddChatForUser(first, chat_id);
    AddChatForUser(second, chat_id);

    chats_.insert({chat_id, std::make_unique<History>()});

    return Response::CreateSuccess();
}

auto Vault::AddMessageTo(const Id& chat_id, const Message& message) -> Response
{
    if (auto iter = chats_.find(chat_id);
        iter != chats_.end())
    {
        auto& chat = iter->second;
        chat->Add(message);

        return Response::CreateSuccess();
    }

    return Response::CreateError();
}

auto Vault::EditMessage(const Id& chat_id, const Id& message_to_edit, const Message& new_message) -> Response
{
    if (auto iter = chats_.find(chat_id);
        iter != chats_.end())
    {
        auto& chat = iter->second;
        return chat->Edit(message_to_edit, new_message);
    }

    return Response::CreateError();
}

auto Vault::DeleteMessage(const Id& chat_id, const Id& message_to_delete) -> Response
{
    if (auto iter = chats_.find(chat_id);
        iter != chats_.end())
    {
        auto& chat = iter->second;
        return chat->Delete(message_to_delete);
    }

    return Response::CreateError();
}

auto Vault::GetChatsOf(const User& user) -> std::optional<std::set<Id>>
{
    if (auto iter = user_chats_.find(user.id);
        iter != user_chats_.end())
    {
        return iter->second;
    }
    return {};
}

auto Vault::GetHistory(const Id& chat_id) const -> std::optional<History>
{
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

} // namespace Chat