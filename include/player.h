#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Player
{
public:
    Player();
    ~Player() = default;

    void Render(SDL_Renderer* renderer);

    void MoveX(float _x);
    void MoveY(float _y);

    void HandleGravity();
    void Jump();
private:
    float x;
    float y;
    SDL_Rect playerRect;

    float gravity;
};