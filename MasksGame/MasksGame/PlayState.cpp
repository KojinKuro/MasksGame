//
//  PlayState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "PlayState.h"

void PlayState::update()
{
    
}

void PlayState::render()
{
    TextureManager::Instance()->draw("man", 20, 20, 183, 122, Game::Instance()->getRenderer());
    TextureManager::Instance()->draw("man", 300, 300, 183, 122, Game::Instance()->getRenderer());
}

void PlayState::onEnter()
{
    TextureManager::Instance()->load("horse.gif", "man", Game::Instance()->getRenderer());
}

void PlayState::onExit()
{
    
}