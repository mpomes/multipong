#include "Red.h"
#include <SDL_net.h>
#include <stdio.h>

Red::Red()
{
    //ctor
    connectedClients = 0;
}

Red::~Red()
{
    //dtor
    SDLNet_Quit();
}

int Red::iniciaServidor(){
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

    playerNumber = 0;


    std::cout << "Esperando cliente : " << std::endl;
    //Esperar conexion de usuarios
    while(connectedClients<3){
        clientes[connectedClients]=SDLNet_TCP_Accept(tcpsock);
        if(clientes[connectedClients]) {
            //Enviamos el número de cliente
            std::cout << "Cliente conectado :" << connectedClients << std::endl;
            connectedClients++;
        }
    }


    return 0;
}

int Red::iniciaCliente(std::string host, int port){
    // connect to localhost at port 9999 using TCP (client)
    IPaddress ip;
    TCPsocket tcpsock;

    if(SDLNet_ResolveHost(&ip,host.c_str(),port)==-1) {
        printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        return -1;
    }

    tcpsock=SDLNet_TCP_Open(&ip);
    if(!tcpsock) {
        printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
        return -1;
    }

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
