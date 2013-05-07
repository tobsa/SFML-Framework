////////////////////////////////////////////////////////////////////////////////
// Filename: Main.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Disable deprecation warnings
////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Log.hpp"
#include <iostream>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////
// Static functions
////////////////////////////////////////////////////////////////////////////////
static const std::string getTime();

namespace sfx
{

std::ofstream Log::m_file;
std::string Log::m_logName = "Log.txt";

////////////////////////////////////////////////////////////////////////////////
void Log::open(const std::string& logName)
{
    // If the file is already open then close it first
    if(m_file.is_open())
        m_file.close();

    m_logName = logName;

    m_file.open(logName);

    if(!m_file.is_open())
        std::cout << "Failed to create " + logName;
}

////////////////////////////////////////////////////////////////////////////////
void Log::close()
{
    m_file.close();
}

////////////////////////////////////////////////////////////////////////////////
void Log::write(const std::string& text)
{
    if(!m_file.is_open())
        open(m_logName);

    std::cout << getTime() << " : " << text << std::endl;
    m_file    << getTime() << " : " << text << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
void Log::setLogName(const std::string& logName)
{
    m_logName = logName;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Log::getLogName()
{
    return m_logName;
}

} // namespace sfx

////////////////////////////////////////////////////////////////////////////////
const std::string getTime()
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime (buffer, 80, "%Y-%m-%d:%X", timeinfo);

    return buffer;
}