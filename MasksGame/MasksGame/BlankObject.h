//
//  BlankObject.h
//  MasksGame
//
//  Created by Charles Kwang on 4/8/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__BlankObject__
#define __MasksGame__BlankObject__

#include "BaseObject.h"

class BlankObject : public BaseObject
{
public:
    virtual void draw();
    virtual bool update();
    virtual void clean();
    
    BlankObject(int x, int y, int w, int h);
    
    Vector2D getPosition() {return p_position;}
    int getWidth() {return p_width;}
    int getHeight() {return p_height;}
private:
    Vector2D p_position;
    int p_width;
    int p_height;
};
#endif /* defined(__MasksGame__BlankObject__) */
