//
// Created by M on 5/4/21.
//

#include "EndGameState.h"



void EndGameState::updateInput(const float &dt)
{
    this->checkForQuit();
}
void EndGameState::initButtons()
{
    this->buttons["PlayAgain"]  = new Button(450, 100, 150, 50, &this->font,
                                             "Play Again",sf::Color(70,70,70,200),
                                             sf::Color(150,150,150,200),
                                             sf::Color(20,20,20,200) );

    this->buttons["Select Level"] = new Button(450, 180, 150, 50, &this->font,
                                               "Select Level",sf::Color(70,70,70,200),
                                               sf::Color(150,150,150,200),
                                               sf::Color(20,20,20,200) );

    this->buttons["ExitGame"] = new Button(450, 260, 150, 50, &this->font,
                                           "Quit",sf::Color(70,70,70,200),
                                           sf::Color(150,150,150,200),
                                           sf::Color(20,20,20,200) );

    this->buttons["GoBackToMM"] = new Button(450, 340, 150, 50, &this->font,
                                             "Main Menu",sf::Color(70,70,70,200),
                                             sf::Color(150,150,150,200),
                                             sf::Color(20,20,20,200) );

}

void EndGameState::initBackground()
{
    this->background.setSize(sf::Vector2f (static_cast<float>(this->window->getSize().x),
                                           static_cast<float>(this->window->getSize().y)
                             )

    );

    if(!this->backgroundSprite.loadFromFile("../data/background-c19.png"))
    {
        throw"ERROR::Mainmenu failed to load background sprite";
    }
    this->background.setTexture(&this->backgroundSprite);
}

void EndGameState::initVariable()
{

}

void EndGameState::initFonts()
{
    if(!this->font.loadFromFile("../data/8bitOperatorPlus-Regular.ttf"))
    {
        throw("Error: MainMenuState::Could not load font");
    }
}
void EndGameState::initKeyBinds()
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

EndGameState::EndGameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys,
                           std::stack<State *> *states) : State(window, supportedKeys, states)
{
    this->initVariable();
    this->initBackground();
    this->initFonts();
    this->initKeyBinds();
    this->initButtons();
}

EndGameState::~EndGameState()
{
    auto itr = this->buttons.begin();
    for (itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
    {
        delete itr->second;
    }
}

void EndGameState::updateButtons()
{

    /*updates the buttons in their states and takes care of their functionality*/
    for(auto &itr : this->buttons)
    {
        itr.second->update(this->mousePosView);
    }
    //play game
    if(this->buttons["PlayAgain"]->isPressed())
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

void EndGameState::renderButtons(sf::RenderTarget* target)
{
    for(auto &itr : this->buttons)
    {
        itr.second->render(target);
    }
    //this->mainMenuButton->render(target);

}

void EndGameState::update(const float& dt) {
    this->updateInput(dt);
    this->updateMousePositions();
    this->updateButtons();
    if (quit)
        window->close();
    //this->mainMenuButton->update(this->mousePosView);
    //system('cls');
    //std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";

}



void EndGameState::render(sf::RenderTarget *target)
{
    if (!target)
        target = this->window;
    target->draw(this->background);
    this->renderButtons(target);
}
void EndGameState::endState()
{
    ;
}