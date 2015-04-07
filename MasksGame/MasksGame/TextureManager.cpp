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

void TextureManager::renderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(ren, tex, NULL, &dest);
}

/**
 * Render the message we want to display to a texture for drawing
 * @param message The message we want to display
 * @param fontFile The font we want to use to render the text
 * @param color The color we want the text to be
 * @param fontSize The size we want the font to be
 * @param renderer The renderer to load the texture in
 * @return An SDL_Texture containing the rendered message, or nullptr if something went wrong
 */
SDL_Texture* TextureManager::renderText(const std::string &message, const std::string &fontFile,
                        SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
    //Open the font
    TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr){
        return nullptr;
    }
    //We need to first render to a surface as that's what TTF_RenderText
    //returns, then load that surface into a texture
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == nullptr){
        TTF_CloseFont(font);
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr){
    }
    //Clean up the surface and font
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
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

void TextureManager::clean(std::string id)
{
    SDL_DestroyTexture(g_textureMap[id]);
}