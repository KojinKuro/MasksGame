//
//  InputHandler.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/11/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "InputHandler.h"
#include "Game.h"

InputHandler * InputHandler::p_instance = 0;

void InputHandler::update()
{
    memcpy(m_keystate, newKeyState, this->length);
    newKeyState = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
                Game::Instance()->quit();
                break;
            case SDL_KEYDOWN:
                break;
            case SDL_KEYUP:
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT)
                    m_mouseStates[LEFT] = true;
                else if(event.button.button == SDL_BUTTON_MIDDLE)
                    m_mouseStates[MIDDLE] = true;
                else if(event.button.button == SDL_BUTTON_RIGHT)
                    m_mouseStates[RIGHT] = true;
                break;
            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_LEFT)
                    m_mouseStates[LEFT] = false;
                else if(event.button.button == SDL_BUTTON_MIDDLE)
                    m_mouseStates[MIDDLE] = false;
                else if(event.button.button == SDL_BUTTON_RIGHT)
                    m_mouseStates[RIGHT] = false;
                break;
            case SDL_MOUSEMOTION:
                m_mousePosition->setX(event.motion.x);
                m_mousePosition->setY(event.motion.y);
                break;
            default:
                break;
        }
    }
}

InputHandler * InputHandler::Instance()
{
    if(p_instance == 0)
        p_instance = new InputHandler();
    return p_instance;
}

void InputHandler::clean()
{
    delete p_instance;
    p_instance = NULL;
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if(m_keystate != 0)
    {
        if(newKeyState[key] == true)
            return true;
        else
            return false;
    }
    return false;
}

bool InputHandler::onKeyDown(SDL_Scancode key)
{
    if(m_keystate != 0)
    {
        if(m_keystate[key] == false && newKeyState[key] == true)
            return true;
        else
            return false;
    }
    return false;
}

bool InputHandler::onKeyUp(SDL_Scancode key)
{
    if(m_keystate != 0)
    {
        if(m_keystate[key] == true && newKeyState[key] == false)
            return true;
        else
            return false;
    }
    return false;
}