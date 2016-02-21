#ifndef PALA_H
#define PALA_H

#include <SDL.h>

class Pala
{
    public:
        Pala();
        virtual ~Pala();

        enum Direcction { UP = 1, DOWN = 2, NONE = 0 };

        //Initialization
        void Init(int player);

        //Update para la IA
        void Update(float deltaTime, Direcction dir);

        //render
        void Render(SDL_Surface* surf);

        SDL_Rect* getRect();
    protected:

    private:
        SDL_Rect rect;
        float speed;
        float delta;
        int player;
};

#endif // PALA_H
