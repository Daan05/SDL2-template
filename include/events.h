#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "application.h"

enum Keys
{
    ARROW_UP,
    ARROW_DOWN,
    ARROW_LEFT,
    ARROW_RIGHT,
    ESCAPE,
    MOUSE_LEFT,
    MOUSE_RIGHT,
    SPACE
};

class Events
{
public:
    Events(Application* _app);
    ~Events();

    void GetEvents();
    void HandleEvents();
private:
    Application* app;

    SDL_Event event;

    std::vector<Keys> keysDown;
};