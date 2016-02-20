#ifndef GAME_H
#define GAME_H


#include "Red.h"


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

};

#endif // GAME_H
