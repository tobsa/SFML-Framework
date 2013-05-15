////////////////////////////////////////////////////////////////////////////////
// Filename: FileWriter.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "FileWriter.hpp"
#include "Log.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
FileWriter::FileWriter(const std::string& filename, Mode mode)
{
    open(filename, mode);    
}

////////////////////////////////////////////////////////////////////////////////
void FileWriter::open(const std::string& filename, Mode mode)
{
    if(mode == Clear)
        m_file.open(filename);
    else 
        m_file.open(filename, std::ofstream::app);

    if(!m_file.is_open())
        sfx::Log::write("Error (FileWriter::FileWrite()): Couldn't open " + filename); 
}

////////////////////////////////////////////////////////////////////////////////
void FileWriter::close()
{
    m_file.close();
}

////////////////////////////////////////////////////////////////////////////////
bool FileWriter::isOpen() const
{
    return m_file.is_open();
}

////////////////////////////////////////////////////////////////////////////////
std::ostream& FileWriter::write()
{
    return m_file;
}

////////////////////////////////////////////////////////////////////////////////
void FileWriter::flush()
{
    m_file.flush();
}

} // namespace sfx