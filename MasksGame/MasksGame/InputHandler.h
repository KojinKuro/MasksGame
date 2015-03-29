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
        for(int i=0;i<3;++i)
            m_mouseStates.push_back(false);
    }
    ~InputHandler() {}
    SDL_Event event;
    
    //keyboard is up or down
    const Uint8* m_keystate;
    
    //mouse helper stuff
    std::vector<bool> m_mouseStates;
    Vector2D * m_mousePosition = new Vector2D(0,0);
public:
    static InputHandler * Instance();
    void update();
    void clean();
    
    //keyboards
    bool isKeyDown(SDL_Scancode key);
    void onKeyDown(SDL_Event& g_event);
    void onKeyUp(SDL_Event& g_event);
    
    //mouse
    bool getMouseButtonState(int mouseButton){return m_mouseStates[mouseButton];}
    Vector2D * getMousePosition() { return m_mousePosition;}
    void onMouseMove(SDL_Event& g_event);
    void onMouseButtonDown(SDL_Event& g_event);
    void onMouseButtonUp(SDL_Event& g_event);
    
};

#endif /* defined(__Tutorial_Game__InputHandler__) */
