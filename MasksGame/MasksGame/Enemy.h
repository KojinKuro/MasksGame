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
#include "Player.h"
#include "Collider2D.h"

class Enemy : public BaseObject
{
public:
    virtual void draw();
    virtual bool update();
    virtual void clean();
    
    Vector2D getPosition() {return p_position;}
    int getWidth() {return p_width;}
    int getHeight() {return p_height;}
    
    Enemy();
private:
    Vector2D p_position;
    Vector2D p_velocity;
    Vector2D p_acceleration;
    
    int p_width;
    int p_height;
    
    Collider2D<Enemy, Player> e_collider;
    
    Uint32 start, curr;
};


#endif /* defined(__MasksGame__Enemy__) */
