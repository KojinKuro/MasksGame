//
//  maingame.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "Game.h"
#include "InputHandler.h"
#include "GameStatesMachine.h"
#include "PlayState.h"
#include "MenuState.h"

Game* Game::g_instance = 0;

Game* Game::Instance()
{
    if(g_instance ==0)
        g_instance = new Game();
    return g_instance;
}

Game::Game()
{
    
}

Game::~Game()
{
    
}

void Game::init(const char* title, int x, int y, int w, int h, bool fullScreen)
{
    //check if the game is running or not
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return;
    
    int flag = SDL_WINDOW_SHOWN;
    if(fullScreen)
        flag = SDL_WINDOW_FULLSCREEN;
    
    //creates game
    g_window = SDL_CreateWindow(title, x, y, w, h, flag);
    if(g_window != 0)
    {
        g_renderer = SDL_CreateRenderer(g_window, -1, 0);
        if(g_renderer !=0)
        {
            SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
        }
        else
        {
            return;
        }
    }
    else
        return;
    
    GameStatesMachine::Instance()->pushState(new MenuState());
    
    g_running = true;
}

void Game::update()
{
    InputHandler::Instance()->update();
    GameStatesMachine::Instance()->update();
}

void Game::handleEvents()
{
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
        GameStatesMachine::Instance()->changeState(new PlayState());
}

void Game::render()
{
    SDL_RenderClear(g_renderer);
    
    GameStatesMachine::Instance()->render();
    
    SDL_RenderPresent(g_renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(g_window);
    SDL_DestroyRenderer(g_renderer);
    
    SDL_Quit();
}