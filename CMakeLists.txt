cmake_minimum_required(VERSION 3.28)
project(cpp_module_00)

set(CMAKE_CXX_STANDARD 98)

add_executable(megaphone ex00/megaphone.cpp)

add_executable(phonebook
        ex01/main.cpp
        ex01/PhoneBook.cpp
        ex01/PhoneBook.hpp
        ex01/Contact.cpp
        ex01/Contact.hpp)

add_executable(dream
        ex02/tests.cpp
        ex02/Account.cpp
        ex02/Account.hpp)
