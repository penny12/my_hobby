#include "SDL.h"
#include <iostream>
using namespace std;

int main()
{
  SDL_Window *pWindow;
  SDL_Renderer *pRenderer;
  SDL_Init(SDL_INIT_EVERYTHING);

  if(SDL_CreateWindowAndRenderer(100, 100, 0, &pWindow, &pRenderer))
  {
    cout << SDL_GetError() << "\n";
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return 0;
  }

  SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
  // pWindow = SDL_CreateWindow("test", 0, 0, 100, 100, SDL_WINDOW_SHOWN);

  SDL_RenderClear(pRenderer);
    
  SDL_RenderPresent(pRenderer);

  SDL_Delay(3000);
  SDL_DestroyWindow(pWindow);
  SDL_Quit();

  // while(true)
  // {
  //   SDL_Event e;
  //   if(SDL_PollEvent(&e))
  //   {
  //     if(e.type == SDL_QUIT)
  //     {
  //       break;
  //     }
  //   }

  //   SDL_RenderClear(pRenderer);
    
  //   SDL_RenderPresent(pRenderer);
  // }

  // SDL_DestroyRenderer(pRenderer);
  // SDL_DestroyWindow(pWindow);
  // SDL_Quit();
}


