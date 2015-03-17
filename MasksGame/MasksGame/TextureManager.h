//
//  TextureManager.h
//  MasksGame
//
//  Created by Charles Kwang on 3/9/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __Tutorial_Game__TextureManager__
#define __Tutorial_Game__TextureManager__

#include <string>
#include <iterator>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <map>

class TextureManager
{
public:
    static TextureManager * Instance();
    std::map<std::string, SDL_Texture*> g_textureMap;
    ~TextureManager();
    bool load(std::string fileName, std::string id, SDL_Renderer * render);
    void draw(std::string id, int xpos, int ypos, int w, int h, SDL_Renderer * render, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(std::string id, int xpos, int ypos, int w, int h, int currRow, int currFrame, SDL_Renderer * render, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    TextureManager() {};
    static TextureManager * g_tInstance;
};

#endif /* defined(__Tutorial_Game__TextureManager__) */
