#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <SDL_net.h>
#include "Game.h"
#include "Red.h"

int main(int argc, char** argv){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window *win = SDL_CreateWindow("Multipong!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }else{
        std::cout << "Ventana Inicializada" << std::endl;
    }

    SDL_Surface *sur = SDL_GetWindowSurface(win);

    //Creamos conexion de red
    Red red;
    red.inicia();

    bool somosServidor = false;
    //si somos servidor
    if(somosServidor){
        red.iniciaServidor();
    }else{
        red.iniciaCliente("127.0.0.1", 9999);
    }


    Game* game = new Game();
    game->play(win, sur, &red);

    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}


