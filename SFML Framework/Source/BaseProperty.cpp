////////////////////////////////////////////////////////////////////////////////
// Filename: BaseProperty.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "BaseProperty.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
BaseProperty::BaseProperty()
{
}

////////////////////////////////////////////////////////////////////////////////
BaseProperty::BaseProperty(const std::string& type) :
    m_type (type)
{
}

////////////////////////////////////////////////////////////////////////////////
BaseProperty::~BaseProperty()
{
}

////////////////////////////////////////////////////////////////////////////////
const std::string& BaseProperty::getType() const
{
    return m_type;
}

////////////////////////////////////////////////////////////////////////////////
void BaseProperty::setType(const std::string& type)
{
    m_type = type;
}

} // namespace sfx