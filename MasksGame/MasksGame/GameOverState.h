//
//  GameOverState.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__GameOverState__
#define __MasksGame__GameOverState__

#include "GameStates.h"

class GameOverState : public GameStates
{
public:
    virtual void update();
    virtual void render();
    
    virtual void onEnter();
    virtual void onExit();
    virtual std::string getStateID() {return stateID;}
private:
    std::string stateID = "OVER";
    
    Mix_Music * song;
    
    SDL_Texture * text;
    SDL_Color color = {0,0,0};
};

#endif /* defined(__MasksGame__GameOverState__) */
