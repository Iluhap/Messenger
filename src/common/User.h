
#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "Id.h"


struct User
{
    std::wstring name;
    std::wstring surname;

    Id id;

    bool operator==(const User& other) const noexcept
    {
        return name == other.name
            and surname == other.surname
            and id == other.id;
    }
};


