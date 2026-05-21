#include "particula.h"

Particula::Particula()
{
    x = 0;
    y = 0;

    vx = 0;
    vy = 0;

    masa = 1;
    radio = 5;
}

Particula::Particula(float posX,
                     float posY,
                     float velX,
                     float velY,
                     float m,
                     float r)
{
    x = posX;
    y = posY;

    vx = velX;
    vy = velY;

    masa = m;
    radio = r;
}

void Particula::mover(float dt)
{
    x = x + vx * dt;
    y = y + vy * dt;
}

void Particula::rebotar(float anchoCaja, float altoCaja)
{
    if(x - radio <= 0)
    {
        x = radio;
        vx = -vx;
    }

    if(x + radio >= anchoCaja)
    {
        x = anchoCaja - radio;
        vx = -vx;
    }

    if(y - radio <= 0)
    {
        y = radio;
        vy = -vy;
    }

    if(y + radio >= altoCaja)
    {
        y = altoCaja - radio;
        vy = -vy;
    }
}

float Particula::getX()
{
    return x;
}

float Particula::getY()
{
    return y;
}

float Particula::getVx()
{
    return vx;
}

float Particula::getVy()
{
    return vy;
}

float Particula::getMasa()
{
    return masa;
}

float Particula::getRadio()
{
    return radio;
}

void Particula::setX(float posX)
{
    x = posX;
}

void Particula::setY(float posY)
{
    y = posY;
}

void Particula::setVx(float velX)
{
    vx = velX;
}

void Particula::setVy(float velY)
{
    vy = velY;
}

void Particula::setMasa(float m)
{
    masa = m;
}

void Particula::setRadio(float r)
{
    radio = r;
}