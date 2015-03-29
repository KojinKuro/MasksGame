//
//  ButtonObject.h
//  MasksGame
//
//  Created by Charles Kwang on 3/17/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__ButtonObject__
#define __MasksGame__ButtonObject__

#include "BaseObject.h"
#include <string>

class ButtonObject : public BaseObject
{
public:
    virtual void draw();
    virtual void clean();
    virtual bool update();
    
    //do button thing because im too lazy to make it in the actual function
    void buttonAction();
    
    ButtonObject(std::string filename, std::string id, int xPos, int yPos, int width, int height);
private:    
    std::string sID;
    
    int pos_X;
    int pos_Y;
    
    int obj_W;
    int obj_H;
};

#endif /* defined(__MasksGame__ButtonObject__) */
