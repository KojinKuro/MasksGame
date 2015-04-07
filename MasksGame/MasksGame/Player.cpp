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
    TextureManager::Instance()->load("character.png", "player", Game::Instance()->getRenderer());
}

Player::~Player()
{
    delete p_instance;
    p_instance = NULL;
}

void Player::draw()
{
    TextureManager::Instance()->draw("player", p_position.getX(), p_position.getY(), p_width, p_height, Game::Instance()->getRenderer());
}

bool Player::update()
{
    p_velocity.setX(0);
    p_velocity.setY(0);
    
    //controls how the player moves and makes stay inside box
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) &&(p_toplPos.getY() <= p_position.getY()))
        p_velocity.setY(-1);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN) &&(p_botrPos.getY() >= (p_position.getY()+p_height)))
        p_velocity.setY(1);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && (p_toplPos.getX() <= p_position.getX()))
        p_velocity.setX(-1);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) &&(p_botrPos.getX() >= (p_position.getX()+p_width)))
        p_velocity.setX(1);
    
    //controls health player remove later
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_EQUALS))
        addHealth(10);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_MINUS))
       lowHealth(10);
    
    
    //adds movemnt ands stuff
    p_velocity += p_acceleration;
    p_position += p_velocity;
    
    return true;
}

void Player::clean()
{
    
}

void Player::reset()
{
    p_position.setX(192);
    p_position.setY(128);
    
    p_velocity.setX(0);
    p_velocity.setY(0);
    
    p_acceleration.setX(0);
    p_acceleration.setY(0);
}

void Player::addHealth(int num)
{
    if(p_healthCur+num > p_healthMax)
        p_healthCur = p_healthMax;
    else
        p_healthCur += num;
}

void Player::lowHealth(int num)
{
    if(p_healthCur-num < p_healthMin)
        p_healthCur = p_healthMin;
    else
        p_healthCur -= num;
}

void Player::setHealth(int num)
{
    if(num <= p_healthMax && num >= p_healthMin)
        p_healthCur = num;
}