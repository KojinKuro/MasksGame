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
#include "InputHandler.h"
#include <SDL2/SDL.h>
#include <string>
#include "Collider2D.h"

class ButtonObject : public BaseObject
{
public:
    virtual void draw();
    virtual void clean();
    //is the mouse inside the button
    virtual bool update();
    
    ButtonObject(std::string text, int xPos, int yPos, int width, int height);
    
    Vector2D getPosition(){return p_position;}
    int getWidth() {return p_width;}
    int getHeight() {return p_height;}
private:
    Vector2D p_position;
    int p_width;
    int p_height;
    
    std::string sID = "button";
    std::string test;
    
    SDL_Color color {0,0,0};
    SDL_Texture * texture = NULL;
    
    Collider2D<ButtonObject, InputHandler> e_collider;
};

#endif /* defined(__MasksGame__ButtonObject__) */
