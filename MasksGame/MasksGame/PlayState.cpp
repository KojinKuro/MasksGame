//
//  PlayState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "GameStatesMachine.h"
#include "GameOverState.h"
#include "PlayState.h"
#include "Player.h"

void PlayState::update()
{
    Player::Instance()->update();
    //if soemthing collides with it
    if(emyObj->update())
        GameStatesMachine::Instance()->changeState(new GameOverState());
}

void PlayState::render()
{
    Player::Instance()->draw();
    emyObj->draw();
}

void PlayState::onEnter()
{
    song = Mix_LoadMUS("Overworld.mp3");
    Mix_PlayMusic(song, -1);
    
    emyObj = new Enemy();
}

void PlayState::onExit()
{
    Mix_FreeMusic(song);
    SDL_Delay(1000);
}