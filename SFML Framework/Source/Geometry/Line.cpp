////////////////////////////////////////////////////////////////////////////////
// Filename: Line.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Line.hpp"
#include "../Utility/Log.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Line::Line(const sf::Vector2f& position0, const sf::Vector2f& position1, const sf::Color& color) :
    m_threshold (10.f)
{
    m_vertices.addBack(sf::Vertex(position0, color));
    m_vertices.addBack(sf::Vertex(position1, color));
}

////////////////////////////////////////////////////////////////////////////////
Line::Line(float x0, float y0, float x1, float y1, const sf::Color& color) :
    m_threshold (10.f)
{
    m_vertices.addBack(sf::Vertex(sf::Vector2f(x0, y0), color));
    m_vertices.addBack(sf::Vertex(sf::Vector2f(x1, y1), color));
}

////////////////////////////////////////////////////////////////////////////////
void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(&m_vertices[0], m_vertices.getSize(), sf::Lines, states);
}

////////////////////////////////////////////////////////////////////////////////
bool Line::contains(const sf::Vector2f& position) const
{
    return contains(position.x, position.y);
}

////////////////////////////////////////////////////////////////////////////////
bool Line::contains(float x, float y) const
{
    float x0 = m_vertices[0].position.x;
    float y0 = m_vertices[0].position.y;
    float x1 = m_vertices[1].position.x;
    float y1 = m_vertices[1].position.y;

    float slope     = (y1 - y0) / (x1 - x0);
    float intercept = (y0 - slope * x0);

    float minX = x0 < x1 ? x0 : x1;
    float maxX = x0 < x1 ? x1 : x0;
    float minY = y0 < y1 ? y0 : y1;
    float maxY = y0 < y1 ? y1 : y0;

    if(slope * x + intercept > (y - m_threshold) && slope * x + intercept < (y + m_threshold))
    {
        if(x >= minX && x <= maxX && y >= minY && y <= maxY)
        {
            return true;
        }
    }

    return false;
}

////////////////////////////////////////////////////////////////////////////////
const sf::Vector2f& Line::getPosition(std::size_t index) const
{
    if(index < 0 || index > 1)
        sfx::Log::writeT("Error (Line::getPosition()): Index " + sfx::convert(index) + " is out of bounds");

    return m_vertices[index].position;
}

////////////////////////////////////////////////////////////////////////////////
const sf::Color& Line::getColor(std::size_t index) const
{
    if(index < 0 || index > 1)
        sfx::Log::writeT("Error (Line::getColor()): Index " + sfx::convert(index) + " is out of bounds");

    return m_vertices[index].color;
}

////////////////////////////////////////////////////////////////////////////////
void Line::setPosition(std::size_t index, const sf::Vector2f& position)
{
    if(index < 0 || index > 1)
        return;

    m_vertices[index].position = position;
}

////////////////////////////////////////////////////////////////////////////////
void Line::setPosition(std::size_t index, float x, float y)
{
    setPosition(index, sf::Vector2f(x, y));
}

////////////////////////////////////////////////////////////////////////////////
void Line::setColor(std::size_t index, const sf::Color& color)
{
    if(index < 0 || index > 1)
        return;

    m_vertices[index].color = color;
}

////////////////////////////////////////////////////////////////////////////////
float Line::getThreshold() const
{
    return m_threshold;
}

////////////////////////////////////////////////////////////////////////////////
void Line::setThreshold(float threshold)
{
    m_threshold = threshold;
}

} // namespace sfx
