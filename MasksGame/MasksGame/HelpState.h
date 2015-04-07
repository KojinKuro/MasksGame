//
//  HelpState.h
//  MasksGame
//
//  Created by Charles Kwang on 4/1/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__HelpState__
#define __MasksGame__HelpState__

#include "GameStates.h"
#include "ButtonObject.h"

class HelpState : public GameStates
{
public:
    void update();
    void render();
    
    void onEnter();
    void onExit();
    std::string getStateID() {return stateID;};
public:
    std::string stateID = "HELP";
    
    SDL_Color color = {0,0,0};
    std::vector<SDL_Texture*> h_textList;
    
    ButtonObject * backButton = NULL;
};

#endif /* defined(__MasksGame__HelpState__) */
