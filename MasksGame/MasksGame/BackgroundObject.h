
//
//  BackgroundObject.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__BackgroundObject__
#define __MasksGame__BackgroundObject__

#include "BaseObject.h"

class BackgroundObject : public BaseObject
{
public:
    virtual void draw();
    virtual bool update();
    virtual void clean();
private:
    int pos_X;
    int pos_Y;
    
    int obj_W;
    int obj_H;
};

#endif /* defined(__MasksGame__BackgroundObject__) */
