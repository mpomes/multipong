#include "Game.h"

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

    numPlayers = _numberPlayers;

    red.iniciaServidor(9999);

    red.esperaClientes(numPlayers - 1);
}


void Game::iniciaCliente(SDL_Window *win, std::string host, int port){
    sur = SDL_GetWindowSurface(win);

    //Iniciamos conexion de red
    red.inicia();

    red.iniciaCliente(host, port);
}
