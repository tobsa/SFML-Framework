////////////////////////////////////////////////////////////////////////////////
// Filename: GuiManager.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Button.hpp"
#include "CheckBox.hpp"
#include "GuiManager.hpp"
#include "Label.hpp"
#include "Picture.hpp"
#include "RadioButton.hpp"
#include "Slider.hpp"
#include "TextEditBox.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
GuiManager::GuiManager(Application& application) :
    m_application(application)
{
}

////////////////////////////////////////////////////////////////////////////////
void GuiManager::remove(const std::string& key)
{
    const auto& result = m_objects.find(key);
    if (result != m_objects.end())
    {
        m_objectsList.remove(result->second);
        m_objects.remove(key);
    }
}

////////////////////////////////////////////////////////////////////////////////
void GuiManager::onEvent(const sf::Event& event)
{
    for (const auto& object : m_objectsList)
        object->onEvent(event);
}

////////////////////////////////////////////////////////////////////////////////
void GuiManager::onUpdate()
{
    for (const auto& object : m_objectsList)
        object->onUpdate();
}

////////////////////////////////////////////////////////////////////////////////
void GuiManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& object : m_objectsList)
        target.draw(*object);
}

////////////////////////////////////////////////////////////////////////////////
sfx::Button& GuiManager::createButton(const std::string& key, const std::string& filename, const sf::Vector2f& position)
{
    sfx::Button& button = create<sfx::Button>(key);
    button.setTexture(filename);
    button.setPosition(position);

    return button;
}

////////////////////////////////////////////////////////////////////////////////
sfx::Button& GuiManager::createButton(const std::string& key, const std::string& filename, float x, float y)
{
    sfx::Button& button = create<sfx::Button>(key);
    button.setTexture(filename);
    button.setPosition(x, y);

    return button;
}

////////////////////////////////////////////////////////////////////////////////
sfx::CheckBox& GuiManager::createCheckBox(const std::string& key, const std::string& filename, const sf::Vector2f& position)
{
    sfx::CheckBox& checkBox = create<sfx::CheckBox>(key);
    checkBox.setTexture(filename);
    checkBox.setPosition(position);

    return checkBox;
}

////////////////////////////////////////////////////////////////////////////////
sfx::CheckBox& GuiManager::createCheckBox(const std::string& key, const std::string& filename, float x, float y)
{
    sfx::CheckBox& checkBox = create<sfx::CheckBox>(key);
    checkBox.setTexture(filename);
    checkBox.setPosition(x, y);

    return checkBox;
}

////////////////////////////////////////////////////////////////////////////////
sfx::Label& GuiManager::createLabel(const std::string& key, const std::string& text, const std::string& font, const sf::Vector2f& position, unsigned int characterSize)
{
    sfx::Label& label = create<sfx::Label>(key);
    label.setText(text);
    label.setFont(font);
    label.setPosition(position);
    label.setCharacterSize(characterSize);

    return label;
}

////////////////////////////////////////////////////////////////////////////////
sfx::Label& GuiManager::createLabel(const std::string& key, const std::string& text, const std::string& font, float x, float y, unsigned int characterSize)
{
    sfx::Label& label = create<sfx::Label>(key);
    label.setText(text);
    label.setFont(font);
    label.setPosition(x, y);
    label.setCharacterSize(characterSize);

    return label;
}

////////////////////////////////////////////////////////////////////////////////
sfx::Picture& GuiManager::createPicture(const std::string& key, const std::string& filename, const sf::Vector2f& position)
{
    sfx::Picture& picture = create<sfx::Picture>(key);
    picture.setTexture(filename);
    picture.setPosition(position);

    return picture;
}

////////////////////////////////////////////////////////////////////////////////
sfx::Picture& GuiManager::createPicture(const std::string& key, const std::string& filename, float x, float y)
{
    sfx::Picture& picture = create<sfx::Picture>(key);
    picture.setTexture(filename);
    picture.setPosition(x, y);

    return picture;
}

////////////////////////////////////////////////////////////////////////////////
sfx::RadioButton& GuiManager::createRadioButton(const std::string& key, const std::string& filename, const std::string& group, const sf::Vector2f& position)
{
    sfx::RadioButton& radioButton = create<sfx::RadioButton>(key);
    radioButton.setTexture(filename);
    radioButton.setGroup(group);
    radioButton.setPosition(position);

    return radioButton;
}

////////////////////////////////////////////////////////////////////////////////
sfx::RadioButton& GuiManager::createRadioButton(const std::string& key, const std::string& filename, const std::string& group, float x, float y)
{
    sfx::RadioButton& radioButton = create<sfx::RadioButton>(key);
    radioButton.setTexture(filename);
    radioButton.setGroup(group);
    radioButton.setPosition(x, y);

    return radioButton;
}

////////////////////////////////////////////////////////////////////////////////
sfx::Slider& GuiManager::createSlider(const std::string& key, const std::string& filename, const sf::Vector2f& position, float minimum, float maximum, float current)
{
    sfx::Slider& slider = create<sfx::Slider>(key);
    slider.setTexture(filename);
    slider.setPosition(position);
    slider.setMinimum(minimum);
    slider.setMaximum(maximum);
    slider.setValue(current);

    return slider;
}

////////////////////////////////////////////////////////////////////////////////
sfx::Slider& GuiManager::createSlider(const std::string& key, const std::string& filename, float x, float y, float minimum, float maximum, float current)
{
    sfx::Slider& slider = create<sfx::Slider>(key);
    slider.setTexture(filename);
    slider.setPosition(x, y);
    slider.setMinimum(minimum);
    slider.setMaximum(maximum);
    slider.setValue(current);

    return slider;
}

////////////////////////////////////////////////////////////////////////////////
sfx::TextEditBox& GuiManager::createTextEditBox(const std::string& key, const std::string& filename, const std::string& font, const sf::Vector2f& position, unsigned int characterSize)
{
    sfx::TextEditBox& textEditBox = create<sfx::TextEditBox>(key);
    textEditBox.setTexture(filename);
    textEditBox.setPosition(position);
    textEditBox.setFont(font);
    textEditBox.setCharacterSize(characterSize);

    return textEditBox;
}

////////////////////////////////////////////////////////////////////////////////
sfx::TextEditBox& GuiManager::createTextEditBox(const std::string& key, const std::string& filename, const std::string& font, float x, float y, unsigned int characterSize)
{
    sfx::TextEditBox& textEditBox = create<sfx::TextEditBox>(key);
    textEditBox.setTexture(filename);
    textEditBox.setPosition(x, y);
    textEditBox.setFont(font);
    textEditBox.setCharacterSize(characterSize);

    return textEditBox;
}

} // namespace sfx
