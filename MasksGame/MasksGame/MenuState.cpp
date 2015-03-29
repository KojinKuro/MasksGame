//
//  MenuState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "MenuState.h"
#include "GameStatesMachine.h"
#include "PlayState.h"
#include "Game.h"

void MenuState::update()
{
    if(m_gamelist.at(0)->update() && InputHandler::Instance()->getMouseButtonState(0))
        GameStatesMachine::Instance()->changeState(new PlayState());
}

void MenuState::render()
{
    TextureManager::Instance()->draw("main", 0, 0, 640, 480, Game::Instance()->getRenderer());
    for(int i=0;i<m_gamelist.size();i++)
        m_gamelist.at(i)->draw();
    TextureManager::Instance()->draw("pause",0,0,640, 480, Game::Instance()->getRenderer());
    
    TextureManager::Instance()->renderTexture(texture, Game::Instance()->getRenderer(), 100,300);

}

void MenuState::onEnter()
{
    song = Mix_LoadMUS("Acoustic.mp3");
    Mix_PlayMusic(song, -1);
    
    TextureManager::Instance()->load("main_menu.png", "main", Game::Instance()->getRenderer());
    m_gamelist.push_back(new ButtonObject("buttonclicked.png", "bclick", 0, 0, 200, 50));
    
    texture = TextureManager::Instance()->renderText("Hi there", "text.ttf", color, 50, Game::Instance()->getRenderer());
}

void MenuState::onExit()
{
    for(int i=0;i<m_gamelist.size();i++)
        delete m_gamelist.at(i);
    m_gamelist.clear();
    
    Mix_FreeMusic(song);
    SDL_DestroyTexture(texture);
    
    SDL_Delay(1000);
}