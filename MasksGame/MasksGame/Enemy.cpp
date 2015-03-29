//
//  Enemy.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/23/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "Enemy.h"
#include "Player.h"

Enemy::Enemy() {
    TextureManager::Instance()->load("horse.gif", "Enemy", Game::Instance()->getRenderer());
}

void Enemy::draw()
{
    TextureManager::Instance()->draw("Enemy", p_position.getX(), p_position.getY(), p_width, p_height, Game::Instance()->getRenderer());
}

bool Enemy::update()
{
    p_velocity.setX(0);
    p_velocity.setY(0);
    
    p_velocity += p_acceleration;
    p_position += p_velocity;
    
    return collideWithPlayer();
}

bool Enemy::collideWithPlayer()
{
    //bottomright
    if(p_position.getX() <= Player::Instance()->getPosition().getX() && (p_position.getX()+p_width) >= Player::Instance()->getPosition().getX())
    {
        if(p_position.getY() <= Player::Instance()->getPosition().getY() && (p_position.getY()+p_height) >= Player::Instance()->getPosition().getY())
            return true;
    }
    //bottom left
    if(p_position.getX() <= (Player::Instance()->getPosition().getX() + Player::Instance()->getWidth()) && (p_position.getX()+p_width) >= (Player::Instance()->getPosition().getX()+Player::Instance()->getWidth()))
    {
        if(p_position.getY() <= Player::Instance()->getPosition().getY() && (p_position.getY()+p_height) >= Player::Instance()->getPosition().getY())
            return true;
    }
    //top right
    if(p_position.getX() <= Player::Instance()->getPosition().getX() && (p_position.getX()+p_width) >= Player::Instance()->getPosition().getX())
    {
        if(p_position.getY() <= (Player::Instance()->getPosition().getY()+Player::Instance()->getHeight()) && (p_position.getY()+p_height) >= (Player::Instance()->getPosition().getY()+Player::Instance()->getHeight()))
            return true;
    }
    //top left
    if(p_position.getX() <= (Player::Instance()->getPosition().getX()+Player::Instance()->getWidth()) && (p_position.getX()+p_width) >= (Player::Instance()->getPosition().getX()+Player::Instance()->getWidth()))
    {
        if(p_position.getY() <= (Player::Instance()->getPosition().getY()+Player::Instance()->getHeight()) && (p_position.getY()+p_height) >= (Player::Instance()->getPosition().getY()+Player::Instance()->getHeight()))
            return true;
    }
    return false;
}

void Enemy::clean()
{
    
}