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

class PlayState : public GameStates
{
public:
    virtual void update();
    virtual void render();
    
    virtual void onEnter();
    virtual void onExit();
private:
    std::string stateID = "PLAY";
    virtual std::string getStateID() {return stateID;}
};

#endif /* defined(__MasksGame__PlayState__) */
