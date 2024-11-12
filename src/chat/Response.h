
#pragma once

#include "History.h"


namespace Chat {

class Response
{
public:
    enum class Status
    {
        Success,
        Error
    };

public:
    static Response CreateSuccess();
    static Response CreateError(const std::optional<std::wstring>& error_message = {});
    static Response Create(const Status& status,
                           const std::optional<std::wstring>& error_message = {});

private:
    Response(const Status& status, const std::optional<std::wstring>& error_message);

public:
    auto type() const { return status_; };
    auto error_message() const { return error_message_; };
    auto is_error() const { return status_ == Status::Error; }

private:
    Status status_;
    std::optional<std::wstring> error_message_;
};

} // namespace Chat
