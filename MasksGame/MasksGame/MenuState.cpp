//
//  MenuState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "MenuState.h"

void MenuState::update()
{
    
}

void MenuState::render()
{
    TextureManager::Instance()->draw("horse", 0, 0, 183, 122, Game::Instance()->getRenderer());
    TextureManager::Instance()->draw("horse", 300, 0, 183, 122, Game::Instance()->getRenderer());
}

void MenuState::onEnter()
{
    TextureManager::Instance()->load("horse.gif", "horse", Game::Instance()->getRenderer());
}

void MenuState::onExit()
{
    
}