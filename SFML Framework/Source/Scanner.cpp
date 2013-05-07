////////////////////////////////////////////////////////////////////////////////
// Filename: Scanner.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////////////////////////
#include "Scanner.hpp"
#include <cctype>

////////////////////////////////////////////////////////////////////////////////
Scanner::Scanner(const std::string& str) :
	m_string (str)
{
}

////////////////////////////////////////////////////////////////////////////////
std::string Scanner::getToken()
{
	// If there's no tokens then return an empty string
	if(!hasToken())
		return "";

	// The current character position
	std::size_t current	= 0;

	// Skip spaces
	if(current < m_string.size())
	{
		while(isspace(m_string[current]))
		{
			current++;
			if(current == m_string.size())
				break;
		}
	}

	m_string = m_string.substr(current,m_string.size() - current);
	current  = 0;

	// If the current character is a number
	if(isdigit(m_string[current]))
	{
		// Loop until the next non-number
		while(isdigit(m_string[current]))
		{
			current++;
			if(current == m_string.size())
				break;
		}
	}
	// If the current character is a letter
	else if(isalpha(m_string[current]))
	{
		// Loop until the next non-letter
		while(isalpha(m_string[current]))
		{
			current++;
			if(current == m_string.size())
				break;
		}
	}
	else
		current++;
	
	// Get the token
	std::string token = m_string.substr(0,current);

	// Skip spaces
	if(current < m_string.size())
	{
		while(isspace(m_string[current]))
		{
			current++;
			if(current == m_string.size())
				break;
		}
	}

	// Make sure the token is excluded from the string
	m_string = m_string.substr(current,m_string.size() - current);

	return token;
}

////////////////////////////////////////////////////////////////////////////////
std::string Scanner::peekToken()
{
	std::string token = getToken();
	saveToken(token);
	return token;
}

////////////////////////////////////////////////////////////////////////////////
void Scanner::saveToken(const std::string& token)
{
	if(token == "") 
		return;

	m_string = token + " " + m_string;
}

////////////////////////////////////////////////////////////////////////////////
bool Scanner::hasToken() const
{
	return !m_string.empty();
}