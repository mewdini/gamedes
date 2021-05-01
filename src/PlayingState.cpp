//
// Created by M on 4/30/21.
//

#include "PlayingState.h"
#include "PlayerView.h"




void PlayingState::initKeyBinds()
{

    std::ifstream ifs("../data/gameStateKeybinds.ini");
    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";
        while(ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close();
//    this->keybinds["Move_Left"] = this->supportedKeys->at("A");
//    this->keybinds["Move_Right"] = this->supportedKeys->at("D");
//    this->keybinds["Move_Up"] = this->supportedKeys->at("W");
//    this->keybinds["Move_Down"] = this->supportedKeys->at("S");
//    this->keybinds["Close"] = this->supportedKeys->at("Escape");
}

PlayingState::PlayingState(sf::RenderWindow* window,std::map<std::string, int>* supportedKeys,std::stack<State*>*  states)
        : State(window, supportedKeys,states)
{
    this->initKeyBinds();
}

PlayingState::~PlayingState()
{

}

void PlayingState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

    this->player.update(dt);
}

void PlayingState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;
    PlayerView* pView = new PlayerView();
    Stage stage(7);
    pView->createBG(stage.getMap());
    pView->drawBG(window);
    this->player.render(window);


}

void PlayingState::endState()
{
    std::cout << "Ending game state" << "\n";
}

void PlayingState::updateInput(const float &dt)
{
    //it will quit as soon as we press escape
    this->checkForQuit();

    //player input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Move_Left"))))
        this->player.move(dt,-1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Keyboard::Key(this->keybinds.at("Move_Right"))))
        this->player.move(dt,1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Keyboard::Key(this->keybinds.at("Move_Up"))))
        this->player.move(dt,0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Keyboard::Key(this->keybinds.at("Move_Down"))))
        this->player.move(dt,0.f, 1.f);
}
