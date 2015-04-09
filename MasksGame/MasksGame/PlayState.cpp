//
//  PlayState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "GameStatesMachine.h"
#include "GameOverState.h"
#include "PlayState.h"
#include "Player.h"
#include <iostream>

void PlayState::update()
{
    currMap->update();
    p_levelList.at(p_levelList.at(0)->p_ID)->update();
    
    Player::Instance()->update();
    emyObj->update();
    health.update();
    soul.update();
    
    if(Player::Instance()->getHealth() == 0)
        GameStatesMachine::Instance()->changeState(new GameOverState());
}

void PlayState::render()
{
    currMap->render();
    p_levelList.at(p_levelList.at(0)->p_ID)->render();
    
    //renders top line text
    for(int i=0;i<2;++i)
    {
        TextureManager::Instance()->renderTexture(p_textList.at(i), Game::Instance()->getRenderer(), 0, i*32);
    }
    
    Player::Instance()->draw();
    emyObj->draw();
    
    health.draw();
    soul.draw();
}

void PlayState::onEnter()
{
    song = Mix_LoadMUS("Overworld.mp3");
    Mix_PlayMusic(song, -1);
    
    emyObj = new Enemy();
    
    currMap = new TileMap("tilemap_game","map.png");
    //controls loading the levels
    //line is so i can be super lazy and not have to change IDs
    p_levelList.push_back(NULL);
    p_levelList.push_back(new MapRender("tilemap_gate", "overmap_gate","map.png"));
    p_levelList.push_back(new MapRender("tilemap_streetleft","overmap_streetleft","map.png"));
    p_levelList.push_back(new MapRender("tilemap_streetright","overmap_streetright","map.png"));
    p_levelList.push_back(new MapRender("tilemap_tree","overmap_tree","map.png"));
    p_levelList.push_back(new MapRender("tilemap_cafeteria","overmap_cafeteria","map.png"));
    p_levelList.push_back(new MapRender("tilemap_classleft","overmap_classleft","map.png"));
    p_levelList.push_back(new MapRender("tilemap_classright","overmap_classright","map.png"));
    
    //controls all of the text on the level
    p_textList.push_back(TextureManager::Instance()->renderText("HLTH:", "text.ttf", color, 24, Game::Instance()->getRenderer()));
    p_textList.push_back(TextureManager::Instance()->renderText("SOUL:", "text.ttf", color, 24, Game::Instance()->getRenderer()));
    p_textList.push_back(TextureManager::Instance()->renderText("COLOR:", "text.ttf", color, 24, Game::Instance()->getRenderer()));
}

void PlayState::onExit()
{
    Mix_FreeMusic(song);
    
    currMap->clean();
    
    delete currMap;
    for(int i=0;i<p_levelList.size();++i)
    {
        p_levelList.at(i)->clean();
        delete p_levelList.at(i);
    }
    p_levelList.clear();
    
    delete emyObj;
    emyObj = NULL;
    Player::Instance()->reset();
    
    health.clean();
    soul.clean();
}

void PlayState::onTempExit()
{
    Mix_PauseMusic();
}

void PlayState::onTempEnter()
{
    Mix_ResumeMusic();
}