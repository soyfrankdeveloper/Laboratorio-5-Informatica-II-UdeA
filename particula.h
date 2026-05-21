#ifndef PARTICULA_H
#define PARTICULA_H

class Particula
{
private:

    float x;
    float y;

    float vx;
    float vy;

    float masa;
    float radio;

public:

    Particula();

    Particula(float posX,
              float posY,
              float velX,
              float velY,
              float m,
              float r);

    void mover(float dt);
    void rebotar(float anchoCaja, float altoCaja);

    float getX();
    float getY();

    float getVx();
    float getVy();

    float getMasa();
    float getRadio();

    void setX(float posX);
    void setY(float posY);

    void setVx(float velX);
    void setVy(float velY);

    void setMasa(float m);
    void setRadio(float r);
};

#endif