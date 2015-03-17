//
//  main.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "Game.h"

int fps = 60;
int SDLDELAY = 1000.0/fps;

int main(int argc, const char * argv[]) {
    Uint32 frameTime, frameStart;
    
    Game::Instance()->init("Masks Game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 640, 480, false);
    
    while(Game::Instance()->getRunning())
    {
        Game::Instance()->update();
        Game::Instance()->handleEvents();
        Game::Instance()->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < SDLDELAY)
            SDL_Delay((int)(SDLDELAY-frameTime));
    }
    Game::Instance()->clean();
    return 0;
}
