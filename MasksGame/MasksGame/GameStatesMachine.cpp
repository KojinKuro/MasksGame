//
//  GameStatesMachine.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "GameStatesMachine.h"

GameStatesMachine* GameStatesMachine::g_instance = 0;

GameStatesMachine* GameStatesMachine::Instance()
{
    if(g_instance == 0)
        g_instance = new GameStatesMachine();
    return g_instance;
}

std::string GameStatesMachine::getStateID()
{
    if(!m_stateList.empty())
        return m_stateList.back()->getStateID();
    return NULL;
}

void GameStatesMachine::update()
{
    if(!m_stateList.empty())
        m_stateList.back()->update();
}

void GameStatesMachine::render()
{
    if(!m_stateList.empty())
        m_stateList.back()->render();
}

//get rid of the current state
void GameStatesMachine::popState()
{
    if(!m_stateList.empty())
    {
        m_stateList.back()->onExit();
        delete m_stateList.back();
        m_stateList.pop_back();
    }
}

void GameStatesMachine::pushState(GameStates * gamestate)
{
    m_stateList.push_back(gamestate);
    m_stateList.back()->onEnter();
}

void GameStatesMachine::changeState(GameStates * gamestate)
{
    //get rid of current state
    if(!m_stateList.empty())
    {
        m_stateList.back()->onExit();
        delete m_stateList.back();
        m_stateList.pop_back();
    }
    
    m_stateList.push_back(gamestate);
    m_stateList.back()->onEnter();
}