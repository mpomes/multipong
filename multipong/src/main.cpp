#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <SDL_net.h>
#include "Game.h"

int main(int argc, char** argv){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Multipong!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Surface *sur = SDL_GetWindowSurface(win);

    Game* game = new Game();
    game->play(win, sur);

    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
