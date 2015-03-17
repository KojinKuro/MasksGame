//
//  TextureManager.cpp
//  MasksGame
//
//  Created by Charles Kwang on 3/9/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "TextureManager.h"

TextureManager* TextureManager::g_tInstance = NULL;

TextureManager* TextureManager::Instance()
{
    if(g_tInstance == 0)
        g_tInstance = new TextureManager();
    return g_tInstance;
}

TextureManager::~TextureManager()
{
    std::map<std::string, SDL_Texture*>::iterator mapIt;
    for(mapIt = g_textureMap.begin(); mapIt != g_textureMap.end(); ++mapIt)
        SDL_DestroyTexture(g_textureMap[mapIt->first]);
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer * render)
{
    SDL_Surface * tempSurface = IMG_Load(fileName.c_str());
    if(tempSurface == 0)
        return false;
    
    SDL_Texture * gameTexture = SDL_CreateTextureFromSurface(render, tempSurface);
    
    SDL_free(tempSurface);
    
    if(gameTexture != 0)
    {
        g_textureMap[id] = gameTexture;
        return true;
    }
    return false;
}

void TextureManager::draw(std::string id, int xpos, int ypos, int w, int h, SDL_Renderer * render, SDL_RendererFlip flip)
{
    SDL_Rect sourceRect;
    SDL_Rect destRect;
    
    sourceRect.x = 0;
    sourceRect.y = 0;
    destRect.w = sourceRect.w = w;
    destRect.h = sourceRect.h = h;
    destRect.x = xpos;
    destRect.y = ypos;
    
    SDL_RenderCopyEx(render, g_textureMap[id], &sourceRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int xpos, int ypos, int w, int h, int currRow, int currFrame, SDL_Renderer * render, SDL_RendererFlip flip)
{
    SDL_Rect sourceRect;
    SDL_Rect destRect;
    
    sourceRect.x = w * currFrame;
    sourceRect.y = h * currRow;
    destRect.w = sourceRect.w = w;
    destRect.h = sourceRect.h = h;
    destRect.x = xpos;
    destRect.y = ypos;
    
    SDL_RenderCopyEx(render, g_textureMap[id], &sourceRect, &destRect, 0, 0, flip);
}