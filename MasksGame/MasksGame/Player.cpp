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

//p_toplPos(32,64) , p_botrPos(480,416)

Player::Player() : p_position(192,128) , p_velocity(0,0) , p_acceleration(0,0) , p_width(32) , p_height(32) , p_healthCur(100), e_collider(p_boundBox, this){
    TextureManager::Instance()->load("character.png", "player", Game::Instance()->getRenderer());
}

Player::~Player()
{
    
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
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
        p_velocity.setY(-1);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
        p_velocity.setY(1);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
        p_velocity.setX(-1);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
        p_velocity.setX(1);

    //controls health player remove later
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_EQUALS))
        addHealth(10);
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_MINUS))
       lowHealth(10);
    
    //adds movemnt ands stuff
    p_velocity += p_acceleration;
    
    Vector2D oldPosition = p_position;
    p_position += p_velocity;
    
    e_collider.update();
    if(e_collider.getStateID() != 4)
        p_position = oldPosition;
    
    return true;
}

void Player::clean()
{
    delete p_boundBox;
    delete p_instance;
}

void Player::reset()
{
    p_position.setX(192);
    p_position.setY(128);
    
    p_velocity.setX(0);
    p_velocity.setY(0);
    
    p_acceleration.setX(0);
    p_acceleration.setY(0);
    
    p_healthCur = 100;
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