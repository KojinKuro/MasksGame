//
//  MapRender.h
//  MasksGame
//
//  Created by Charles Kwang on 4/7/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__MapRender__
#define __MasksGame__MapRender__

#include "Vector2D.h"
#include <string>
#include <vector>

class MapRender
{
public:
    void update();
    void render();
    void clean();
    void loadToArray(std::string fileName, const char * name);
    
    MapRender(std::string fileName, std::string overFile, std::string picFile);
    
    static int p_ID;
private:
    int t_map[14][11] {};
    int t_over[14][11] {};
    
    const int COLMAX = 14;
    const int ROWMAX = 11;
    
    std::vector<Vector2D> p_overList;
    
    //helps drawing the stuff
    void draw(int x, int y);
};

#endif /* defined(__MasksGame__MapRender__) */
