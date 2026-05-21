#include "obstaculo.h"

Obstaculo::Obstaculo()
{
    x = 0;
    y = 0;
    ancho = 10;
    alto = 10;
}

Obstaculo::Obstaculo(float posX, float posY, float a, float h)
{
    x = posX;
    y = posY;
    ancho = a;
    alto = h;
}

float Obstaculo::getX()
{
    return x;
}

float Obstaculo::getY()
{
    return y;
}

float Obstaculo::getAncho()
{
    return ancho;
}

float Obstaculo::getAlto()
{
    return alto;
}
