
#pragma once

#include "User.h"
#include "Message.h"
#include "Request.h"
#include "Response.h"


class RequestHandler
{
public:
    void handle(Request& request, Response& response);
    virtual void handleGet(Request& request, Response& response) = 0;
    virtual void handlePost(Request& request, Response& response) = 0;
    virtual void handlePut(Request& request, Response& response) = 0;
    virtual void handleDelete(Request& request, Response& response) = 0;
    virtual void handlePatch(Request& request, Response& response) = 0;
};

void RequestHandler::handle(Request& request, Response& response)
{
    switch (request.type())
    {
        case Request::Type::Get:
        {
            handleGet(request, response);
            return;
        }
        case Request::Type::Post:
        {
            handlePost(request, response);
            return;
        }
        case Request::Type::Put:
        {
            handlePut(request, response);
            return;
        }
        case Request::Type::Delete:
        {
            handleDelete(request, response);
            return;
        }
        case Request::Type::Patch:
        {
            handlePatch(request, response);
            return;
        }
        default: {}
    }
}
