#ifndef RED_H
#define RED_H
#include <iostream>
#include "SDL_net.h"

class Red
{
    public:
        Red();
        virtual ~Red();

        int inicia();

        int iniciaServidor();

        int iniciaCliente(std::string host, int port);

        int playerNumber;

    protected:
        int connectedClients;
        TCPsocket clientes[3];

    private:
};

#endif // RED_H
