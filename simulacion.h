#ifndef SIMULACION_H
#define SIMULACION_H

#include "particula.h"
#include "obstaculo.h"
#include "colisiones.h"
#include <string>

using namespace std;


class Simulacion
{
private:

    Particula particulas[4];

    Obstaculo obstaculos[4];

    int cantidad;
    int cantidadObstaculos;



    float anchoCaja;
    float altoCaja;


    float tiempo;

    Colisiones colisiones;

public:

    Simulacion();

    void agregarParticula(Particula p);

    void agregarObstaculo(Obstaculo o);

    void actualizar(float dt);

    void revisarObstaculos();
    void revisarParticulas();

    void mostrarDatos();

    void guardarDatos();
    void guardarColision(string texto);

};

#endif
