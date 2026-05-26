#ifndef OBSTACULO_H
#define OBSTACULO_H

class Obstaculo
{
private:

    float x;
    float y;
    float ancho;
    float alto;

    float resistencia;
    bool activo;

public:

    Obstaculo();

    Obstaculo(float posX, float posY, float a, float h);

    float getX();
    float getY();
    float getAncho();
    float getAlto();

    float getResistencia();
    bool estaActivo();

    void recibirDanio(float danio);
};

#endif
