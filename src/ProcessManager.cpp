

#include "ProcessManager.h"


ProcessManager::ProcessManager(sf::RenderWindow* window)
    : State(window)
{

}

ProcessManager::~ProcessManager()
{

}

void ProcessManager::update(const float& dt)
{
    std::cout << "Hello from game state" << "\n";
}

void ProcessManager::render(sf::RenderTarget* target)
{

}

void ProcessManager::endState()
{

}

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