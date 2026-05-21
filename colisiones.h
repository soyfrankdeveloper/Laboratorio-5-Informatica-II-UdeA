#ifndef COLISIONES_H
#define COLISIONES_H

#include "particula.h"
#include "obstaculo.h"
#include <string>

using namespace std;

class Colisiones
{
private:

    float restitucion;

public:

    Colisiones();

    bool choqueObstaculo(Particula &p, Obstaculo &o, float tiempo, string &texto);
    bool choqueParticulas(Particula &p1, Particula &p2, float tiempo, string &texto);

    float distancia(float x1, float y1, float x2, float y2);
};

#endif
