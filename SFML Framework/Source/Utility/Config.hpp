////////////////////////////////////////////////////////////////////////////////
// Filename: Config.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef CONFIG_HPP
#define CONFIG_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "../Containers/Vector.hpp"
#include <string>
#include <memory>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A simple ini config file reader and writer
////////////////////////////////////////////////////////////////////////////////
class Config 
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create a config file class
    ////////////////////////////////////////////////////////////////////////////////
    Config(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////////
    // Read an integer from the config file
    ////////////////////////////////////////////////////////////////////////////////
    int getInteger(const std::string& sectionName, const std::string& key, int defaultValue);

    ////////////////////////////////////////////////////////////////////////////////
    // Read a float from the config file
    ////////////////////////////////////////////////////////////////////////////////
    float getFloat(const std::string& sectionName, const std::string& key, float defaultValue);

    ////////////////////////////////////////////////////////////////////////////////
    // Read a string from the config file
    ////////////////////////////////////////////////////////////////////////////////
    std::string getString(const std::string& sectionName, const std::string& key, const std::string& defaultValue);

    ////////////////////////////////////////////////////////////////////////////////
    // Set a new integer
    ////////////////////////////////////////////////////////////////////////////////
    void setInteger(const std::string& sectionName, const std::string& key, int value);

    ////////////////////////////////////////////////////////////////////////////////
    // Set a float
    ////////////////////////////////////////////////////////////////////////////////
    void setFloat(const std::string& sectionName, const std::string& key, float value);

    ////////////////////////////////////////////////////////////////////////////////
    // Set a new string
    ////////////////////////////////////////////////////////////////////////////////
    void setString(const std::string& sectionName, const std::string& key, const std::string& value);

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    struct Section;
    typedef std::shared_ptr<Section>  SectionPtr;
    typedef sfx::Vector<SectionPtr>   Sections;

    ////////////////////////////////////////////////////////////////////////////////
    // Represent a pair of key and value
    ////////////////////////////////////////////////////////////////////////////////
    template<class T> struct KeyValue
    {
        KeyValue(const std::string& key, const T& value) :
            m_key   (key),
            m_value (value)
        {
        }

        bool operator == (const KeyValue& value)
        {
            return m_key == value.m_key;
        }

        std::string m_key;
        T           m_value;
    };

    ////////////////////////////////////////////////////////////////////////////////
    // Represent a section
    ////////////////////////////////////////////////////////////////////////////////
    struct Section 
    {
        Section() {}

        Section(const std::string& key) :
            m_key (key)
        {
        }

        std::string                        m_key;
        sfx::Vector<KeyValue<int>>         m_integers;
        sfx::Vector<KeyValue<float>>       m_floats;
        sfx::Vector<KeyValue<std::string>> m_strings;
    };

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Find a section. If the section doesn't exist nullptr is returned.
    ////////////////////////////////////////////////////////////////////////////////
    SectionPtr findSection(const std::string& section);

    ////////////////////////////////////////////////////////////////////////////////
    // Check if a key exist in a section. Returns the index position or -1 if it
    // doesn't exist
    ////////////////////////////////////////////////////////////////////////////////
    std::size_t findKey(SectionPtr section, const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Save the stored information to the config file
    ////////////////////////////////////////////////////////////////////////////////
    void save();

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    std::string m_filename;
    Sections    m_sections;
};

} // namespace sfx

#endif