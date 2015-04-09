//
//  BaseObject.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__BaseObject__
#define __MasksGame__BaseObject__

#include "TextureManager.h"
#include "Game.h"
#include "Vector2D.h"

class BaseObject
{
public:
    virtual void draw() = 0;
    virtual bool update() = 0;
    virtual void clean() = 0;
protected:    
    int m_currFrame = 0;
    int m_currRow = 0;
};

#endif /* defined(__MasksGame__BaseObject__) */
