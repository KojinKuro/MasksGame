//
//  CreditState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 4/6/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "CreditState.h"
#include "MenuState.h"
#include "GameStatesMachine.h"

void CreditState::update()
{
    if(returnMain->update() && InputHandler::Instance()->getMouseButtonState(0))
        GameStatesMachine::Instance()->changeState(new MenuState());
}

void CreditState::render()
{
    int i = 0;
    TextureManager::Instance()->renderTexture(c_textList.at(i), Game::Instance()->getRenderer(), 0, 0);
    
    for(i = 1;i<c_textList.size();i++)
        TextureManager::Instance()->renderTexture(c_textList.at(i), Game::Instance()->getRenderer(), 0, 64+(32*(i-1)) + i*4);
    returnMain->draw();
}

void CreditState::onEnter()
{
    c_textList.push_back(TextureManager::Instance()->renderText("Credits", "text.ttf", color, 48, Game::Instance()->getRenderer()));
    c_textList.push_back(TextureManager::Instance()->renderText("Desisgned by: Charles Kwang", "text.ttf", color, 24, Game::Instance()->getRenderer()));
    c_textList.push_back(TextureManager::Instance()->renderText("Programmed by: Charles Kwang", "text.ttf", color, 24, Game::Instance()->getRenderer()));
    c_textList.push_back(TextureManager::Instance()->renderText("Music by: SOMEONE IDK YET", "text.ttf", color, 24, Game::Instance()->getRenderer()));
    c_textList.push_back(TextureManager::Instance()->renderText("Art by: Charles Kwang", "text.ttf", color, 24, Game::Instance()->getRenderer()));
    
    //button bottom right
    returnMain = new ButtonObject("Back", 512, 448, 128, 32);
}

void CreditState::onExit()
{
    delete returnMain;
    
    //gets rid of all text
    for(int i=0;i<c_textList.size();i++)
    {
        SDL_DestroyTexture(c_textList.at(i));
    }
    c_textList.clear();
    
    //try
    SDL_RenderClear(Game::Instance()->getRenderer());
}

