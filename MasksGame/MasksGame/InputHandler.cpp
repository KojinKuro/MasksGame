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
    m_keystate = SDL_GetKeyboardState(0);
    if(SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
                Game::Instance()->quit();
                break;
            case SDL_KEYDOWN:
                onKeyDown(event);
                break;
            case SDL_KEYUP:
                onKeyUp(event);
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
                if(event.button.button == SDL_BUTTON_MIDDLE)
                    m_mouseStates[MIDDLE] = false;
                if(event.button.button == SDL_BUTTON_RIGHT)
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
    
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if(m_keystate != 0)
    {
        if(m_keystate[key] == 1)
            return true;
        else
            return false;
    }
    return false;
}

void InputHandler::onKeyDown(SDL_Event& g_event)
{
    
}

void InputHandler::onKeyUp(SDL_Event& g_event)
{
    
}