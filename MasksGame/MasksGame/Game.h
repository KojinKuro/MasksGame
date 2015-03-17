//
//  maingame.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__maingame__
#define __MasksGame__maingame__

#include <SDL2/SDL.h>

class Game
{
public:
    static Game* Instance();
    bool getRunning() {return g_running;}
    SDL_Renderer* getRenderer() {return g_renderer;}
    
    void init(const char* title, int x, int y, int w, int h, bool fullScreen);
    
    void update();
    void handleEvents();
    void render();
    void quit() {g_running = false;}
    
    void clean();
private:
    static Game* g_instance;
    
    SDL_Window * g_window;
    SDL_Renderer * g_renderer;
    
    Game();
    ~Game();
    
    bool g_running = false;
};

#endif /* defined(__MasksGame__maingame__) */
