//
//  TileMap.h
//  MasksGame
//
//  Created by Charles Kwang on 3/30/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__TileMap__
#define __MasksGame__TileMap__

#include <string>
#include <vector>

class TileMap
{
public:
    void update();
    void render();
    void clean();

    TileMap(std::string fileName, std::string picFile);
private:
    int t_col = 20;
    int t_row = 15;

    std::vector<std::vector<int>> t_map;
    
    const int COLMAX = 20;
    const int ROWMAX = 15;
    
    //helps drawing the stuff
    void draw(int x, int y);
};

#endif /* defined(__MasksGame__TileMap__) */
