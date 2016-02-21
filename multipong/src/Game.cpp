#include "Game.h"
#include <stdio.h>

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}


void Game::iniciaServidorJugador(SDL_Window *win, int _numberPlayers, int port){
    sur = SDL_GetWindowSurface(win);

    //Iniciamos conexion de red
    red.inicia();

    //Definimos el número de jugadores
    numPlayers = _numberPlayers;

    //Iniciamos el servidor
    red.iniciaServidor(9999);

    int i;
    //Creamos las palas en funcion del numero de jugadores
    for(i=0; i<numPlayers; i++){
        Pala *pala = new Pala();
        pala->Init(i);
        palas.push_back(pala);
    }

    //Esperamos el número de jugadores -1 (porque nosotros somos un jugador)
    red.esperaClientes(numPlayers - 1);

    //Inicio la bola
    bola.Init();

    bool quit = false;
    int lastTime = SDL_GetTicks();
    int currentTime = SDL_GetTicks();
    float deltaTime = 0;

    while(!quit){
        currentTime = SDL_GetTicks();
        deltaTime = (float)(currentTime - lastTime) / 1000;
        lastTime = currentTime;

        //Muevo Bola
        bola.Update(palas, deltaTime);


        //Inicio surface
        SDL_FillRect(sur,NULL,0);


        bola.Render(sur);
        for(i = 0; i<numPlayers;i++){
            palas[i]->Render(sur);
        }

        SDL_Event test_event;
        SDL_Scancode tecla;
        while (SDL_PollEvent(&test_event)) {
            switch (test_event.type) {
            case SDL_KEYDOWN:
                tecla = test_event.key.keysym.scancode;
                if (tecla == SDL_SCANCODE_ESCAPE){
                    quit = true;
                }
                else if(tecla == SDL_SCANCODE_UP){
                    //dir = 1;
                }
                else if(tecla == SDL_SCANCODE_DOWN){
                    //dir = -1;
                }
                break;

            case SDL_QUIT:
                quit = true;
                break;
            }
        }

        SDL_UpdateWindowSurface(win);
        SDL_Delay(100);
    }
}


void Game::iniciaCliente(SDL_Window *win, std::string host, int port){
    sur = SDL_GetWindowSurface(win);

    //Iniciamos conexion de red
    red.inicia();

    red.iniciaCliente(host, port);
}
