//
//  PlayState.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__PlayState__
#define __MasksGame__PlayState__

#include "GameStates.h"
#include "Enemy.h"
#include "TileMap.h"
#include "hmpObject.h"

class PlayState : public GameStates
{
public:
    virtual void update();
    virtual void render();
    
    virtual void onEnter();
    virtual void onExit();
    virtual std::string getStateID() {return stateID;}
private:
    std::string stateID = "PLAY";
    Enemy * emyObj;

    Mix_Music * song = NULL;
    
    TileMap * currMap = NULL;
    
    hmpObject health = hmpObject("health");
    hmpObject soul = hmpObject("soul");
};

#endif /* defined(__MasksGame__PlayState__) */
