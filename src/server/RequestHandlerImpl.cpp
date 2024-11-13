
#include "RequestHandlerImpl.h"


void RequestHandlerImpl::handleGet(Request& request, Response& response)
{
    if (auto payload = MakeGetChatsFrom(request.payload());
        payload.has_value())
    {
        response = Response::MakeFrom(vault_->GetChat(payload.user()));
        return;
    }

    if (auto payload = MakeGetChatHistoryFrom(request.payload());
        payload.has_value())
    {
        response = Response::MakeFrom(AddMessage->GetChatHistory(payload.user(), payload.chat_id()));
        return;
    }
}
void RequestHandlerImpl::handlePost(Request& request, Response& response)
{
    if (auto payload = MakeAddChatFrom(request.payload());
        payload.has_value())
    {
        response = Response::MakeFrom(vault_->AddChat(payload.users()));
        return;
    }

    if (auto payload = MakeAddMessageFrom(request.payload());
        payload.has_value())
    {
        response = Response::MakeFrom(AddMessage->AddChat(payload.user(), payload.chat_id(), paload.message()));
        return;
    }
}
void RequestHandlerImpl::handlePut(Request& request, Response& response)
{
    if (auto payload = MakeEditMessageFrom(request.payload());
        payload.has_value())
    {
        response = Response::MakeFrom(vault_->EditMessage(payload.user(), payload.chat_id(), payload.message()));
        return;
    }
}
void RequestHandlerImpl::handleDelete(Request& request, Response& response)
{
    if (auto payload = MakeDeleteMessageFrom(request.payload());
        payload.has_value())
    {
        response = Response::MakeFrom(vault_->EditMessage(payload.user(), payload.chat_id(), payload.message()));
        return;
    }
}
void RequestHandlerImpl::handlePatch(Request& request, Response& response)
{
    // TODO
}
