
#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>


class Id
{
public:
    static Id Create();

    Id(const Id& other) = default;
    Id(Id&& other) = default;

private:
    explicit Id(const boost::uuids::uuid& uuid);

public:
    auto uuid() const { return uuid_; };

    bool operator==(const Id& other) const { return uuid_ == other.uuid_; }

private:
    boost::uuids::uuid uuid_;
};

template<>
struct std::hash<Id>
{
    std::size_t operator()(const Id& id) const noexcept
    {
        const auto& hash = std::hash<std::string> {};
        return hash(boost::uuids::to_string(id.uuid()));
    }
};

template<>
struct std::less<Id>
{
    bool operator()(const Id& left, const Id& right) const noexcept
    {
        const auto& hash = std::hash<Id> {};
        return hash(left) < hash(right);
    }
};
