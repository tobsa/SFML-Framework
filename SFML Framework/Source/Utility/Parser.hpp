////////////////////////////////////////////////////////////////////////////////
// Filename: Parser.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_PARSER_HPP
#define SFX_PARSER_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <string>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// An parser that can read tokens from a string
////////////////////////////////////////////////////////////////////////////////
class Parser
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Constructor
    ////////////////////////////////////////////////////////////////////////////////
    Parser(const std::string& str, const std::string& seperators = " ");

    ////////////////////////////////////////////////////////////////////////////////
    // Get the next  token, peek at the next token (read without consume it),
    // get the total string and get all seperators
    ////////////////////////////////////////////////////////////////////////////////
    std::string getToken();
    std::string peekToken();
    const std::string& getString() const;
    const std::string& getSeperators() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Save a token to the beginning of the string, set a new string, set all 
    // seperators and add a new seperator
    ////////////////////////////////////////////////////////////////////////////////
    void saveToken(const std::string& token);
    void setString(const std::string& str);
    void setSeperators(const std::string& seperators);
    void addSeperator(const std::string& seperator);

    ////////////////////////////////////////////////////////////////////////////////
    // Check if there's more tokens to read
    ////////////////////////////////////////////////////////////////////////////////
    bool hasToken() const;

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    std::string m_string;
    std::string m_seperators;
};

} // namespace sfx

#endif