// Created by M on 2/28/21.

#include "Game.h"
#include "Player.h"


// Static Functions
//Initializer Functions
//Constructors/Destructors
void Game::initWindow()
{
    /*create a SFML window using options from a window file*/
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Covid Champ");
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);

}

void Game::initStates()
{
    this->states.push(new ProcessManager(this->window));
}
Game::Game()
{
    this->initWindow();
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



void Game::updateDt()
{
    /*updates the dt variable with the time it takes to update and render one frame*/
    this->dt = this->dtClock.restart().asSeconds();

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
        this->states.top()->update(this->dt);
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




//void Game::Game(PlayerView* p_view)

//    view = p_view;
//}
//
//// it updates the game logic, everything that happens in the game.
//void Game::update(sf::Int64 elapsed_time)
//{
//    time_per_frame = elapsed_time;
//    level.allAttack();
//    // germs move
//}
//
//void Game::click(int x, int y)
//{
//    while (view->isButtonPressed(sf::Mouse::Left))
//    {
//        // tell player view to draw tower at cursor location
//        ;
//    }
//
//    // try to build tower here (tower build function should return false if not enough money or invalid position)
//    bool worked;
//    auto mouse_pos = view->getMousePos();
//    worked = level.build(Tower::Towers::first, mouse_pos.x, mouse_pos.y);
//
//    if (!worked)
//    {
//        // tell player view to show that failed
//        ;
//    }
//}