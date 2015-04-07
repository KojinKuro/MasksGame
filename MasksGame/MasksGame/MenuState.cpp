//
//  MenuState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "MenuState.h"
#include "GameStatesMachine.h"
#include "CreditState.h"
#include "HelpState.h"
#include "PlayState.h"

void MenuState::update()
{
    //play button
    if(m_gamelist.at(0)->update() && InputHandler::Instance()->getMouseButtonState(0))
        GameStatesMachine::Instance()->changeState(new PlayState());
    //help button
    else if(m_gamelist.at(1)->update() && InputHandler::Instance()->getMouseButtonState(0))
        GameStatesMachine::Instance()->changeState(new HelpState());
    //credits button
    else if(m_gamelist.at(2)->update() && InputHandler::Instance()->getMouseButtonState(0))
        GameStatesMachine::Instance()->changeState(new CreditState());
    //exit button
    else if(m_gamelist.at(3)->update() && InputHandler::Instance()->getMouseButtonState(0))
    {
        Game::Instance()->quit();
    }
}

void MenuState::render()
{
    for(int i=0;i<m_gamelist.size();i++)
        m_gamelist.at(i)->draw();
    
    TextureManager::Instance()->draw("drawing", 480, 64, 128, 128, Game::Instance()->getRenderer());
    
    TextureManager::Instance()->renderTexture(texture, Game::Instance()->getRenderer(),32,416);
    TextureManager::Instance()->renderTexture(texture2, Game::Instance()->getRenderer(), 32, 448);
}

void MenuState::onEnter()
{
    song = Mix_LoadMUS("Acoustic.mp3");
    Mix_PlayMusic(song, -1);
    
    TextureManager::Instance()->load("masks.png", "drawing", Game::Instance()->getRenderer());
    
    texture = TextureManager::Instance()->renderText("Masks Game", "text.ttf", color, 20, Game::Instance()->getRenderer());
    texture2 = TextureManager::Instance()->renderText("by Charles Kwang", "text.ttf", color, 20, Game::Instance()->getRenderer());
    
    m_gamelist.push_back(new ButtonObject("Play", 0, 0, 128, 32));
    m_gamelist.push_back(new ButtonObject("Help", 0, 37, 128, 32));
    m_gamelist.push_back(new ButtonObject("Credits", 0, 74, 128, 32));
    m_gamelist.push_back(new ButtonObject("Exit", 0, 111, 128, 32));
}

void MenuState::onExit()
{
    for(int i=0;i<m_gamelist.size();i++)
    {
        m_gamelist.at(i)->clean();
        delete m_gamelist.at(i);
    }
    m_gamelist.clear();
    
    Mix_FreeMusic(song);
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(texture2);
}