#ifndef PALA_H
#define PALA_H

#include "SDL.h"

class Pala
{
    public:
        Pala();
        virtual ~Pala();

        int GetY();
        int GetX();
        void SetPosition(int x, int y);

        void Render(SDL_Surface *sur);

    protected:
        SDL_Rect rec;
    private:
};

#endif // PALA_H
