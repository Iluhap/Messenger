
#pragma once

#include <unordered_map>
#include <set>
#include <memory>

#include "Request.h"
#include "Response.h"
#include "History.h"
#include "Id.h"
#include "Response.h"


namespace Chat {

class Vault
{
public:
    auto AddChat(const User& first, const User& second) -> Response;

    auto AddMessageTo(const Id& chat_id, const Message& message) -> Response;
    auto EditMessage(const Id& chat_id, const Id& message_to_edit, const Message& new_message) -> Response;
    auto DeleteMessage(const Id& chat_id, const Id& message_to_delete) -> Response;

    auto GetChatsOf(const User& user) -> std::optional<std::set<Id>>;
    auto GetHistory(const Id& chat_id) const -> std::optional<History>;

private:
    void AddChatForUser(const User& user, const Id& chat_id);

private:
    std::unordered_map</*User*/ Id, /*Chat*/ std::set<Id>> user_chats_;
    std::unordered_map</*Chat*/ Id, std::unique_ptr<History>> chats_;
};

} // namespace Chat
