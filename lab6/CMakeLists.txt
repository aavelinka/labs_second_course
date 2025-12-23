cmake_minimum_required(VERSION 3.10)
project(lab6)

set(CMAKE_CXX_STANDARD 20)

include_directories(include repo/include exceptions/include)

set(SOURCES
    exceptions/src/InputValidator.cpp
    Algorithm.cpp
    Algorithm.h
    src/Person.cpp
    src/Employer.cpp
    src/Tourist.cpp
    src/Dealer.cpp
    main.cpp
)

set(HEADERS
    exceptions/include/Exception.h
    exceptions/include/InputException.h
    exceptions/include/InputValidator.h
    include/Deque.tpp
    include/Deque.hpp
    include/Person.h
    include/Employer.h
    include/Tourist.h
    include/Dealer.h
)

add_executable(lab6 ${SOURCES} ${HEADERS})
