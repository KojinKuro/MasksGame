//
//  BlankObject.cpp
//  MasksGame
//
//  Created by Charles Kwang on 4/8/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "BlankObject.h"

void BlankObject::draw()
{
    
}

bool BlankObject::update()
{
    return true;
}

void BlankObject::clean()
{
    
}

BlankObject::BlankObject(int x, int y, int w, int h) : p_position(x,y) , p_width(w) , p_height(h)
{
    
}