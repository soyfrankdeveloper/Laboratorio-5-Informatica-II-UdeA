#include "obstaculo.h"

Obstaculo::Obstaculo()
{
    x = 0;
    y = 0;
    ancho = 10;
    alto = 10;
<<<<<<< HEAD

    resistencia = 100;
    activo = true;
=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
}

Obstaculo::Obstaculo(float posX, float posY, float a, float h)
{
    x = posX;
    y = posY;
    ancho = a;
    alto = h;
<<<<<<< HEAD

    resistencia = 100;
    activo = true;
=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
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
<<<<<<< HEAD

float Obstaculo::getResistencia()
{
    return resistencia;
}

bool Obstaculo::estaActivo()
{
    return activo;
}

void Obstaculo::recibirDanio(float danio)
{
    resistencia = resistencia - danio;

    if(resistencia <= 0)
    {
        resistencia = 0;
        activo = false;
    }
}
=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
