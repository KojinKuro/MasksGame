//
//  InputHandler.h
//  MasksGame
//
//  Created by Charles Kwang on 3/11/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __Tutorial_Game__InputHandler__
#define __Tutorial_Game__InputHandler__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "Vector2D.h"

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler
{
private:
    static InputHandler * p_instance;
    InputHandler()
    {
        newKeyState = SDL_GetKeyboardState(&this->length);
        m_keystate = new Uint8[this->length];
        for(int i=0;i<3;++i)
            m_mouseStates.push_back(false);
    }
    SDL_Event event;
    
    //keyboard is up or down
    int length;
    const Uint8* newKeyState;
    Uint8 * m_keystate;
    
    //mouse helper stuff
    std::vector<bool> m_mouseStates;
    Vector2D * m_mousePosition = new Vector2D(0,0);
public:
    //stuff for Collider2D mouse
    Vector2D getPosition() {return *getMousePosition();}
    int getWidth() {return 0;}
    int getHeight() {return 0;}
    
    static InputHandler * Instance();
    void update();
    void clean();
    
    //keyboards
    bool isKeyDown(SDL_Scancode key);
    bool onKeyDown(SDL_Scancode key);
    bool onKeyUp(SDL_Scancode key);
    
    //mouse
    bool getMouseButtonState(int mouseButton){return m_mouseStates[mouseButton];}
    Vector2D * getMousePosition() {return m_mousePosition;}
    void onMouseMove(SDL_Event& g_event);
    void onMouseButtonDown(SDL_Event& g_event);
    void onMouseButtonUp(SDL_Event& g_event);
    
};

#endif /* defined(__Tutorial_Game__InputHandler__) */
