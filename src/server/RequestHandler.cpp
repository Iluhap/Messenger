
#include "RequestHandler.h"


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
