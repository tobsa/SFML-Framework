////////////////////////////////////////////////////////////////////////////////
// Filename: FileReader.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef FILE_READER_HPP
#define FILE_READER_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <string>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A simple class that simplyfies the task of reading from files
////////////////////////////////////////////////////////////////////////////////
class FileReader
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create a file reader object
    ////////////////////////////////////////////////////////////////////////////////
    FileReader(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////////
    // Open and close the file reader
    ////////////////////////////////////////////////////////////////////////////////
    void open(const std::string& filename);
    void close();

    ////////////////////////////////////////////////////////////////////////////////
    // Check if the file reader is open
    ////////////////////////////////////////////////////////////////////////////////
    bool isOpen() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Check if there's more to read from the file
    ////////////////////////////////////////////////////////////////////////////////
    bool available() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the whole file as a string
    ////////////////////////////////////////////////////////////////////////////////
    std::string getFile();

    ////////////////////////////////////////////////////////////////////////////////
    // Get the next line from the file
    ////////////////////////////////////////////////////////////////////////////////
    std::string getLine();
    
    ////////////////////////////////////////////////////////////////////////////////
    // Get the next letter from the file
    ////////////////////////////////////////////////////////////////////////////////
    char get();

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    std::ifstream m_file;
};

} // namespace sfx

#endif