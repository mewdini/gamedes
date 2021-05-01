////
//// Created by M on 4/29/21.
////


#include "MainMenuState.h"


void MainMenuState::initButtons()
{
    this->buttons["PlayGame"]  = new Button(100, 100, 150, 50, &this->font,
                                       "Play Game",sf::Color(70,70,70,200),
                                       sf::Color(150,150,150,200),
                                       sf::Color(20,20,20,200) );

    this->buttons["ExitGame"] = new Button(100, 400, 150, 50, &this->font,
                                           "Quit",sf::Color(70,70,70,200),
                                           sf::Color(150,150,150,200),
                                           sf::Color(20,20,20,200) );
}
void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("../data/8bitOperatorPlus-Regular.ttf"))
    {
        throw("Error: MainMenuState::Could not load font");
    }
}
void MainMenuState::initKeyBinds()
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
//    this->keybinds["Move_Left"] = this->supportedKeys->at("A");
//    this->keybinds["Move_Right"] = this->supportedKeys->at("D");
//    this->keybinds["Move_Up"] = this->supportedKeys->at("W");
//    this->keybinds["Move_Down"] = this->supportedKeys->at("S");
//    this->keybinds["Close"] = this->supportedKeys->at("Escape");
}

MainMenuState::MainMenuState(sf::RenderWindow* window,std::map<std::string, int>* supportedKeys,std::stack<State*>* states)
        : State(window, supportedKeys, states)
{
    this->initFonts();
    this->initKeyBinds();
    this->initButtons();



    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
    auto itr = this->buttons.begin();
    for (itr = this->buttons.begin(); itr != this->buttons.end(); ++itr)
    {
        delete itr->second;
    }
}

void MainMenuState::updateButtons()
{

    /*updates the buttons in their states and takes care of their functionality*/
    for(auto &itr : this->buttons)
    {
        itr.second->update(this->mousePosView);
    }
    //play game
    if(this->buttons["PlayGame"]->isPressed())
    {
        this->states->push(new PlayingState(this->window, this->supportedKeys, this->states));
    }


    //quit the game
    if(this->buttons["ExitGame"]->isPressed())
    {
        this->quit = true;
    }

}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
    for(auto &itr : this->buttons)
    {
        itr.second->render(target);
    }
    //this->mainMenuButton->render(target);

}

void MainMenuState::update(const float& dt)
{
    this->updateInput(dt);
    this->updateMousePositions();
    this->updateButtons();
    //this->mainMenuButton->update(this->mousePosView);
    //system('cls');
    //std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";




}

void MainMenuState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;
    target->draw(this->background);
    this->renderButtons(target);
    //this->mainMenuButton->render(target);
}

void MainMenuState::endState()
{
    std::cout << "Ending MainMenu game state" << "\n";
}

void MainMenuState::updateInput(const float &dt)
{
    //it will quit as soon as we press escape
    this->checkForQuit();
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))

}


