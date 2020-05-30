#ifndef PROBLEM2_HPP
#define PROBLEM2_HPP

#include <functional>
#include <fstream>
#include <iostream>
#include "FileException.hpp"



template <typename LineType>
class TextLineReader
{
public:
    using LineParser = std::function<LineType(const std::string&)>;

public:
    TextLineReader(const std::string& filePath, LineParser lineParser);
    ~TextLineReader();

    TextLineReader(const TextLineReader& other) = delete;
    TextLineReader& operator=(const TextLineReader& other) = delete;

    bool hasNextLine() const;
    LineType nextLine();

    // int current_line;

private:
LineParser lineParser_;
std::string filePath_;
std::ifstream in_file;

};


template <typename LineType>
TextLineReader<LineType>::TextLineReader(const std::string& filePath, 
                                         LineParser lineParser)
    : lineParser_{lineParser}, filePath_{filePath}
{
    in_file.open(filePath_);
}


template <typename LineType>
TextLineReader<LineType>::~TextLineReader()
{
    in_file.close();
}


template <typename LineType>
bool TextLineReader<LineType>::hasNextLine() const
{
    return in_file.eof();
}


template <typename LineType>
LineType TextLineReader<LineType>::nextLine()
{
    
    int num = 0;
    std::cin >> num;
    // std::getline(in_file,current_line);
    return num;
}


#endif

