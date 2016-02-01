#include "Pala.h"

Pala::Pala()
{
    //ctor
    rec.h = 50;
    rec.w = 20;
    rec.x = 0;
    rec.y = 0;
}

Pala::~Pala()
{
    //dtor
}


int Pala::GetY(){
    return rec.y;
}

int Pala::GetX(){
    return rec.x;
}

void Pala::SetPosition(int x, int y){
    rec.x = x;
    rec.y = y;
}

void Pala::Render(SDL_Surface *sur){
    SDL_FillRect(sur,&rec,0x000000);
}
