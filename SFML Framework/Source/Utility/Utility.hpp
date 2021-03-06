////////////////////////////////////////////////////////////////////////////////
// Filename: Utility.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_UTILITY_HPP
#define SFX_UTILITY_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <SFML/Graphics/Sprite.hpp>

namespace sfx
{
    ////////////////////////////////////////////////////////////////////////////////
    // Definitions
    ////////////////////////////////////////////////////////////////////////////////
    const float Pi = 3.14159265359f;
    const float PiOver180 = Pi / 180.f;

    ////////////////////////////////////////////////////////////////////////////////
    // Convert between radians and degrees
    ////////////////////////////////////////////////////////////////////////////////
    float toDegree(float radians);
    float toRadian(float degrees);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the distance between two points
    ////////////////////////////////////////////////////////////////////////////////
    float getDistance(const sf::Vector2f& position0, const sf::Vector2f& position1);
    float getDistance(float x0, float y0, float x1, float y1);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the angle between two points
    ////////////////////////////////////////////////////////////////////////////////
    float getAngle(const sf::Vector2f& position0, const sf::Vector2f& position1);
    float getAngle(float x0, float y0, float x1, float y1);

    ////////////////////////////////////////////////////////////////////////////////
    // Get a random number
    ////////////////////////////////////////////////////////////////////////////////
    int getRandom(int begin, int end);
    float getRandom(float begin, float end);
    sf::Vector2f getRandom(float begin0, float end0, float begin1, float end1);

    ////////////////////////////////////////////////////////////////////////////////
    // Convert between strings and numbers
    ////////////////////////////////////////////////////////////////////////////////
    template<class T> T convert(const std::string& str);
    template<class T> std::string convert(T number);

    ////////////////////////////////////////////////////////////////////////////////
    // Clamp a value
    ////////////////////////////////////////////////////////////////////////////////
    template<class T> T clamp(T value, T min, T max);

    ////////////////////////////////////////////////////////////////////////////////
    // Like clamp but instead wraps the value
    ////////////////////////////////////////////////////////////////////////////////
    template<class T> T wrap(T value, T min, T max);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the mouse position
    ////////////////////////////////////////////////////////////////////////////////
    sf::Vector2f getMouseMovedPosition(const sf::Event& event);
    sf::Vector2f getMousePressedPosition(const sf::Event& event);
    sf::Vector2f getMouseReleasedPosition(const sf::Event& event);

    ////////////////////////////////////////////////////////////////////////////////
    // Check if a point is inside a circle
    ////////////////////////////////////////////////////////////////////////////////
    bool inCircle(const sf::Vector2f& position, const sf::Vector2f& center, float radius);
    bool inCircle(float x, float y, float centerX, float centerY, float radius);

    ////////////////////////////////////////////////////////////////////////////////
    // Encrypt/Decrypt a message with a key
    ////////////////////////////////////////////////////////////////////////////////
    std::string encrypt(const std::string& key, const std::string& message);
    std::string decrypt(const std::string& key, const std::string& message);

    ////////////////////////////////////////////////////////////////////////////////
    // Subtract the half width of the first with the half width of the second
    // position
    ////////////////////////////////////////////////////////////////////////////////
    sf::Vector2f subtractHalf(const sf::Vector2f& position0, const sf::Vector2f& position1);
    sf::Vector2f subtractHalf(float x0, float y0, float x1, float y1);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the bounding box of a sprite
    ////////////////////////////////////////////////////////////////////////////////
    sf::FloatRect getBoundingBox(const sf::Sprite& sprite);

    ////////////////////////////////////////////////////////////////////////////////
    // Advance an iterator by an offset and return it
    ////////////////////////////////////////////////////////////////////////////////
    template<typename T> T advance(T& iterator, std::size_t offset);

    ////////////////////////////////////////////////////////////////////////////////
    // Calculate the dot product from two vectors
    ////////////////////////////////////////////////////////////////////////////////
    float dotProduct(const sf::Vector2f& v0, const sf::Vector2f& v1);
    float dotProduct(float vx0, float vy0, float vx1, float vy1);

} // namespace sfx

////////////////////////////////////////////////////////////////////////////////
// Inline files
////////////////////////////////////////////////////////////////////////////////
#include "Utility.inl"

#endif
