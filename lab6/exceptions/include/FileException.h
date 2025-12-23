#pragma once

#include <stdexcept>
#include <string>

class FileException : public std::runtime_error
{
public:
    explicit FileException(const string& message)
        : std::runtime_error(message)
    {
    }
};
