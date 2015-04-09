//
//  TileMap.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/30/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "TileMap.h"
#include "Game.h"
#include "TextureManager.h"
#include <fstream>
#include <iostream>

void TileMap::update()
{
    
}

void TileMap::render()
{
    for(int i=0;i<ROWMAX;i++)
    {
        for(int j=0;j<COLMAX;j++)
        {
            draw(j,i);
        }
    }
}

void TileMap::draw(int x, int y)
{
    TextureManager::Instance()->drawFrame("tileMap", x*32, y*32, 32, 32, 0, (t_map.at(y)).at(x), Game::Instance()->getRenderer());
}

void TileMap::clean()
{

}

TileMap::TileMap(std::string fileName, std::string picFile)
{
    std::ifstream inFS;
    std::string fullName = SDL_GetBasePath();
    fullName += fileName;
    
    inFS.open(fullName.c_str());
    if(!(inFS.is_open()))
    {
        std::cout << "Could not open file.\n";
        return;
    }
    
    //controlls row
    int tt = 0;
    
    while(!inFS.eof())
    {
        char buff[100];
        
        //move to buffer thing
        inFS.getline(buff, 100);
        
        const char * token[20] = {};
        int j = 0;
        
        token[0] = strtok(buff, ",");
        
        if(token[0])
        {
            for(j=1;j<COLMAX;j++)
            {
                token[j] = strtok(0, ",");
                if(!token[j])
                    break;
            }
        }
        
        std::vector<int> tempVector;
        for(int i=0;i<COLMAX;i++)
        {
            tempVector.push_back(atoi(token[i]));
        }
        t_map.push_back(tempVector);
        tt++;
    }
    
    inFS.close();
    //ends the loading the file and starts the image stuff
    TextureManager::Instance()->load(picFile, "tileMap", Game::Instance()->getRenderer());
}