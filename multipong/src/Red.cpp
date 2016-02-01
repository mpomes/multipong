#include "Red.h"
#include <SDL_net.h>
#include <stdio.h>

Red::Red()
{
    //ctor
}

Red::~Red()
{
    //dtor
    SDLNet_Quit();
}

int Red::iniciaServidor(){
    std::string servidor = "192.168.1.1";

    // create a listening TCP socket on port 9999 (server)
    IPaddress ip;
    TCPsocket tcpsock;

    std::cout << "Creando servidor : " << std::endl;

    if(SDLNet_ResolveHost(&ip,NULL,9999)==-1) {
        printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        return -1;
    }

    tcpsock=SDLNet_TCP_Open(&ip);
    if(!tcpsock) {
        printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
        return -2;
    }

    std::cout << "Servidor creado : " << std::endl;

    return 0;
}

int Red::iniciaCliente(std::string host, std::string port){
    return 0;
}

int Red::inicia(){
    /* Inicializamos la Red */
    if(SDLNet_Init()==-1) {
        std::cout << "SDLNet_Init: " << SDLNet_GetError() << std::endl;
        return -2;
    }else{
        std::cout << "Red Inicializada" << std::endl;
    }

    return 0;
}
