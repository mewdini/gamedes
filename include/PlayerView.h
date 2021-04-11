//Edited by Zack on 3/28

#ifndef PlayerView_h
#define PlayerView_h
#include <SFML/Graphics.hpp>

class PlayerView{

    public:
        PlayerView();
        void init();
        void update();
        sf::Vector2i getMousePos(sf::Window);
        bool isButtonPressed(sf::Mouse::Button);

    private:
        sf::RenderWindow window;
        sf::Texture texture; 
        // May need multiple textures, pending based on art
        sf::Font font;
        // # of fonts needed depends on art direction

};

#endif