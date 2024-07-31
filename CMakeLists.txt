cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(LibraryManagementSystem
    src/main.cpp
    src/Book.cpp
    src/User.cpp
    src/Admin.cpp
    src/Library.cpp
    src/Database.cpp
)
