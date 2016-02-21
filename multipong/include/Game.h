#ifndef GAME_H
#define GAME_H


#include "Red.h"
#include "Pala.h"
#include <vector>


class Game
{
    public:
        Game();
        virtual ~Game();

        void iniciaServidorJugador(SDL_Window *win, int numberPlayers, int port);
        void iniciaCliente(SDL_Window *win, std::string host, int port);
    protected:

    private:

        Red red;
        SDL_Surface *sur;

        int numPlayers;
        std::vector<Pala*> palas;


};

#endif // GAME_H
