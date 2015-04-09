//
//  ButtonObject.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/17/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "ButtonObject.h"
#include "Game.h"
#include "TextureManager.h"

ButtonObject::ButtonObject(std::string text, int xPos, int yPos, int width, int height) : p_position(xPos, yPos) , p_width(width) , p_height(height) , e_collider(this, InputHandler::Instance())
{
    TextureManager::Instance()->load("button.png", sID, Game::Instance()->getRenderer());
    texture = TextureManager::Instance()->renderText(text, "text.ttf", color, 20, Game::Instance()->getRenderer());
}

void ButtonObject::draw()
{
    TextureManager::Instance()->draw(sID, p_position.getX(), p_position.getY(), p_width, p_height, Game::Instance()->getRenderer());
    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    TextureManager::Instance()->renderTexture(texture, Game::Instance()->getRenderer(), p_position.getX()+(p_width-w)/2, p_position.getY()+(p_height-h)/2);
}

void ButtonObject::clean()
{
    //do nothing
    SDL_DestroyTexture(texture);
}

bool ButtonObject::update()
{
    e_collider.update();
    if(e_collider.getStateID() == 4 || e_collider.getStateID() == 2 || e_collider.getStateID() == 1)
        return true;
    return false;
}