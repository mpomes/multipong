#include "Game.h"

#define DESPLAZAMIENTO 3

Game::Game()
{
    //ctor
    playernumber = 0;
}

Game::~Game()
{
    //dtor
}

int Game::play(SDL_Window *win, SDL_Surface* sur){
    //Iniciamos red (cliente/servidor)

    bool salir = false;
    while(!salir){
        //Limpiar pantalla
        SDL_FillRect(sur,NULL,0xffffff);

        //Obtenemos inputs usuarios
        input.Update();
        salir = input.exit;

        //Modificamos palas
        actualizaJugador();

        //Enviamos palas a usuarios

        //Pintamos palas
        for(int i=0;i<4;i++){
            Game::palas[i].Render(sur);
        }

        SDL_UpdateWindowSurface(win);

        //Delay
        SDL_Delay(10);
    }

    return 0;
}


void Game::actualizaJugador(){
    if(input.arriba && palas[Game::playernumber].GetY()>DESPLAZAMIENTO){
            palas[playernumber].SetPosition(palas[playernumber].GetX(),
                                            palas[playernumber].GetY() - DESPLAZAMIENTO);
    }

    if(input.abajo && palas[Game::playernumber].GetY()<(480 - DESPLAZAMIENTO - 50)){
            palas[playernumber].SetPosition(palas[playernumber].GetX(),
                                            palas[playernumber].GetY() + DESPLAZAMIENTO);
    }
}
