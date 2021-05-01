//
// Created by M on 4/30/21.
//

#ifndef CSCI437_BUTTON_H
#define CSCI437_BUTTON_H
#include <iostream>

#include <cstdlib>
#include "sstream"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

enum buttonStates {buttonIdel = 0, buttonHover, buttonActive};
class Button
{
private:
    short unsigned buttonState;
    bool pressed;
    bool hover;

    sf::RectangleShape shape;
    sf::Text text;
    sf::Font* font;

    //PROMENI OVA IMENA
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
public:
    Button(float pos_x, float pos_y, float width, float height, sf::Font* font,
           std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    //acs

    void changeGold(int txt);
    const bool isPressed() const;
    //func
    //button is clicked
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);
};


#endif //CSCI437_BUTTON_H
