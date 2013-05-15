////////////////////////////////////////////////////////////////////////////////
// Filename: Polygon.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Polygon.hpp"
#include "../Utility/Log.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Polygon::Polygon(std::size_t size)
{
    m_vertices.resize(size);
}

////////////////////////////////////////////////////////////////////////////////
void Polygon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(m_vertices.isEmpty())
        return;

    target.draw(&m_vertices[0], m_vertices.getSize(), sf::TrianglesFan, states);
}

////////////////////////////////////////////////////////////////////////////////
bool Polygon::contains(const sf::Vector2f& position) const
{
    bool inside = false;
    std::size_t j = m_vertices.getSize() - 1;

    for(std::size_t i = 0; i < m_vertices.getSize(); ++i)
    {
        float x0 = m_vertices[i].position.x;
        float x1 = m_vertices[j].position.x;
        float y0 = m_vertices[i].position.y;
        float y1 = m_vertices[j].position.y;

        if((y0 < position.y && y1 >= position.y  || y1 < position.y && y0 >= position.y) && (x0 <= position.x || x1 <= position.x))
            inside ^= (x0 + (position.y - y0) / (y1 - y0) * (x1 - x0) < position.x);

        j = i;
    }

    return inside;
}

////////////////////////////////////////////////////////////////////////////////
bool Polygon::contains(float x, float y) const
{
    return true;
}

////////////////////////////////////////////////////////////////////////////////
void Polygon::addPoint(const sf::Vector2f& position, const sf::Color& color)
{
    m_vertices.addBack(sf::Vertex(position, color));
}

////////////////////////////////////////////////////////////////////////////////
void Polygon::addPoint(float x, float y, const sf::Color& color)
{
    m_vertices.addBack(sf::Vertex(sf::Vector2f(x, y), color));
}

////////////////////////////////////////////////////////////////////////////////
std::size_t Polygon::getSize() const
{
    return m_vertices.getSize();
}

////////////////////////////////////////////////////////////////////////////////
const sf::Vertex& Polygon::getPoint(std::size_t index) const
{
    if(index < 0 || index >= getSize())
        sfx::Log::writeT("Error (Polygon::getPoint()): Index " + sfx::convert(index) + " is out of bounds");

    return m_vertices[index];
}

////////////////////////////////////////////////////////////////////////////////
const sf::Vector2f& Polygon::getPosition(std::size_t index) const
{
    if(index < 0 || index >= getSize())
        sfx::Log::writeT("Error (Polygon::getPosition()): Index " + sfx::convert(index) + " is out of bounds");

    return m_vertices[index].position;
}

////////////////////////////////////////////////////////////////////////////////
const sf::Color& Polygon::getColor(std::size_t index) const
{
    if(index < 0 || index >= getSize())
        sfx::Log::writeT("Error (Polygon::getColor()): Index " + sfx::convert(index) + " is out of bounds");

    return m_vertices[index].color;
}

////////////////////////////////////////////////////////////////////////////////
void Polygon::setPosition(std::size_t index, const sf::Vector2f& position)
{
    if(index < 0 || index >= getSize())
        return;

    m_vertices[index].position = position;
}

////////////////////////////////////////////////////////////////////////////////
void Polygon::setPosition(std::size_t index, float x, float y)
{
    if(index < 0 || index >= getSize())
        return;

    m_vertices[index].position = sf::Vector2f(x, y);
}

////////////////////////////////////////////////////////////////////////////////
void Polygon::setColor(const sf::Color& color)
{
    for(auto& vertex : m_vertices)
        vertex.color = color;
}

////////////////////////////////////////////////////////////////////////////////
void Polygon::setColor(std::size_t index, const sf::Color& color)
{
    if(index < 0 || index >= getSize())
        return;

    m_vertices[index].color = color;
}

////////////////////////////////////////////////////////////////////////////////
void Polygon::remove(std::size_t index)
{
    m_vertices.remove(index);
}

} // namespace sfx
