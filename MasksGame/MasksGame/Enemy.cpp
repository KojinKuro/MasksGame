//
//  Enemy.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/23/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "Enemy.h"
#include <iostream>

Enemy::Enemy() : p_position(350,300), p_velocity(0,0) , p_acceleration(0,0), p_height(32), p_width(32), e_collider(this, Player::Instance()) , start(SDL_GetTicks()) {
    TextureManager::Instance()->load("slime.png", "Enemy", Game::Instance()->getRenderer());
}

void Enemy::draw()
{
    TextureManager::Instance()->draw("Enemy", p_position.getX(), p_position.getY(), p_width, p_height, Game::Instance()->getRenderer());
}

bool Enemy::update()
{
    p_velocity.setX(0);
    p_velocity.setY(0);
    
    e_collider.update();
    
    p_velocity += p_acceleration;
    p_position += p_velocity;
    
    curr = SDL_GetTicks();
    if(e_collider.getStateID() == 1 || e_collider.getStateID() == 2 || e_collider.getStateID() == 4)
    {
        if((curr - start) / 1000 > 0)
        {
            Player::Instance()->lowHealth(10);
            start = curr;
        }
    }
    return false;
}

void Enemy::clean()
{
    
}