
#include "Response.h"


namespace Chat {

Response Chat::Response::Create(const Chat::Response::Status& type,
                                const std::optional<std::wstring>& error_message)
{
    return Response {type, error_message};
}
Response::Response(const Chat::Response::Status& status,
                   const std::optional<std::wstring>& error_message)
    :
    status_(status),
    error_message_(error_message)
{
}
Response Response::CreateSuccess()
{
    return {Status::Success, {}};
}
Response Response::CreateError(const std::optional<std::wstring>& error_message)
{
    return {Status::Error, error_message};
}

}
