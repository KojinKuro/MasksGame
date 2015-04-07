//
//  PauseState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "PauseState.h"

void PauseState::update()
{
    
}

void PauseState::render()
{
    
}

void PauseState::onEnter()
{
    //stop pause menu looping
    while(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_P))
        InputHandler::Instance()->update();
}

void PauseState::onExit()
{

}