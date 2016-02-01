#ifndef RED_H
#define RED_H
#include <iostream>


class Red
{
    public:
        Red();
        virtual ~Red();

        int inicia();

        int iniciaServidor();

        int iniciaCliente(std::string host, std::string port);

    protected:

    private:
};

#endif // RED_H
