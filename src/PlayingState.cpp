//
// Created by M on 4/30/21.
//

#include "PlayingState.h"
#include "PlayerView.h"
#include "Stage.h"
#include "Tower.h"
void PlayingState::initButtons()
{
    this->buttons["Hint"]  = new Button(150, 550, 500, 50, &this->font,
                                       "Click to build towers! Kill viruses to gain more gold!",sf::Color(70,70,70,0),
                                       sf::Color(150,150,150,0),
                                       sf::Color(20,20,20,0) );
    this->buttons["Gold"]  = new Button(650, 0, 150, 100, &this->font,
                                       "Gold:100",sf::Color(70,70,70,0),
                                       sf::Color(150,150,150,0),
                                       sf::Color(20,20,20,0) );
    this->buttons["Tower1"]  = new Button(300, 0, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),
                                       sf::Color(255,0,0,200),

                                       sf::Color(20,20,20,0) );


    this->buttons["Tower2"]  = new Button(200, 100, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),
                                       sf::Color(255,0,0,200),
                                       sf::Color(20,20,20,0) );
this->buttons["Tower3"]  = new Button(450, 100, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),
                                       sf::Color(255,0,0,200),
                                       sf::Color(20,20,20,0) );
this->buttons["Tower4"]  = new Button(200, 250, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),
                                       sf::Color(255,0,0,200),

                                       sf::Color(20,20,20,0) );

this->buttons["Tower5"]  = new Button(450, 250, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),

                                       sf::Color(255,0,0,200),
                                       sf::Color(20,20,20,0) );


this->buttons["Tower6"]  = new Button(750, 350, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),

                                       sf::Color(255,0,0,200),
                                       sf::Color(20,20,20,0) );

this->buttons["Tower7"]  = new Button(450, 400, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),
                                       sf::Color(255,0,0,200),
                                       sf::Color(20,20,20,0) );
this->buttons["Tower8"]  = new Button(550, 400, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),
                                       sf::Color(255,0,0,200),
                                       sf::Color(20,20,20,0) );
this->buttons["Tower9"]  = new Button(650, 400, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),
                                       sf::Color(255,0,0,200),
                                       sf::Color(20,20,20,0) );

    this->buttons["Tower10"]  = new Button(200, 450, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),
                                       sf::Color(255,0,0,200),
                                       sf::Color(20,20,20,0) );
this->buttons["Tower11"]  = new Button(300, 450, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),
                                       sf::Color(255,0,0,200),
                                       sf::Color(20,20,20,0) );
this->buttons["Tower12"]  = new Button(600, 500, 50, 50, &this->font,
                                       "",sf::Color(70,70,70,0),
                                       sf::Color(255,0,0,200),
                                       sf::Color(20,20,20,0) );
                                       
}
void PlayingState::initFonts()
{
    if(!this->font.loadFromFile("../data/8bitOperatorPlus-Regular.ttf"))
    {
        throw("Error: MainMenuState::Could not load font");
    }
}

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
    Stage s(7);
    this->stage=s;
    //s.setValueOnMap(6,0,4);
    PlayerView* pView = new PlayerView();
    this->initFonts();
    this->initKeyBinds();
    this->initButtons();
}

PlayingState::~PlayingState()
{

}

void PlayingState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateButtons();
    this->player.update(dt);
}

void PlayingState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;
    //this->stage.setValueOnMap(6,0,4);
    PlayingState::pView.createBG(this->stage.getMap()); // drawing the default background
    PlayingState::pView.drawBG(window);
    this->renderButtons(window);       // drawing the buttons
    this->player.render(window);


}
void PlayingState::updateButtons()
{

    /*updates the buttons in their states and takes care of their functionality*/
    for(auto &itr : this->buttons)
    {
        itr.second->update(this->mousePosView);
    }
    this->buttons["Gold"]->changeGold(this->stage.getGold());
    //Build Towers 
    if(this->buttons["Tower1"]->isPressed())
    {
        Towers tower=Towers::first;
        this->stage.build(tower,6,0);
        
        
       
    }
    else if(this->buttons["Tower2"]->isPressed())
    {
        Towers tower=Towers::first;
        //int a=this->stage.getValueOnMap(4,2);
        //printf("%d",a);
        this->stage.build(tower,4,2);
        
        
    }
    if(this->buttons["Tower3"]->isPressed())
    {
        Towers tower=Towers::first;
                this->stage.build(tower,9,2);
    }
if(this->buttons["Tower4"]->isPressed())
    {
        Towers tower=Towers::first;
        this->stage.build(tower,4,5);
    }
    if(this->buttons["Tower5"]->isPressed())
    {
        Towers tower=Towers::first;
        this->stage.build(tower,9,5);
    }
if(this->buttons["Tower6"]->isPressed())
    {
        Towers tower=Towers::first;
        this->stage.build(tower,15,7);
    }
if(this->buttons["Tower7"]->isPressed())
    {
        Towers tower=Towers::first;
        this->stage.build(tower,9,8);
    }
if(this->buttons["Tower8"]->isPressed())
    {
        Towers tower=Towers::first;
        this->stage.build(tower,11,8);
    }
    if(this->buttons["Tower9"]->isPressed())
    {
        Towers tower=Towers::first;
        this->stage.build(tower,13,8);
    }
if(this->buttons["Tower10"]->isPressed())
    {
        Towers tower=Towers::first;
        this->stage.build(tower,4,9);
    }
if(this->buttons["Tower11"]->isPressed())
    {
        Towers tower=Towers::first;
        this->stage.build(tower,6,9);
    }
if(this->buttons["Tower12"]->isPressed())
    {
        Towers tower=Towers::first;
        this->stage.build(tower,12,10);
    }

}
void PlayingState::renderButtons(sf::RenderTarget* target)
{
    for(auto &itr : this->buttons)
    {
        itr.second->render(target);
    }
    //this->mainMenuButton->render(target);

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
