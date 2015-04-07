//
//  MenuState.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__MenuState__
#define __MasksGame__MenuState__

#include "GameStates.h"
#include "ButtonObject.h"

class MenuState : public GameStates
{
public:
    virtual void update();
    virtual void render();
    
    virtual void onEnter();
    virtual void onExit();
    virtual std::string getStateID() {return stateID;}
private:
    std::string stateID = "MENU";
    
    Mix_Music * song = NULL;
    
    std::vector<BaseObject*> m_gamelist;
    
    SDL_Texture * texture;
    SDL_Texture * texture2;
    SDL_Color color = {0,0,0};
};

#endif /* defined(__MasksGame__MenuState__) */
