cmake_minimum_required(VERSION 3.26)

project(messenger)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS)

include_directories(
        "src"
        "src/common"
        "src/chat"
)

file(GLOB_RECURSE Server_SRCs CONFIGURE_DEPENDS
        "src/server.cpp"

        "src/common/*.h"
        "src/common/*.cpp"

        "src/chat/.h"
        "src/chat/.cpp"

        "src/server/*.h"
        "src/server/*.cpp"
)

add_executable(server
        ${Server_SRCs}
)

target_include_directories(server
        PUBLIC ${Boost_INCLUDE_DIRS}
)
