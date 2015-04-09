//
//  HelpState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 4/1/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "MenuState.h"
#include "HelpState.h"
#include "GameStatesMachine.h"

void HelpState::update()
{
    if(backButton->update() && InputHandler::Instance()->getMouseButtonState(0))
        GameStatesMachine::Instance()->changeState(new MenuState());
}

void HelpState::render()
{
    for(int i=0;i<h_textList.size();++i)
        TextureManager::Instance()->renderTexture(h_textList.at(i), Game::Instance()->getRenderer(), 0, i*16);
    backButton->draw();
}

void HelpState::onEnter()
{
    backButton = new ButtonObject("Back", 512, 448, 128, 32);
    
    h_textList.push_back(TextureManager::Instance()->renderText("=Controls=", "text.ttf", color, 12, Game::Instance()->getRenderer()));
    h_textList.push_back(TextureManager::Instance()->renderText("W: forward", "text.ttf", color, 12, Game::Instance()->getRenderer()));
    h_textList.push_back(TextureManager::Instance()->renderText("A: left", "text.ttf", color, 12, Game::Instance()->getRenderer()));
    h_textList.push_back(TextureManager::Instance()->renderText("D: right", "text.ttf", color, 12, Game::Instance()->getRenderer()));
    h_textList.push_back(TextureManager::Instance()->renderText("S: down", "text.ttf", color, 12, Game::Instance()->getRenderer()));
    h_textList.push_back(TextureManager::Instance()->renderText("P: pause", "text.ttf", color, 12, Game::Instance()->getRenderer()));
    h_textList.push_back(TextureManager::Instance()->renderText("Mouse: clicking", "text.ttf", color, 12, Game::Instance()->getRenderer()));
    
    h_textList.push_back(TextureManager::Instance()->renderText("=Story=", "text.ttf", color, 12, Game::Instance()->getRenderer()));
    h_textList.push_back(TextureManager::Instance()->renderText("Welcome to school", "text.ttf", color, 12, Game::Instance()->getRenderer()));
}

void HelpState::onExit()
{
    backButton->clean();
    delete backButton;
    
    for(int i=0;i<h_textList.size();++i)
        SDL_DestroyTexture(h_textList.at(i));
    h_textList.clear();
}