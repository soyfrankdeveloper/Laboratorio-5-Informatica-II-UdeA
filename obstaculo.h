#ifndef OBSTACULO_H
#define OBSTACULO_H

class Obstaculo
{
private:

    float x;
    float y;
    float ancho;
    float alto;

<<<<<<< HEAD
    float resistencia;
    bool activo;

=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
public:

    Obstaculo();

    Obstaculo(float posX, float posY, float a, float h);

    float getX();
    float getY();
    float getAncho();
    float getAlto();
<<<<<<< HEAD

    float getResistencia();
    bool estaActivo();

    void recibirDanio(float danio);
=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
};

#endif
