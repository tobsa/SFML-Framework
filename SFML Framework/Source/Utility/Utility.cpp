////////////////////////////////////////////////////////////////////////////////
// Filename: Utility.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Utility.hpp"
#include <time.h>
#include <cstdlib>

namespace sfx
{

void initRandomGenerator()
{
    srand(time(0));
}

////////////////////////////////////////////////////////////////////////////////
float toDegree(float radians)
{
    return radians * 180.f / Pi;
}

////////////////////////////////////////////////////////////////////////////////
float toRadian(float degrees)
{
    return degrees * PiOver180;
}

////////////////////////////////////////////////////////////////////////////////
float getDistance(const sf::Vector2f& position0, const sf::Vector2f& position1)
{
    return getDistance(position0.x, position0.y, position1.x, position1.y);
}

////////////////////////////////////////////////////////////////////////////////
float getDistance(float x0, float y0, float x1, float y1)
{
    return std::sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
}

////////////////////////////////////////////////////////////////////////////////
float getAngle(const sf::Vector2f& position0, const sf::Vector2f& position1)
{
    return getAngle(position0.x, position0.y, position1.x, position1.y);
}

////////////////////////////////////////////////////////////////////////////////
float getAngle(float x0, float y0, float x1, float y1)
{
    return -toDegree(std::atan2(x1 - x0, y1 - y0));
}

////////////////////////////////////////////////////////////////////////////////
int getRandom(int begin, int end)
{
    return begin + rand()%(end-begin);
}

////////////////////////////////////////////////////////////////////////////////
float getRandom(float begin, float end)
{
    return begin + static_cast <float> (rand()) /( static_cast <float> (9999/(end-begin)));
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f getRandom(float begin0, float end0, float begin1, float end1)
{
    return sf::Vector2f(getRandom(begin0, end0), getRandom(begin1, end1));
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f getMouseMovedPosition(const sf::Event& event)
{
    return sf::Vector2f(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y));
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f getMousePressedPosition(const sf::Event& event)
{
    return sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f getMouseReleasedPosition(const sf::Event& event)
{
    return sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
}

////////////////////////////////////////////////////////////////////////////////
bool inCircle(const sf::Vector2f& position, const sf::Vector2f& center, float radius)
{
    return inCircle(position.x, position.y, center.x, center.y, radius);
}

////////////////////////////////////////////////////////////////////////////////
bool inCircle(float x, float y, float centerX, float centerY, float radius)
{
    return ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY)) < (radius * radius);
}

////////////////////////////////////////////////////////////////////////////////
std::string encrypt(const std::string& key, const std::string& message)
{
    std::size_t index = 0;
    std::string temp  = "";

    if(key.empty())
        return message;

    for(std::size_t i = 0; i < message.size(); ++i)
    {
        temp += static_cast<char>(message[i] + key[index++]);

        if(index >= key.size())
            index = 0;
    }

    return temp;
}

////////////////////////////////////////////////////////////////////////////////
std::string decrypt(const std::string& key, const std::string& message)
{
    std::size_t index = 0;
    std::string temp  = "";

    if(key.empty())
        return message;

    for(std::size_t i = 0; i < message.size(); ++i)
    {
        temp += static_cast<char>(message[i] - key[index++]);

        if(index >= key.size())
            index = 0;
    }

    return temp;
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f subtractHalf(const sf::Vector2f& position0, const sf::Vector2f& position1)
{
    return subtractHalf(position0.x, position0.y, position1.x, position1.y);
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f subtractHalf(float x0, float y0, float x1, float y1)
{
    return sf::Vector2f(x0 / 2.f - x1 / 2.f, y0 / 2.f - y1 / 2.f);
}

////////////////////////////////////////////////////////////////////////////////
sf::FloatRect getBoundingBox(const sf::Sprite& sprite)
{
    return sf::FloatRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getLocalBounds().width, sprite.getLocalBounds().height);
}

////////////////////////////////////////////////////////////////////////////////
float dotProduct(const sf::Vector2f& v0, const sf::Vector2f& v1)
{
    return dotProduct(v0.x, v0.y, v1.x, v1.y);
}

////////////////////////////////////////////////////////////////////////////////
float dotProduct(float vx0, float vy0, float vx1, float vy1)
{
    return vx0 * vx1 + vy0 * vy1;
}

} // namespace sfx
