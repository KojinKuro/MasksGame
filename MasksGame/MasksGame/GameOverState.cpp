//
//  GameOverState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "GameOverState.h"

void GameOverState::update()
{
    
}

void GameOverState::render()
{
    TextureManager::Instance()->renderTexture(text, Game::Instance()->getRenderer(), 0, 0);
}

void GameOverState::onEnter()
{
    song = Mix_LoadMUS("Japan.mp3");
    Mix_PlayMusic(song, -1);
    
    text = TextureManager::Instance()->renderText("GAME OVER!\nHit Enter to exit.", "text.ttf", color, 13, Game::Instance()->getRenderer());
}

void GameOverState::onExit()
{
    Mix_FreeMusic(song);
    SDL_Delay(1000);
}