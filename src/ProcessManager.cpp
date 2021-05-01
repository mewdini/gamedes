

//#include "ProcessManager.h"
//
//
//void ProcessManager::initKeyBinds()
//{
//
//    std::ifstream ifs("../data/gameStateKeybinds.ini");
//    if (ifs.is_open())
//    {
//        std::string key = "";
//        std::string key2 = "";
//        while(ifs >> key >> key2)
//        {
//            this->keybinds[key] = this->supportedKeys->at(key2);
//        }
//    }
//
//    ifs.close();
////    this->keybinds["Move_Left"] = this->supportedKeys->at("A");
////    this->keybinds["Move_Right"] = this->supportedKeys->at("D");
////    this->keybinds["Move_Up"] = this->supportedKeys->at("W");
////    this->keybinds["Move_Down"] = this->supportedKeys->at("S");
////    this->keybinds["Close"] = this->supportedKeys->at("Escape");
//}
//
//ProcessManager::ProcessManager(sf::RenderWindow* window,std::map<std::string, int>* supportedKeys)
//    : State(window, supportedKeys)
//{
//    this->initKeyBinds();
//}
//
//ProcessManager::~ProcessManager()
//{
//
//}
//
//void ProcessManager::update(const float& dt)
//{
//    this->updateInput(dt);
//
//    this->player.update(dt);
//}
//
//void ProcessManager::render(sf::RenderTarget* target)
//{
//    if (!target)
//        target = this->window;
//
//    this->player.render(window);
//
//
//}
//
//void ProcessManager::endState()
//{
//    std::cout << "Ending game state" << "\n";
//}
//
//void ProcessManager::updateInput(const float &dt)
//{
//    //it will quit as soon as we press escape
//    this->checkForQuit();
//
//    //player input
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Move_Left"))))
//        this->player.move(dt,-1.f, 0.f);
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Keyboard::Key(this->keybinds.at("Move_Right"))))
//        this->player.move(dt,1.f, 0.f);
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Keyboard::Key(this->keybinds.at("Move_Up"))))
//        this->player.move(dt,0.f, -1.f);
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Keyboard::Key(this->keybinds.at("Move_Down"))))
//        this->player.move(dt,0.f, 1.f);
//}
//#include "ProcessManager.h"
//
//
//
//ProcessManager::ProcessManager(SharedContext* l_shared):m_shared(l_shared)
//{
//    RegisterState<State_Intro>(StateType::Intro);
//    RegisterState<State_MainMenu>(StateType::MainMenu);
//    RegisterState<State_Game>(StateType::Game);
//    RegisterState<State_Paused>(StateType::Paused);
//}
//
//
//ProcessManager::~ProcessManager()
//{
//    for (auto &itr : m_states)
//    {
//        itr.second->OnDestroy();
//        delete itr.second;
//    }
//}
//
//void ProcessManager::Draw()
//{
//    if (m_states.empty()) { return; }
//    /* We check if the state container has at least one state,
//     * if it does then we check the most recently added ones transparency
//     * flag as well if there is more then 1 otherwise transparency
//     * is useless. If there's only one state on the stack or if the current state
//     * isn't transparent, we simply invoke its Draw method. Otherwise, things get a
//     * little bit more interesting.*/
//
//    /*In order to correctly render transparent states, we must call their respective
//     * Draw methods in a correct order, where the latest state on the stack is drawn on screen
//     * last. To do that, it's necessary to iterate through the state vector backwards until a state
//     * is found that is either not transparent or is the first state on the stack, which is what the while
//     * loop does. After such state is found, the Draw calls of all states from and including the one found, up
//     * to the very last one are invoked in the for loop. This effectively renders multiple
//     * states at once in correct order.*/
//    if (m_states.back().second->IsTransparent() && m_states.size() > 1)
//    {
//        auto itr = m_states.end();
//        while (itr != m_states.begin())
//        {
//            if (itr != m_states.end())
//            {
//                if (!itr -> second -> IsTransparent())
//                {
//                    break;
//                }
//            }
//            --itr;
//        }
//        for (; itr != m_states.end(); ++itr)
//        {
//            itr->second->Draw();
//        }
//    }
//    else
//    {
//        m_states.back().second->Draw();
//    }
//}
//
//void ProcessManager::Update(const sf::Time &l_time)
//{
//    if (m_states.empty()) { return; }
//
//    if (m_states.back().second->IsTranscendent() && m_states.size() > 1)
//    {
//        auto itr = m_states.end();
//        while (itr != m_states.begin())
//        {
//            if (itr != m_states.end())
//            {
//                if (!itr -> second -> IsTranscendent())
//                {
//                    break;
//                }
//            }
//            --itr;
//        }
//        for (; itr != m_states.end(); ++itr)
//        {
//            itr->second->Update(l_time);
//        }
//    }
//    else
//    {
//        m_states.back().second->Update(l_time);
//    }
//}
//
//
//SharedContext* ProcessManager::GetContext()
//{
//    return m_shared;
//}
//
//
//bool ProcessManager::HasState(const StateType &l_type) {
//    for (auto itr = m_states.begin();
//         itr != m_states.end(); ++itr)
//
//    {
//        if (itr->first == l_type)
//        {
//            auto removed = std::find(m_toRemove.begin(),
//            m_toRemove.end(), l_type);
//
//            if (removed == m_toRemove.end()) {return true; }
//
//            return false;
//        }
//
//    }
//
//    return false;
//
//}
//
//void ProcessManager::Remove(const StateType &l_type)
//{
//    m_toRemove.push_back(l_type);
//}
//
//void ProcessManager::ProcessRequests()
//{
//    while (m_toRemove.begin() != m_toRemove.end())
//    {
//        RemoveState(*m_toRemove.begin());
//        m_toRemove.erase(m_toRemove.begin());
//    }
//}
//
//void ProcessManager::SwitchTo(const StateType &l_type)
//{
//    m_shared->m_eventManager->SetCurrentState(l_type);
//    for (auto itr = m_states.begin();
//        itr != m_states.end(); ++itr)
//    {
//        if (itr->first == l_type)
//
//        {
//            m_states.back().second->Deactivate();
//            StateType tmp_type = itr->first;
//            BaseState* tmp_state = itr->second;
//            m_states.erase(itr);
//            m_states.emplace_back(tmp_type,tmp_state);
//            tmp_state->Activate();
//            return;
//        }
//    }
//
//    //State with l_type was not found
//
//    if (!m_states.empty())
//    {
//        m_states.back().second->Deactivate();
//    }
//    CreateState(l_type);
//    m_states.back().second->Activate();
//}
//
//
//
//void ProcessManager::CreateState(const StateType &l_type)
//{
//    auto newState = m_stateFactory.find(l_type);
//    if (newState == m_stateFactory.end())
//    {
//        return;
//    }
//    BaseState* state = newState->second();
//    m_states.emplace_back((l_type, state);
//    state->OnCreate();
//}
//
//
//void ProcessManager::RemoveState(const StateType &l_type)
//{
//    for (auto itr = m_states.begin();
//        itr != m_states.end(); ++itr)
//
//    {
//        if (itr->first ==l_type)
//
//        {
//            itr->second->OnCreate();
//            delete itr->second;
//            m_states.erase(itr);
//            m_shared->m_soundManager->RemoveState(l_type);
//            return;
//        }
//    }
//
//}