//
//  Player.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "Player.h"
#include "InputHandler.h"

Player * Player::p_instance = NULL;

Player * Player::Instance()
{
    if(p_instance == NULL)
        p_instance = new Player();
    return p_instance;
}

Player::Player() {
    TextureManager::Instance()->load("horse.gif", "player", Game::Instance()->getRenderer());
}

void Player::draw()
{
    TextureManager::Instance()->draw("player", p_position.getX(), p_position.getY(), p_width, p_height, Game::Instance()->getRenderer());
}

bool Player::update()
{
    p_velocity.setX(0);
    p_velocity.setY(0);
    
    //controls how the player moves
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
        p_velocity.setY(-1);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
        p_velocity.setY(1);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
        p_velocity.setX(-1);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
        p_velocity.setX(1);
    
    p_velocity += p_acceleration;
    p_position += p_velocity;
    
    return true;
}

void Player::clean()
{
    
}