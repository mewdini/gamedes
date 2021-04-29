//CREATED BY MIODRAG 13/4/2021
#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include "State.h"
#pragma once

class ProcessManager: //GameState
        public State
{
private:

public:
    ProcessManager(sf::RenderWindow* window);
    virtual ~ProcessManager();

    //functions
    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};



////#include "SharedContext.h"
//#include "BaseState.h"
//#include <vector>
//#include <unordered_map>
//
//
//enum class StateType
//{
//    Intro = 1, MainMenu, Game, Paused, GameOver, Credits
//};
//
//using StateContainer = std::vector <std::pair<StateType, BaseState*>>;
//using TypeContainer = std::vector<StateType>;
//
//// Using an unordered map here in order to map a specific state type
//// to a specific function that will generate that type
//using StateFactory = std::unordered_map<StateType, std::function<BaseState*(void)>>;
//
//
///* Forward Declaration of ProcessManager
// * The reason all the methods through out the
// * states are virtual is because each class
// * that inherits from BaseState has to implement
// * each and every one of them in order for the project
// * tot compile. Lastly we use m_transcendent and m_transparent
// * to indicate if this state we are currently in has to render
// * or update the state that came before it */
//
//class ProcessManager
//{
//public:
//    ProcessManager(SharedContext* l_shared);
//    ~ProcessManager();
//
//    void Update(const sf::Time& l_time);
//    void Draw();
//
//    void ProcessRequests();
//
//    SharedContext* GetContext();
//    bool HasState(const StateType& l_type);
//
//    void SwitchTo(const StateType& l_type);
//    void Remove(const StateType& l_type);
//private:
//    //Methods
//    void CreateState(const StateType& l_type);
//    void RemoveState(const StateType& l_type);
//
//    template<class T>
//    void RegisterState(const StateType& l_type)
//    {
//        m_stateFactory[l_type] = [this]() -> BaseState*
//        {
//            return new T(this);
//        };
//    }
//
//    //Members
//    SharedContext* m_shared;
//    StateContainer m_states;
//    TypeContainer m_toRemove;
//    StateFactory m_stateFactory;
//
//
//};
//
//
//struct SharedContext
//{
//    SharedContext():m_wind(nullptr), m_eventManager(nullptr){}
//    Window* m_wind;
//    EventManager* m_eventManager;
//};
//
//
//
//
#endif  /*PROCESSMANAGER_H*/