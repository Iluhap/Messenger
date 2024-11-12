
#include "Id.h"
#include <boost/uuid/uuid_generators.hpp>


Id Id::Create()
{
    auto uuid = boost::uuids::random_generator()();
    return Id(uuid);
}

Id::Id(const boost::uuids::uuid& uuid)
    :
    uuid_(uuid)
{
}
