//
//  MenuObject.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__MenuObject__
#define __MasksGame__MenuObject__

#include "BaseObject.h"

class MenuObject : public BaseObject
{
public:
    virtual void draw();
    virtual bool update();
    virtual void clean();
};

#endif /* defined(__MasksGame__MenuObject__) */
