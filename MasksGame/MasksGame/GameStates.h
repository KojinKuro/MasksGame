//
//  GameStates.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__GameStates__
#define __MasksGame__GameStates__

#include <string>
#include <vector>
#include "Game.h"
#include "TextureManager.h"

class GameStates
{
public:
    virtual void update() = 0;
    virtual void render() = 0;
    
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
private:
    virtual std::string getStateID() = 0;
};

#endif /* defined(__MasksGame__GameStates__) */