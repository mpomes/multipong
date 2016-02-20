#include <SDL.h>
#include <stdio.h>
#include <iostream>
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


    bool somosServidor = false;

    #ifdef SERVIDOR
        somosServidor = true;
        std::cout << "SOMOS SERVIDOR" << SDL_GetError() << std::endl;
    #else
        std::cout << "SOMOS CLIENTE" << SDL_GetError() << std::endl;
    #endif // SERVIDOR

    //Creamos conexion de red
    Red red;
    red.inicia();

    //si somos servidor
    if(somosServidor){
        red.iniciaServidor(9999);

        red.esperaClientes(1);
    }else{
        red.iniciaCliente("localhost", 9999);

    }


    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
