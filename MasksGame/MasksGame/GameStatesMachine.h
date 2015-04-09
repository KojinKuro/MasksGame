//
//  GameStatesMachine.h
//  MasksGame
//
//  Created by Charles Kwang on 3/16/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#ifndef __MasksGame__GameStatesMachine__
#define __MasksGame__GameStatesMachine__

#include "GameStates.h"

class GameStatesMachine
{
public:
    static GameStatesMachine* Instance();
    
    void update();
    void render();
    
    std::string getStateID();
    
    void popState();
    void pushState(GameStates * gamestate);
    void changeState(GameStates * gamestate);
    
    ~GameStatesMachine();
private:
    static GameStatesMachine* g_instance;
    GameStatesMachine() {}
    
    std::vector<GameStates*> m_stateList;
};

#endif /* defined(__MasksGame__GameStatesMachine__) */
