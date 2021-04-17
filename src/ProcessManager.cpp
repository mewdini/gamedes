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
//     * is useless. If there's only one state on the stack or if the current state isn't transparent, we simply invoke its Draw method. Otherwise, things get a little bit more interesting.
//
//In order to correctly render transparent states, we must call their respective Draw methods in a correct order, where the latest state on the stack is drawn on screen last. To do that, it's necessary to iterate through the state vector backwards until a state is found that is either not transparent or is the first state on the stack, which is what the while loop does. After such state is found, the Draw calls of all states from and including the one found, up to the very last one are invoked in the for loop. This effectively renders multiple states at once in correct order.*/
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