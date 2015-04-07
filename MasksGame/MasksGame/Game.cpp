//
//  maingame.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include <iostream>
#include "Game.h"
#include "Player.h"
#include "InputHandler.h"
#include "GameStatesMachine.h"
#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"
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
            SDL_RenderClear(g_renderer);
        }
        else
        {
            return;
        }
    }
    else
        return;
    
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    TTF_Init();
    
    GameStatesMachine::Instance()->pushState(new MenuState());
    
    g_running = true;
}

void Game::update()
{
    InputHandler::Instance()->update();
    GameStatesMachine::Instance()->update();
}

//helper for handleEvents and the changing controls depending on gamestate
enum game_states
{
    eMenu,
    ePlay,
    ePause,
    eOver
};
int hashIt(std::string stringVal)
{
    if(stringVal=="MENU")
        return eMenu;
    if(stringVal=="PLAY")
        return ePlay;
    if(stringVal=="PAUSE")
        return ePause;
    if(stringVal=="OVER")
        return eOver;
    return NULL;
}

//handles the gamestates at the current moment only
void Game::handleEvents()
{
    switch(hashIt(GameStatesMachine::Instance()->getStateID()))
    {
        case eMenu:
            if(!g_running)
                GameStatesMachine::Instance()->popState();
            break;
        case ePlay:
            if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_P))
                GameStatesMachine::Instance()->changeState(new PauseState());
            if(!g_running)
                GameStatesMachine::Instance()->popState();
            break;
        case ePause:
            if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_P))
                GameStatesMachine::Instance()->changeState(new PlayState());
            if(!g_running)
                GameStatesMachine::Instance()->popState();
            break;
        case eOver:
            if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
            {
                GameStatesMachine::Instance()->popState();
                quit();
            }
            if(!g_running)
                GameStatesMachine::Instance()->popState();
            break;
        default:
            break;
    }
}

void Game::render()
{
    SDL_RenderClear(g_renderer);
    
    GameStatesMachine::Instance()->render();
    
    SDL_RenderPresent(g_renderer);
}

void Game::clean()
{
    InputHandler::Instance()->clean();
    
    SDL_DestroyWindow(g_window);
    SDL_DestroyRenderer(g_renderer);
    
    Mix_Quit();
    TTF_Quit();
    
    SDL_Quit();
}