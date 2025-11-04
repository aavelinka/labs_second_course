cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(SOURCES
    src/Person.cpp
    src/Employer.cpp
    src/Tourist.cpp
    src/Dealer.cpp
    main.cpp
)

set(HEADERS
    include/Person.h
    include/Employer.h
    include/Tourist.h
    include/Dealer.h
)

add_executable(lab3 ${SOURCES} ${HEADERS})