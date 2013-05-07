////////////////////////////////////////////////////////////////////////////////
// Filename: Config.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////#
#include "Config.hpp"
#include "Scanner.hpp"
#include "FileReader.hpp"
#include "Utility.hpp"
#include <fstream>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Config::Config(const std::string& filename) :
    m_filename (filename)
{
    sfx::FileReader fileReader(filename);
    sfx::Scanner scanner(fileReader.getFile());

    while(scanner.hasToken())
    {
        std::string token = scanner.getToken();

        // Keep reading tokens until we encountered a section
        if(token != "[") 
            continue; 

        token = scanner.getToken(); // Read section name
        scanner.getToken();         // Discard "]"

        SectionPtr section = std::make_shared<Section>(token);

        // Read the keys under each section
        while(scanner.hasToken())
        {
            std::string key   = scanner.getToken(); // Read key
            scanner.getToken();                     // Discard "="-sign
            std::string value = scanner.getToken(); // Read value

            // Handle float type
            if(scanner.peekToken() == ".")
            {
                value += scanner.getToken();
                value += scanner.getToken();
                section->m_floats.push_back(KeyValue<float>(key, sfx::convert<float>(value)));
            }
            else if(value == "\"") // Handle string type
            {
                value = scanner.getToken();
                scanner.getToken();
                section->m_strings.push_back(KeyValue<std::string>(key, value));
            }
            else // Handle integer
                section->m_integers.push_back(KeyValue<int>(key, sfx::convert<int>(value)));

            if(scanner.peekToken() == "[" || scanner.peekToken() == "")
                break;
        }

        m_sections.push_back(section);
    }
}

////////////////////////////////////////////////////////////////////////////////
int Config::getInteger(const std::string& sectionName, const std::string& key, int defaultValue)
{
    // Check if the section exist
    SectionPtr section = findSection(sectionName);
    if(!section)
        return defaultValue;

    // Check if the key exist
    auto result = std::find(section->m_integers.begin(), section->m_integers.end(), KeyValue<int>(key, defaultValue));
    if(result == section->m_integers.end())
        return defaultValue;

    return result->m_value;
}

////////////////////////////////////////////////////////////////////////////////
float Config::getFloat(const std::string& sectionName, const std::string& key, float defaultValue)
{
    // Check if the section exist
    SectionPtr section = findSection(sectionName);
    if(!section)
        return defaultValue;

    // Check if the key exist
    auto result = std::find(section->m_floats.begin(), section->m_floats.end(), KeyValue<float>(key, defaultValue));
    if(result == section->m_floats.end())
        return defaultValue;

    return result->m_value;
}

////////////////////////////////////////////////////////////////////////////////
std::string Config::getString(const std::string& sectionName, const std::string& key, const std::string& defaultValue)
{
    // Check if the section exist
    SectionPtr section = findSection(sectionName);
    if(!section)
        return defaultValue;

    // Check if the key exist
    auto result = std::find(section->m_strings.begin(), section->m_strings.end(), KeyValue<std::string>(key, defaultValue));
    if(result == section->m_strings.end())
        return defaultValue;

    return result->m_value;
}

////////////////////////////////////////////////////////////////////////////////
void Config::setInteger(const std::string& sectionName, const std::string& key, int value)
{
    SectionPtr section = findSection(sectionName);
    if(!section)
    {
        section = std::make_shared<Section>(sectionName);
        section->m_integers.push_back(KeyValue<int>(key, value));

        m_sections.push_back(section);
    }
    else
    {
        // Add the key to the section if it doens't exist
        std::size_t index = findKey(section, key);
        if(index == -1)
            section->m_integers.push_back(KeyValue<int>(key, value));
        else 
            // If it exist then simply update the value
            section->m_integers[index].m_value = value;
    }

    save();
}

////////////////////////////////////////////////////////////////////////////////
void Config::setFloat(const std::string& sectionName, const std::string& key, float value)
{
    SectionPtr section = findSection(sectionName);
    if(!section)
    {
        section = std::make_shared<Section>(sectionName);
        section->m_floats.push_back(KeyValue<float>(key, value));

        m_sections.push_back(section);
    }
    else
    {
        // Add the key to the section if it doens't exist
        std::size_t index = findKey(section, key);
        if(index == -1)
            section->m_floats.push_back(KeyValue<float>(key, value));
        else 
            // If it exist then simply update the value
            section->m_floats[index].m_value = value;
    }

    save();
}

////////////////////////////////////////////////////////////////////////////////
void Config::setString(const std::string& sectionName, const std::string& key, const std::string& value)
{
    SectionPtr section = findSection(sectionName);
    if(!section)
    {
        section = std::make_shared<Section>(sectionName);
        section->m_strings.push_back(KeyValue<std::string>(key, value));

        m_sections.push_back(section);
    }
    else
    {
        // Add the key to the section if it doens't exist
        std::size_t index = findKey(section, key);
        if(index == -1)
            section->m_strings.push_back(KeyValue<std::string>(key, value));
        else 
            // If it exist then simply update the value
            section->m_strings[index].m_value = value;
    }

    save();
}

////////////////////////////////////////////////////////////////////////////////
Config::SectionPtr Config::findSection(const std::string& sectionName)
{
    for(const auto& section : m_sections)
    {
        if(section->m_key == sectionName)
            return section;
    }
    
    return nullptr;
}

////////////////////////////////////////////////////////////////////////////////
std::size_t Config::findKey(SectionPtr section, const std::string& key)
{
    // Check against integers
    for(std::size_t i = 0; i < section->m_integers.size(); ++i)
    {
        if(section->m_integers[i].m_key == key)
            return i;
    }

    // Check against floats
    for(std::size_t i = 0; i < section->m_floats.size(); ++i)
    {
        if(section->m_floats[i].m_key == key)
            return i;
    }

    // Check against strings
    for(std::size_t i = 0; i < section->m_strings.size(); ++i)
    {
        if(section->m_strings[i].m_key == key)
            return i;
    }

    return -1;
}

////////////////////////////////////////////////////////////////////////////////
void Config::save()
{
    std::ofstream file(m_filename);

    // Loop trough all sections and save their information to the config file
    for(const auto& section : m_sections)
    {
        file << "[" << section->m_key << "]" << std::endl << "\t";

        for(const auto& i : section->m_integers)
            file << i.m_key << " = " << i.m_value << std::endl << "\t";
        for(const auto& i : section->m_floats)
            file << i.m_key << " = " << i.m_value << std::endl << "\t";
        for(const auto& i : section->m_strings)
            file << i.m_key << " = \"" << i.m_value << "\"" << std::endl << "\t";

        file << std::endl;
    }
}

} // namespace sfx