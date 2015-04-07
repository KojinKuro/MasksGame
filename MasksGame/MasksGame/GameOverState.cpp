//
//  GameOverState.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "GameOverState.h"
#include "GameStatesMachine.h"
#include "MenuState.h"

void GameOverState::update()
{
    if(main_menuButt->update() && InputHandler::Instance()->getMouseButtonState(0))
    {
        GameStatesMachine::Instance()->changeState(new MenuState());
    }
}

void GameOverState::render()
{
    TextureManager::Instance()->renderTexture(text, Game::Instance()->getRenderer(), 0, 0);
    main_menuButt->draw();
}

void GameOverState::onEnter()
{
    song = Mix_LoadMUS("Japan.mp3");
    Mix_PlayMusic(song, -1);
    
    text = TextureManager::Instance()->renderText("GAME OVER!\nHit Enter to exit.", "text.ttf", color, 13, Game::Instance()->getRenderer());
    
    main_menuButt = new ButtonObject("do again", 300, 300, 128, 32);
}

void GameOverState::onExit()
{
    Mix_FreeMusic(song);
    
    main_menuButt->clean();
    delete main_menuButt;
    SDL_DestroyTexture(text);
}