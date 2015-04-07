//
//  ButtonObject.h
//  MasksGame
//
//  Created by Charles Kwang on 3/17/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__ButtonObject__
#define __MasksGame__ButtonObject__

#include "BaseObject.h"
#include <SDL2/SDL.h>
#include <string>

class ButtonObject : public BaseObject
{
public:
    virtual void draw();
    virtual void clean();
    //is the mouse inside the button
    virtual bool update();
    
    ButtonObject(std::string text, int xPos, int yPos, int width, int height);
private:    
    std::string sID = "button";
    std::string test;
    
    SDL_Color color {0,0,0};
    SDL_Texture * texture = NULL;

    int pos_X;
    int pos_Y;
    
    int obj_W;
    int obj_H;
};

#endif /* defined(__MasksGame__ButtonObject__) */
