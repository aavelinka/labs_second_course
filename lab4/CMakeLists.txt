cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(SOURCES
    exceptions/src/InputValidator.cpp
    src/Person.cpp
    src/Employer.cpp
    src/Tourist.cpp
    src/Dealer.cpp
    main.cpp
)

set(HEADERS
    algoritm/Algorithm.h
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

add_executable(lab4 ${SOURCES} ${HEADERS})