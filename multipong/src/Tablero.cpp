#include "Tablero.h"
#include <stdlib.h>
#include <math.h>
#include "Constants.h"
#include <iostream>

Tablero::Tablero()
{
    //ctor
}

Tablero::~Tablero()
{
    //dtor
}

void Tablero::init(int w)
{
    midaTablero.x = WIN_WIDTH/2;
    midaTablero.y = 0;
    midaTablero.h = WIN_HEIGHT;
    midaTablero.w = 5;
}

void Tablero::render(SDL_Surface *sur)
{
    SDL_FillRect(sur,&midaTablero,0xFFFFFF);
}
