
#pragma once

class Request
{
public:
    enum class Type;

public:
    Type type() const { return type_; };

private:
    Type type_;
};

enum class Request::Type
{
    Get,
    Post,
    Put,
    Delete,
    Patch
};
