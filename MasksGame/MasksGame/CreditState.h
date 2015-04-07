//
//  CreditState.h
//  MasksGame
//
//  Created by Charles Kwang on 4/6/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__CreditState__
#define __MasksGame__CreditState__

#include "GameStates.h"
#include "ButtonObject.h"

class CreditState: public GameStates
{
public:
    void update();
    void render();
    
    void onEnter();
    void onExit();
    std::string getStateID() {return stateID;}
private:
    std::string stateID = "CREDIT";
    
    ButtonObject * returnMain = NULL;
    
    std::vector<SDL_Texture*> c_textList;
    SDL_Color color = {0,0,0};
};

#endif /* defined(__MasksGame__CreditState__) */
