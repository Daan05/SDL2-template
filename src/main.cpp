#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "application.h"
#include "events.h"

// Main function
int main(int argv, char* args[])
{
    // Application class, renders the game
    Application app("Hello SDL");

    // Events class, handles the events
    Events events(&app);

    int timer = 0;

    // Game looop
    while (!app.quit)
    {
        // Start timer
        timer = (int) SDL_GetTicks64();

        // Check events
        events.GetEvents();
        // Handle the events
        events.HandleEvents();
        
        // Clear the screen
        app.ClearScreen();
        // Render stuff on screen
        app.Run();
        // Update
        app.UpdateScreen();

        // Framerate ~60
        while (timer + 1000 / 60 > (int) SDL_GetTicks64())
        {
            SDL_Delay(1);
        }
    }
    // Exit
    app.Exit();
    return 0;
}