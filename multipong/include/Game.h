#ifndef GAME_H
#define GAME_H
#include "Pala.h"
#include "Input.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        int play(SDL_Window *win, SDL_Surface* sur);

    protected:

        Pala palas[4];
        Input input;
        int playernumber;

    private:

        void actualizaJugador();
};

#endif // GAME_H
