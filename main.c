#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gImage = NULL;

int main(int argc, char *argv[])
{

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Create a window with the specified position, dimensions, and flags
  gWindow = SDL_CreateWindow("SDL Tutorial",
                             SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED,
                             SCREEN_WIDTH, SCREEN_HEIGHT,
                             SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

  if (gWindow == NULL)
  {
    printf("Window could not be created! SDL_Error: %s\n",SDL_GetError());
    return 1;
  }

  // Get window surface - Get the SDL surface associated with the window.
  // https://wiki.libsdl.org/SDL_GetWindowSurface
  gScreenSurface = SDL_GetWindowSurface(gWindow);

  // SDL_Event - A union that contains structures for the different event types.
  // https://wiki.libsdl.org/SDL_Event
  SDL_Event event;
  bool running = true;

  while (running)
  {
    // Poll for currently pending events.
    // https://wiki.libsdl.org/SDL_PollEvent
    while (SDL_PollEvent(&event))
    {
      // https://wiki.libsdl.org/SDL_EventType
      if (event.type == SDL_QUIT)
      {
        running = false;
      }

      // Fill the surface white - Perform a fast fill of a rectangle with a specific color.
      // https://wiki.libsdl.org/SDL_FillRect
      SDL_FillRect(gScreenSurface,
                   NULL,
                   SDL_MapRGB(gScreenSurface->format, 0x00, 0xFF, 0xFF));

      // Update the surface - Copy the window surface to the screen.
      //  - https://wiki.libsdl.org/SDL_UpdateWindowSurface
      SDL_UpdateWindowSurface(gWindow);

      // Wait two seconds - Wait a specified number of milliseconds before returning.
      //- https://wiki.libsdl.org/SDL_Delay
      // SDL_Delay(5000);
    }
  }

  // Destroy window
  //  - https://wiki.libsdl.org/SDL_DestroyWindow
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;

  // Quit SDL subsystems - Clean up all initialized subsystems.
  //- https://wiki.libsdl.org/SDL_Quit
  SDL_Quit();

  return 0;
}