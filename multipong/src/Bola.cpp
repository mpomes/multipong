#include "Bola.h"
#include <stdlib.h>
#include <math.h>
#include "Constants.h"

Bola::Bola()
{
    //ctor
}

Bola::~Bola()
{
    //dtor
}

//Initialization
void Bola::Init(){
    rect.h = BOLA_SIZE;
    rect.w = BOLA_SIZE;
    rect.y = WIN_HEIGHT/2;
    rect.x = WIN_WIDTH/2;
	//Iniciar con un angulo random, pero que nunca sea completamente horizontal o vertical
	int type = rand() % 4;
	switch (type)
	{
	case 0:	//15-75
		angle = rand() % 60 + 15;
		break;
	case 1: //105-165
		angle = rand() % 60 + 105;
		break;
	case 2: //195-255
		angle = rand() % 60 + 195;
		break;
	case 3://285-345
		angle = rand() % 60 + 285;
		break;
	}


	dx = dy = 0.0f;
	speed = 0.4f;
	rebotandoY = rebotandoX =  false;

	speedX = (float)cos(angle*M_PI / 180.0f) * speed;
	speedY = (float)sin(angle*M_PI / 180.0f) * speed;

	MAX_speed = speed *2;
}

//Update para la IA
void Bola::Update(std::vector<Pala*>palas, float deltaTime){
}

//render
void Bola::Render(SDL_Surface* surf){
    SDL_FillRect(surf,&rect,COLOR_BOLA);
}

SDL_Rect* Bola::getRect(){
    return &rect;
}

void Bola::Rebote(){
	//Incremento de la velocidad cada vez que rebota!
	MAX_speed += MAX_speed *0.05f;

	speedX = (float)cos(angle*M_PI / 180.0f) * speed;
	speedY = (float)sin(angle*M_PI / 180.0f) * speed;
	rebotandoX = true;

}
