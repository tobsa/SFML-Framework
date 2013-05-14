////////////////////////////////////////////////////////////////////////////////
// Filename: TextEditBox.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "TextEditBox.hpp"
#include "../Application.hpp"
#include "../Utility/Utility.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
TextEditBox::TextEditBox(Application& application) :
    GuiObject       (application),
    m_maxCharacters (50)
{
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::onEvent(const sf::Event& event)
{
    if(!isEnabled()) return;

    if(event.type == sf::Event::MouseMoved)
    {
        if(contains(getMousePosition(event)))
            setHover(true);
        else  
            setHover(false);
    }

    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(isHover())
            setPressed(true);
        else 
            setPressed(false);
    }

    if(event.type == sf::Event::TextEntered)
    {
        // Don't allow typing in the edit box if it isn't pressed
        if(!isPressed()) return;

        std::string text = m_text.getString();
        char letter      = static_cast<char>(event.text.unicode);

        // Remove the last letter if backspace was pressed
        if(letter == 8)
            text = text.substr(0, text.size() - 1);
        else if(text.size() < m_maxCharacters && letter != 13)        
            text += letter;

        // Update string and caret position
        m_text.setString(text);
        m_caret.setPosition(m_text.findCharacterPos(text.size()).x + 1, getPosition().y + getSize().y / 2.f - m_caret.getSize().y / 2.f);

        // Make sure all the text is inside the edit box
        if(m_text.findCharacterPos(m_text.getString().getSize()).x >= getPosition().x + getSize().x)
        {
            text = m_text.getString();
            text = text.substr(0, text.size() - 1);

            // Update string and caret position
            m_text.setString(text);
            m_caret.setPosition(m_text.findCharacterPos(text.size()).x + 1, getPosition().y + getSize().y / 2.f - m_caret.getSize().y / 2.f);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::onUpdate()
{
    // No updates for a text edit box
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(!isEnabled()) return;

    if(isPressed())
        target.draw(m_sprites[2], states);
    else if(isHover())
        target.draw(m_sprites[1], states);
    else 
        target.draw(m_sprites[0], states);

    target.draw(m_text, states);

    if(isPressed())
        target.draw(m_caret, states);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Vector2f& TextEditBox::getPosition() const
{
    return m_sprites[0].getPosition();
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f TextEditBox::getSize() const
{
    return sf::Vector2f(m_sprites[0].getLocalBounds().width, m_sprites[0].getLocalBounds().height);
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f TextEditBox::getCenter() const
{
    return sf::Vector2f(getPosition().x + getSize().x / 2.f, getPosition().y + getSize().y / 2.f);
}

////////////////////////////////////////////////////////////////////////////////
sf::FloatRect TextEditBox::getBoundingBox() const
{
    return sf::FloatRect(getPosition().x, getPosition().y, getSize().x, getSize().y);
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setPosition(const sf::Vector2f& position)
{
    for(auto& sprite : m_sprites)
        sprite.setPosition(position);

    updateText();
    updateCaret();
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setX(float x)
{
    setPosition(x, getPosition().y);
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setY(float y)
{
    setPosition(getPosition().x, y);
}

////////////////////////////////////////////////////////////////////////////////
bool TextEditBox::intersects(const GuiObject& object) const
{
    return intersects(object.getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool TextEditBox::intersects(const sf::FloatRect& boundingBox) const
{
    return boundingBox.intersects(getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool TextEditBox::contains(const sf::Vector2f& position) const
{
    return contains(position.x, position.y);
}

////////////////////////////////////////////////////////////////////////////////
bool TextEditBox::contains(float x, float y) const
{
    return getBoundingBox().contains(x, y);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Texture& TextEditBox::getTexture(std::size_t index) const
{
    return *m_sprites[sfx::clamp(index, 0U, 2U)].getTexture();
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setTexture(std::size_t index, const std::string& filename)
{
    m_sprites[sfx::clamp(index, 0U, 2U)].setTexture(m_application.getTexture(filename));

    updateText();
    updateCaret();
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setTexture(std::size_t index, const sf::Texture& texture)
{
    m_sprites[sfx::clamp(index, 0U, 2U)].setTexture(texture);

    updateText();
    updateCaret();
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setTexture(const std::string& filename)
{
    setTexture(0, filename + "/Normal.png");
    setTexture(1, filename + "/Hover.png");
    setTexture(2, filename + "/Pressed.png");

    updateText();
    updateCaret();
}

////////////////////////////////////////////////////////////////////////////////
std::string TextEditBox::getText() const
{
    return m_text.getString();
}

////////////////////////////////////////////////////////////////////////////////
const sf::Font& TextEditBox::getFont() const
{
    return *m_text.getFont();
}

////////////////////////////////////////////////////////////////////////////////
unsigned int TextEditBox::getCharacterSize() const
{
    return m_text.getCharacterSize();
}

////////////////////////////////////////////////////////////////////////////////
const sf::Color& TextEditBox::getColor() const
{
    return m_text.getColor();
}

////////////////////////////////////////////////////////////////////////////////
sf::Uint32 TextEditBox::getStyle() const
{
    return m_text.getStyle();
}
    
////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setText(const std::string& text)
{
    m_text.setString(text);

    updateText();
    updateCaret();
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setFont(const std::string& filename)
{
    m_text.setFont(m_application.getFont(filename));

    updateText();
    setCaretSize(getCharacterSize());
    updateCaret();
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setFont(const sf::Font& font)
{
    m_text.setFont(font);

    updateText();
    setCaretSize(getCharacterSize());
    updateCaret();
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setCharacterSize(unsigned int size)
{
    m_text.setCharacterSize(size);

    updateText();
    setCaretSize(getCharacterSize());
    updateCaret();
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setColor(const sf::Color& color)
{
    m_text.setColor(color);
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setStyle(sf::Uint32 style)
{
    m_text.setStyle(style);
    updateText();
    updateCaret();
}

////////////////////////////////////////////////////////////////////////////////
const sf::Vector2f& TextEditBox::getTextPosition() const
{
    return m_text.getPosition();
}

////////////////////////////////////////////////////////////////////////////////
std::size_t TextEditBox::getCaretSize() const
{
    return static_cast<std::size_t>(m_caret.getSize().y);
}

////////////////////////////////////////////////////////////////////////////////
std::size_t TextEditBox::getMaxCharacters() const
{
    return m_maxCharacters;
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setTextPosition(const sf::Vector2f& position)
{
    m_text.setPosition(position);
    updateCaret();
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setTextPosition(float x, float y)
{
    m_text.setPosition(x, y);
    updateCaret();
}

void TextEditBox::setCaretSize(std::size_t size)
{
    m_caret.setSize(sf::Vector2f(1.f, static_cast<float>(size)));
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::setMaxCharacters(std::size_t maxCharacters)
{
    m_maxCharacters = maxCharacters;
}

////////////////////////////////////////////////////////////////////////////////
void TextEditBox::updateText()
{
    setTextPosition(getPosition().x + 1, getPosition().y + getSize().y / 2.f - getCharacterSize() / 1.5f);
}

void TextEditBox::updateCaret()
{
    m_caret.setPosition(m_text.findCharacterPos(m_text.getString().getSize()).x, getPosition().y + getSize().y / 2.f - m_caret.getSize().y / 2.f);
}

}
