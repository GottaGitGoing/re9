#ifndef FILEEXCEPTION_HPP
#define FILEEXCEPTION_HPP

#include <stdexcept>



class FileException : public std::runtime_error
{
public:
    explicit FileException(const std::string& reason)
        : std::runtime_error{reason}
    {
    }
};



#endif

