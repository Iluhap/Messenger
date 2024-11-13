
#pragma once

class Request
{
public:
    enum class Type
    {
        Get,
        Post,
        Put,
        Delete,
        Patch
    };

    struct Payload
    {
        // Contains different payload based on request type
        // e.g.
        void* data;
    };

public:
    Type type() const { return type_; };
    Payload payload() const { return payload_; };

private:
    Type type_;
    Payload payload_;
};
