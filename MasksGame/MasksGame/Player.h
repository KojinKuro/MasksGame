//
//  Player.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__Player__
#define __MasksGame__Player__

#include "BaseObject.h"

class Player : public BaseObject
{
public:
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif /* defined(__MasksGame__Player__) */
