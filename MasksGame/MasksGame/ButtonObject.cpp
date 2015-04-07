//
//  ButtonObject.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/17/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "ButtonObject.h"
#include "InputHandler.h"
#include "Game.h"
#include "TextureManager.h"

ButtonObject::ButtonObject(std::string text, int xPos, int yPos, int width, int height) : pos_X(xPos) , pos_Y(yPos) , obj_W(width) , obj_H(height)
{
    TextureManager::Instance()->load("button.png", sID, Game::Instance()->getRenderer());
    texture = TextureManager::Instance()->renderText(text, "text.ttf", color, 20, Game::Instance()->getRenderer());
}

void ButtonObject::draw()
{
    TextureManager::Instance()->draw(sID, pos_X, pos_Y, obj_W, obj_H, Game::Instance()->getRenderer());
    int w,h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    TextureManager::Instance()->renderTexture(texture, Game::Instance()->getRenderer(), pos_X+(obj_W-w)/2, pos_Y+(obj_H-h)/2);
}

void ButtonObject::clean()
{
    //do nothing
    SDL_DestroyTexture(texture);
}

bool ButtonObject::update()
{
    if(InputHandler::Instance()->getMousePosition()->getX() >= pos_X && InputHandler::Instance()->getMousePosition()->getX() <= (pos_X + obj_W)) {
        if(InputHandler::Instance()->getMousePosition()->getY() >= pos_Y && InputHandler::Instance()->getMousePosition()->getY() <= (pos_Y+obj_H)) {
            return true;
        }
    }
    return false;
}