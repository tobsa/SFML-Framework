////////////////////////////////////////////////////////////////////////////////
// Filename: FileReader.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header
////////////////////////////////////////////////////////////////////////////////
#include "FileReader.hpp"
#include "Log.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
FileReader::FileReader()
{
}

////////////////////////////////////////////////////////////////////////////////
FileReader::FileReader(const std::string& filename, bool createNew) :
    m_file (filename)
{
    if(!isOpen())
    {
        // Force create new
        if(createNew)
        {
            std::ofstream file(filename);
            open(filename);
        }
        else 
            sfx::Log::write("Error (FileReader::FileReader()): Couldn't open " + filename);
    }
}

////////////////////////////////////////////////////////////////////////////////
void FileReader::open(const std::string& filename, bool createNew)
{
    if(isOpen())
        close();

    m_file.open(filename);

    if(!isOpen())
    {
        // Force create a new file
        if(createNew)
        {
            std::ofstream file(filename);
            open(filename);
        }
        else 
            sfx::Log::write("Error (FileReader::FileReader()): Couldn't open " + filename);
    }
}

////////////////////////////////////////////////////////////////////////////////
bool FileReader::isOpen() const
{
    return m_file.is_open();
}

////////////////////////////////////////////////////////////////////////////////
void FileReader::close()
{
    m_file.close();
}

////////////////////////////////////////////////////////////////////////////////
bool FileReader::available()
{
    return !(m_file.peek() == std::ifstream::traits_type::eof());
}

////////////////////////////////////////////////////////////////////////////////
std::string FileReader::getFile()
{
    std::string line;

    while(available())
        line += get();

    return line.substr(0, line.size() - 1);
}

////////////////////////////////////////////////////////////////////////////////
std::string FileReader::getLine()
{
    if(!isOpen())
    {
        std::string error = "Error (FileReader::getLine()): FileReader isn't open";
        sfx::Log::write(error);
        throw error;
    }

    std::string line;
    std::getline(m_file, line);

    return line;
}
    
////////////////////////////////////////////////////////////////////////////////
char FileReader::get()
{
    if(!isOpen())
    {
        std::string error = "Error (FileReader::get()): FileReader isn't open";
        sfx::Log::write(error);
        throw error;
    }

    return m_file.get();
}

} // namespace sfx