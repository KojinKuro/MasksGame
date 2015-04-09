//
//  Collider2D.h
//  MasksGame
//
//  Created by Charles Kwang on 4/7/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__Collider2D__
#define __MasksGame__Collider2D__

#include "Vector2D.h"

template <class T, class Y>
class Collider2D
{
    T * tObj;
    Y * yObj;
    
    int c_width;
    int c_height;
    Vector2D c_v1;
    
    int o_width;
    int o_height;
    Vector2D o_v1;
    
    Vector2D c_v2;
    Vector2D c_v3;
    Vector2D c_v4;
    Vector2D o_v2;
    Vector2D o_v3;
    Vector2D o_v4;
public:
    Collider2D(T * t, Y * y);
    
    void update();
    bool otocChecker(int x);
    
    int getStateID() {return currState;}
    
    //handles States
    bool firstTime;
    int currState;
    //0:none,1,2,3, 4(allin)
    //void onEnter();
    //void onStay();
    //void onExit();
};

template <class T, class Y>
Collider2D<T,Y>::Collider2D(T * t, Y * y) : tObj(t), yObj(y) , firstTime(true) , currState(0) {
    
    c_v1 = tObj->getPosition();
    c_width = tObj->getWidth();
    c_height = tObj->getHeight();
    
    o_v1 = yObj->getPosition();
    o_width = yObj->getWidth();
    o_height = yObj->getHeight();
    
    c_v2 = Vector2D(c_v1.getX()+c_width, c_v1.getY());
    c_v3 = Vector2D(c_v1.getX(), c_v1.getY()+c_height);
    c_v4 = Vector2D(c_v1.getX()+c_width, c_v1.getY()+c_height);
    
    o_v2 = Vector2D(o_v1.getX()+o_width, o_v1.getY());
    o_v3 = Vector2D(o_v1.getX(), o_v1.getY()+o_height);
    o_v4 = Vector2D(o_v1.getX()+o_width, o_v1.getY()+o_height);
}

template <class T, class Y>
void Collider2D<T,Y>::update() {
    //updates the map
    c_v1 = tObj->getPosition();
    c_width = tObj->getWidth();
    c_height = tObj->getHeight();
        
    o_v1 = yObj->getPosition();
    o_width = yObj->getWidth();
    o_height = yObj->getHeight();
        
    c_v2 = Vector2D(c_v1.getX()+c_width, c_v1.getY());
    c_v3 = Vector2D(c_v1.getX(), c_v1.getY()+c_height);
    c_v4 = Vector2D(c_v1.getX()+c_width, c_v1.getY()+c_height);
        
    o_v2 = Vector2D(o_v1.getX()+o_width, o_v1.getY());
    o_v3 = Vector2D(o_v1.getX(), o_v1.getY()+o_height);
    o_v4 = Vector2D(o_v1.getX()+o_width, o_v1.getY()+o_height);
    
    // 1: topleft 2: topright 3: bottomleft 4: bottomright
    if(firstTime)
    {
        if(otocChecker(1))
        {
            currState = 1;
            firstTime = false;
        }
        if(otocChecker(4))
        {
            currState = 4;
        }
    }
    else
    {
        //onStay();
        if(otocChecker(1))
        {
            currState = 2;
            firstTime = false;
            if(otocChecker(4))
                currState = 4;
        }
        //onExit()
        else
        {
            currState = 3;
            firstTime = true;
        }
    }
}

template <class T, class Y>
bool Collider2D<T,Y>::otocChecker(int x) {
    int i = 0;
    if(c_v1.getY() <= o_v1.getY() && c_v2.getX() >= o_v1.getX() && c_v3.getX() <= o_v1.getX() && c_v4.getY() >= o_v1.getY())
    {
        ++i;
    }
    if(c_v1.getY() <= o_v2.getY() && c_v2.getX() >= o_v2.getX() && c_v3.getX() <= o_v2.getX() && c_v4.getY() >= o_v2.getY())
    {
        ++i;
    }
    if(c_v1.getY() <= o_v3.getY() && c_v2.getX() >= o_v3.getX() && c_v3.getX() <= o_v3.getX() && c_v4.getY() >= o_v3.getY())
    {
        ++i;
    }
    if(c_v1.getY() <= o_v4.getY() && c_v2.getX() >= o_v4.getX() && c_v3.getX() <= o_v4.getX() && c_v4.getY() >= o_v4.getY())
    {
        ++i;
    }
    return (x <= i);
}

#endif /* defined(__MasksGame__Collider2D__) */
