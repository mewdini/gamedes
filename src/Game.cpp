// Created by M on 2/28/21.

#include "Game.h"
#include "Player.h"
#include "iostream"

//Functions
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
        auto temp=this->states.top();
        State* tempstate;
        tempstate=temp;
        if (1==0){
            if (this->sfEvent.type == sf::Event::MouseButtonPressed){
                if(this->sfEvent.mouseButton.button == sf::Mouse::Left){
                    auto pos=sf::Mouse::getPosition();
                    printf("%d,%d",pos.x,pos.y);
                    Tower::Towers tower;
                    this->stage.build(tower,pos.x,pos.y);
                    //int a=stage.getValueOnMap(pos.x,pos.y);
                    //printf("%d",a);
                }

            }
        }
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
void Game::setWindow(sf::RenderWindow *w){
    Game::window=w;
}
void Game::render()
{
    this->window->clear();
    pView->createBG(stage.getMap());
    pView->drawBG();
    
    if(!this->states.empty())
        this->states.top()->render(pView->getWindow());
    setWindow(pView->getWindow());
    this->window->display();
}

void Game::run()
{
    PlayerView* pv = new PlayerView();
    Stage s(7);
    Game::stage=s;
    Game::pView=pv;
    stage.setValueOnMap(0,6,3);
    while(this->window->isOpen())
    {
        //cout<< this->states.top();
        this->updateDt();
        this->update();
        this->render();

    }
}


//Initializer Functions
void Game::initWindow()
{
    /*create a SFML window using options from a window file*/
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Covid Champ");
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initStates()
{
    //this->states.push(new MainMenuState(this->window));
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
    //this->states.push(new PlayingState(this->window, &this->supportedKeys));
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

//    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
//    this->supportedKeys["A"] = sf::Keyboard::Key::A;
//    this->supportedKeys["D"] = sf::Keyboard::Key::D;
//    this->supportedKeys["W"] = sf::Keyboard::Key::W;
//    this->supportedKeys["S"] = sf::Keyboard::Key::S;

//debug
    for (auto i: this->supportedKeys)
    {
        std::cout << i.first << " " << i.second << "\n";

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