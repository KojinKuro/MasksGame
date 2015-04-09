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
#include "BlankObject.h"
#include "Collider2D.h"

class Player : public BaseObject
{
public:
    virtual void draw();
    virtual bool update();
    virtual void clean();
    
    Player();
    
    void reset();
    
    Vector2D getPosition() {return p_position;}
    int getWidth() {return p_width;}
    int getHeight() {return p_height;}
    
    //controls health
    void addHealth(int num);
    void lowHealth(int num);
    void setHealth(int num);
    int getHealth() {return p_healthCur;}
    
    //making singleton
    static Player * p_instance;
    static Player * Instance();
private:
    //vectors for control
    Vector2D p_position;
    Vector2D p_velocity;
    Vector2D p_acceleration;

    BlankObject * p_boundBox = new BlankObject(32,64,448,352);
    Collider2D<BlankObject, Player> e_collider;
    
    int p_width;
    int p_height;
    
    int p_healthMax = 100;
    int p_healthCur = 100;
    int p_healthMin = 0;
    
    ~Player();
};

#endif /* defined(__MasksGame__Player__) */
