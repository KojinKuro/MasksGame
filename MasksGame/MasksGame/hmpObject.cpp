//
//  hmpObject.cpp
//  MasksGame
//
//  Created by Charles Kwang on 4/1/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "hmpObject.h"
#include "Player.h"

void hmpObject::draw()
{
    //offsets to 96 pixels
    if(health)
    {
        for(int i=1;i<=heartNum;++i)
            TextureManager::Instance()->draw("heart", (i+2)*32, 0, 32, 32, Game::Instance()->getRenderer());
    }
    else
    {
        for(int i=1;i<=soulNum;++i)
            TextureManager::Instance()->draw("soul", (i+2)*32, 32, 32, 32, Game::Instance()->getRenderer());
    }
}

bool hmpObject::update()
{
    if(health)
    {
        heartNum = Player::Instance()->getHealth()/10;
        return true;
    }
    soulNum = Player::Instance()->getHealth()/10;
    return true;
}

void hmpObject::clean()
{
    
}

hmpObject::hmpObject(std::string type)
{
    if(type == "soul")
    {
        TextureManager::Instance()->load("soul.png", "soul", Game::Instance()->getRenderer());
    }
    else
    {
        health = true;
        //will make it health instead
        TextureManager::Instance()->load("heart.png", "heart", Game::Instance()->getRenderer());
    }
}