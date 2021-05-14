//
// Created by M on 5/4/21.
//

#include "WiningState.h"




void WiningState::updateInput(const float &dt)
{
    this->checkForQuit();
}
void WiningState::initButtons()
{
    this->buttons["NextLevel"]  = new Button(520, 200, 150, 50, &this->font,
                                             "Play Again",sf::Color(70,70,70,200),
                                             sf::Color(150,150,150,200),
                                             sf::Color(20,20,20,200) );

    this->buttons["GoBackToMM"] = new Button(520, 250, 150, 50, &this->font,
                                               "Main Menu",sf::Color(70,70,70,200),
                                               sf::Color(150,150,150,200),
                                               sf::Color(20,20,20,200) );

    this->buttons["ExitGame"] = new Button(520, 300, 150, 50, &this->font,
                                           "Quit",sf::Color(70,70,70,200),
                                           sf::Color(150,150,150,200),
                                           sf::Color(20,20,20,200) );



}

void WiningState::initBackground()
{
    this->background.setSize(sf::Vector2f (static_cast<float>(this->window->getSize().x),
                                           static_cast<float>(this->window->getSize().y)
                             )

    );

    if(!this->backgroundSprite.loadFromFile("../data/vaxx.png"))
    {
        throw"ERROR::Endgame failed to load background sprite";
    }
    this->background.setTexture(&this->backgroundSprite);
}

void WiningState::initVariable()
{

}

void WiningState::initFonts()
{
    if(!this->font.loadFromFile("../data/8bitOperatorPlus-Regular.ttf"))
    {
        throw("Error: EndGame::Could not load font");
    }
}
void WiningState::initKeyBinds()
{


    //the keybinds that are used in the state
    std::ifstream ifs("../data/mainMenuKeyBinds.ini");
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
}

WiningState::WiningState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys,
                           std::stack<State *> *states) : State(window, supportedKeys, states)
{
    this->initVariable();
    this->initBackground();
    this->initFonts();
    this->initKeyBinds();
    this->initButtons();
}

WiningState::~WiningState()
{
    auto itr = this->buttons.begin();
    for (itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
    {
        delete itr->second;
    }
}

void WiningState::updateButtons()
{

    /*updates the buttons in their states and takes care of their functionality*/
    for(auto &itr : this->buttons)
    {
        itr.second->update(this->mousePosView);
    }
    //play game
    if(this->buttons["NextLevel"]->isPressed())
    {
        this->states->push(new PlayingState(this->window,this->supportedKeys, this->states));
    }

    //main menu
    if(this->buttons["GoBackToMM"]->isPressed())
    {
        this->states->push(new MainMenuState(this->window,this->supportedKeys, this->states));
    }

    //quit the game
    if(this->buttons["ExitGame"]->isPressed())
    {
        this->quit = true;
    }

}

void WiningState::renderButtons(sf::RenderTarget* target)
{
    for(auto &itr : this->buttons)
    {
        itr.second->render(target);
    }

}

void WiningState::update(const float& dt) {
    this->updateInput(dt);
    this->updateMousePositions();
    this->updateButtons();
    if (quit)
        window->close();

}



void WiningState::render(sf::RenderTarget *target)
{
    if (!target)
        target = this->window;
    target->draw(this->background);
    this->renderButtons(target);
}
void WiningState::endState()
{
    ;
}