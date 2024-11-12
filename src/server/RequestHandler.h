
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


