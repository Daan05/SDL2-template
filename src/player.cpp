#include "player.h"

Player::Player()
{
    x = 200;
    y = 200;
    playerRect = { (int) x, (int) y, 60, 100 };
    gravity = 0;
}

void Player::MoveX(float _x)
{
    x += _x;
    playerRect.x = (int) x;
}

void Player::MoveY(float _y)
{
    y -= _y;
    playerRect.y = (int) y;
}

void Player::Render(SDL_Renderer* renderer)
{
    // Inside
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderFillRect(renderer, &playerRect);
    // Outline
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &playerRect);
}

void Player::HandleGravity()
{
    if (gravity < 12)
    {
        gravity += 0.2f;
    }
    else 
        gravity = 0;

    if (y > 500)
    {
        gravity = 0;
        y = 500;

    }
    MoveY(-gravity);
}

void Player::Jump()
{
    if (y >= 500)
    {
        gravity = -12;
    }
}