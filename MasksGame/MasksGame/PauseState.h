//
//  PauseState.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__PauseState__
#define __MasksGame__PauseState__

#include "GameStates.h"

class PauseState : public GameStates
{
public:
    virtual void update();
    virtual void render();
    
    virtual void onEnter();
    virtual void onExit();
private:
    std::string stateID = "PAUSE";
    virtual std::string getStateID() {return stateID;}
};

#endif /* defined(__MasksGame__PauseState__) */
