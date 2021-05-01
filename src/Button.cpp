//
// Created by M on 4/30/21.
//

#include "Button.h"


Button::Button(float pos_x, float pos_y, float width, float height, sf::Font* font,
               std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = buttonIdel;

    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setPosition(sf::Vector2f(pos_x, pos_y));
    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(25 );

    // this centers the text on a button
    this->text.setPosition(
            this->shape.getPosition().x + (this->shape.getGlobalBounds().width/ 2.f) - this->text.getGlobalBounds().width / 2.f,
            this->shape.getPosition().y +( this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
            );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
    if(this->buttonState == buttonActive)
        return true;
    return false;
}

void Button::update(const sf::Vector2f mousePos)
{
    /*update the booleans for hover and pressed*/
    //idle
    this->buttonState = buttonIdel;

    //hover
    if(this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = buttonHover;
        //pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = buttonActive;
        }
    }

    switch(this->buttonState)
    {
        case buttonIdel:
            this->shape.setFillColor(this->idleColor);
            break;
        case buttonHover:
            this->shape.setFillColor(this->hoverColor);
            break;
        case buttonActive:
            this->shape.setFillColor(this->activeColor);
            break;
        default:
            this->shape.setFillColor(sf::Color::Red);
            break;
    }

}

void Button::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
    target->draw(this->text);
}