//
//  Enemy.h
//  MasksGame
//
//  Created by Charles Kwang on 3/23/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__Enemy__
#define __MasksGame__Enemy__

#include "BaseObject.h"
#include "Vector2D.h"

class Enemy : public BaseObject
{
public:
    virtual void draw();
    virtual bool update();
    virtual void clean();
    
    Vector2D getPosition() {return p_position;}
    int getWidth() {return p_width;}
    int getHeight() {return p_height;}
    
    bool collideWithPlayer();
    
    Enemy();
private:
    Vector2D p_position = Vector2D(300,300);
    Vector2D p_velocity = Vector2D(0,0);
    Vector2D p_acceleration = Vector2D(0,0);
    
    int p_width = 183;
    int p_height = 122;
};


#endif /* defined(__MasksGame__Enemy__) */
