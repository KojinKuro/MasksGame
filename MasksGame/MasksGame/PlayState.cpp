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
    currMap->update();
    Player::Instance()->update();
    health.update();
    soul.update();
    
    //if soemthing collides with it
    if(emyObj->update())
        GameStatesMachine::Instance()->changeState(new GameOverState());
}

void PlayState::render()
{
    currMap->render();
    Player::Instance()->draw();
    emyObj->draw();
    
    health.draw();
    soul.draw();
}

void PlayState::onEnter()
{
    song = Mix_LoadMUS("Overworld.mp3");
    Mix_PlayMusic(song, -1);
    
    emyObj = new Enemy();
    
    currMap = new TileMap("tilemap_game","map.png");
}

void PlayState::onExit()
{
    Mix_FreeMusic(song);
    
    delete currMap;
    delete emyObj;
    Player::Instance()->reset();
    
    health.clean();
    soul.clean();
}