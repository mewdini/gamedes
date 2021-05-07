// Created by M on 2/28/21.

#include "Game.h"
#include "Player.h"


//Functions
void Game::updateDt()
{
    /*updates the dt variable with the time it takes to update and render one frame*/
    this->dt = this->dtClock.restart().asMicroseconds();
}

void Game::updateSFMLEvents()
{
    while(this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
    if(!this->states.empty())
    {

        this->states.top()->update(this->dt);
        if (this-> states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
        //Application end
    else
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    if(!this->states.empty())
        this->states.top()->render();
    this->window->display();
}

void Game::run()
{
    while(this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}


//Initializer Functions
void Game::initWindow()
{
    /*create a SFML window using options from a window file*/
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Covid Champ", Style::Close);
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initStates()
{
    //this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
    this->states.push(new WiningState(this->window, &this->supportedKeys, &this->states));
}


//Constructors/Destructors
Game::Game()
{
    this->initWindow();
    this->initKeys();
    this->initStates();

}

Game::~Game()
{
    delete this->window;
    while(!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

void Game::endApplication()
{
    std::cout << "The End Game" << "\n";
}



void Game::initKeys()
{

    std::ifstream ifs("../data/supported_key.ini");
     if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;
        while(ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }
    ifs.close();
}
