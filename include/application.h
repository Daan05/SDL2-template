#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

#include "player.h"

class Application
{
public:
    Application(const char* title);
    ~Application();

    void ClearScreen();
    void Render();
    void Update();
    
    void Exit();

    bool quit;

    Player* player;

private:
    const int SCREENWIDTH = 1080;
    const int SCREENHEIGHT = 600;

    SDL_Window* window;
    SDL_Renderer* renderer;
};