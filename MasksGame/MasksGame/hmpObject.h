//
//  hmpObject.h
//  MasksGame
//
//  Created by Charles Kwang on 4/1/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__hmpObject__
#define __MasksGame__hmpObject__

#include "BaseObject.h"

class hmpObject : public BaseObject
{
public:
    void draw();
    bool update();
    void clean();
    
    hmpObject(std::string type);
private:
    bool health = false;
    int heartNum = 10;
    int soulNum = 10;
};

#endif /* defined(__MasksGame__hmpObject__) */
