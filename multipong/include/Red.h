#ifndef RED_H
#define RED_H
#include "SDL_net.h"
#include <vector>
#include <string.h>
#include <string>
#include <stdio.h>
#define MAX_CLIENTS 8
#define MAX_BUFFER 512

class Red
{
    public:
        Red();
        virtual ~Red();

        int inicia();
        int iniciaServidor(int port);

        int esperaClientes(int nclientes);
        int iniciaCliente(std::string host, int port);

        int clienteRecibeNumero();

        int servidorEnviaNumero(TCPsocket * cliente, int numero);

    protected:
        char buffer[MAX_BUFFER];
        TCPsocket tcpsock;
        int connectedClients;
        TCPsocket clientes[MAX_CLIENTS];

        int envia(TCPsocket* cliente, char* msg);
        int recibe(TCPsocket* cliente, char * msg);
    private:
};

#endif // RED_H
