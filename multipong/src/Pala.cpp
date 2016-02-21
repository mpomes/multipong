#include "Pala.h"
#include "Constants.h"

Pala::Pala()
{
    //ctor
}

Pala::~Pala()
{
    //dtor
}


//Initialization
void Pala::Init(int _player){
    int _x;
	player = _player;

	// La posición de la pala va en función del jugador
	// Si el jugador es %2 == 0, entonces va la izquierda
	// en caso contrario va a la derecha

	if( (player%2) == 0){
        _x = PALA_WIDTH + (player/2)* PALA_WIDTH;
	}else{
        _x = WIN_WIDTH -2*PALA_WIDTH -PALA_WIDTH*(player/2);
	}

	rect.x = _x;
    rect.w = PALA_WIDTH;
    rect.h = PALA_HEIGHT;
    rect.y = WIN_HEIGHT/2;

	speed = 0.07f;


	//direcciones
	delta = 0;
}

//Update para la IA
void Pala::Update(float deltaTime, Direcction dir){
}

//render
void Pala::Render(SDL_Surface* surf){
    SDL_FillRect(surf,&rect,COLOR_PALA);
}

SDL_Rect* Pala::getRect(){
    return &rect;
}
