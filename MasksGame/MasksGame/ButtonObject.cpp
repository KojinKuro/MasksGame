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

ButtonObject::ButtonObject(std::string fileName, std::string id, int xPos, int yPos, int width, int height) : pos_X(xPos) , pos_Y(yPos) , obj_W(width) , obj_H(height) , sID(id)
{
    TextureManager::Instance()->load(fileName, id, Game::Instance()->getRenderer());
}

void ButtonObject::draw()
{
    TextureManager::Instance()->draw(sID, pos_X, pos_Y, obj_W, obj_H, Game::Instance()->getRenderer());
}

void ButtonObject::clean()
{
    //do nothing o.o?
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