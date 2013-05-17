////////////////////////////////////////////////////////////////////////////////
// Filename: Utility.inl
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Utility.hpp"
#include <sstream>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
template<class T> T convert(const std::string& str)
{
    std::istringstream is(str);
    T number;

    is >> number;

    return number;
}

////////////////////////////////////////////////////////////////////////////////
template<class T> std::string convert(T number)
{
    std::ostringstream os;
    os << number;
    return os.str();
}

////////////////////////////////////////////////////////////////////////////////
template<class T> T clamp(T value, T min, T max)
{
    if(value < min) return min;
    if(value > max) return max;

    return value;
}

////////////////////////////////////////////////////////////////////////////////
template<class T> T wrap(T value, T min, T max)
{
    if(value < min) return max;
    if(value > max) return min;

    return value;
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> T advance(T& iterator, std::size_t offset)
{
    std::advance(iterator, offset);
    return iterator;
}

} // namespace sfx
