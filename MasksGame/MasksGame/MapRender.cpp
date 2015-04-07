//
//  MapRender.cpp
//  MasksGame
//
//  Created by Charles Kwang on 4/7/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "MapRender.h"
#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include <fstream>
#include <iostream>

int MapRender::p_ID = 1;

void MapRender::update()
{
    for(int i=0;i<p_overList.size();++i)
    {
        if(Player::Instance()->getPosition().Equals(p_overList.at(i)))
        {
            
            break;
        }
    }

}

void MapRender::render()
{
    for(int i=0;i<ROWMAX;i++)
    {
        for(int j=0;j<COLMAX;j++)
        {
            draw(j,i);
        }
    }
}

void MapRender::draw(int x, int y)
{
    TextureManager::Instance()->drawFrame("overFile", (x+1)*32, (y+2)*32, 32, 32, 0, t_map[x][y], Game::Instance()->getRenderer());
}

void MapRender::clean()
{
    
}

void MapRender::loadToArray(std::string fileName, const char * name)
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
        
        const char * token[14] = {};
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
        
        if(strcmp(name, "MAP"))
        {
            for(int i=0;i<COLMAX;i++)
                t_map[i][tt] = atoi(token[i]);
        }
        else
        {
            //number gets set here and offset
            for(int i=0;i<COLMAX;i++)
            {
                int tempNum = atoi(token[i]);
                if(tempNum > 0)
                    p_overList.push_back(Vector2D((i+1)*32,(tt+2)*32));
                t_over[i][tt] = tempNum;
            }
        }
        tt++;
    }
    
    inFS.close();
}

MapRender::MapRender(std::string fileName, std::string overFile, std::string picFile)
{
    loadToArray(fileName, "MAP");
    loadToArray(fileName, "OVER");
    
    //ends the loading the file and starts the image stuff
    TextureManager::Instance()->load(picFile, "overFile", Game::Instance()->getRenderer());
}