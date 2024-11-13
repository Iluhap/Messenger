
#pragma once

#include <memory>

#include "RequestHandler.h"
#include "Vault.h"


class RequestHandlerImpl : public RequestHandler
{
public:
    void handleGet(Request& request, Response& response) override;
    void handlePost(Request& request, Response& response) override;
    void handlePut(Request& request, Response& response) override;
    void handleDelete(Request& request, Response& response) override;
    void handlePatch(Request& request, Response& response) override;

private:


private:
    std::unique_ptr<Chat::Vault> vault_;
};
