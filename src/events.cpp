#include "events.h"

Events::Events(Application* _app)
{
    app = _app;
}

Events::~Events()
{

}

void Events::GetEvents()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            if (!std::count(keysDown.begin(), keysDown.end(), ESCAPE))
            {
                keysDown.push_back(ESCAPE);
            }
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                if (!std::count(keysDown.begin(), keysDown.end(), ESCAPE))
                {
                    keysDown.push_back(ESCAPE);
                }
                break;
            }
            else if (event.key.keysym.sym == SDLK_LEFT)
            {
                if (!std::count(keysDown.begin(), keysDown.end(), ARROW_LEFT))
                {
                    keysDown.push_back(ARROW_LEFT);
                }
                break;
            }
            else if (event.key.keysym.sym == SDLK_RIGHT)
            {
                if (!std::count(keysDown.begin(), keysDown.end(), ARROW_RIGHT))
                {
                    keysDown.push_back(ARROW_RIGHT);
                }
                break;
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                if (!std::count(keysDown.begin(), keysDown.end(), ARROW_UP))
                {
                    keysDown.push_back(ARROW_UP);
                }
                break;
            }
            else if (event.key.keysym.sym == SDLK_DOWN)
            {
                if (!std::count(keysDown.begin(), keysDown.end(), ARROW_DOWN))
                {
                    keysDown.push_back(ARROW_DOWN);
                }
                break;
            }
            else if (event.key.keysym.sym == SDLK_SPACE)
            {
                if (!std::count(keysDown.begin(), keysDown.end(), SPACE))
                {
                    keysDown.push_back(SPACE);
                }
                break;
            }
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                if (std::count(keysDown.begin(), keysDown.end(), ESCAPE))
                {
                    keysDown.erase(std::find(keysDown.begin(), keysDown.end(), ESCAPE));
                }
                break;
            }
            else if (event.key.keysym.sym == SDLK_LEFT)
            {
                if (std::count(keysDown.begin(), keysDown.end(), ARROW_LEFT))
                {
                    
                    keysDown.erase(std::find(keysDown.begin(), keysDown.end(), ARROW_LEFT));
                }
                break;
            }
            else if (event.key.keysym.sym == SDLK_RIGHT)
            {
                if (std::count(keysDown.begin(), keysDown.end(), ARROW_RIGHT))
                {
                   keysDown.erase(std::find(keysDown.begin(), keysDown.end(), ARROW_RIGHT));
                }
                break;
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                if (std::count(keysDown.begin(), keysDown.end(), ARROW_UP))
                {
                    keysDown.erase(std::find(keysDown.begin(), keysDown.end(), ARROW_UP));
                }
                break;
            }
            else if (event.key.keysym.sym == SDLK_DOWN)
            {
                if (std::count(keysDown.begin(), keysDown.end(), ARROW_DOWN))
                {
                    keysDown.erase(std::find(keysDown.begin(), keysDown.end(), ARROW_DOWN));
                }
                break;
            }
            else if (event.key.keysym.sym == SDLK_SPACE)
            {
                if (std::count(keysDown.begin(), keysDown.end(), SPACE))
                {
                    keysDown.erase(std::find(keysDown.begin(), keysDown.end(), SPACE));
                }
                break;
            }
        }
    }
}

void Events::HandleEvents()
{
    for (Keys key : keysDown)
    {
        switch (key)
        {
        case ESCAPE:
            app->quit = true;
            break;
        case ARROW_LEFT:
            app->player->MoveX(-4);
            break;
        case ARROW_RIGHT:
            app->player->MoveX(4);
            break;
        case ARROW_UP:
            //app->player->MoveY(4);
            break;
        case ARROW_DOWN:
            //app->player->MoveY(-4);
            break;
        case SPACE:
            app->player->Jump();
            break;
        default:
            break;
        }
    }
}