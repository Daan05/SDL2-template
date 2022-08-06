#include "application.h"

Application::Application(const char* title)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    quit = false;

    player = new Player();
}

Application::~Application()
{
    
}

void Application::ClearScreen()
{
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderClear(renderer);
}

void Application::Run()
{
    player->HandleGravity();
    player->Render(renderer);
}

void Application::UpdateScreen()
{
    SDL_RenderPresent(renderer);
}

void Application::Exit()
{
    delete player;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}