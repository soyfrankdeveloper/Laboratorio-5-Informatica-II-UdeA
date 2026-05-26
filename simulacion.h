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

    void prepararProyectil(float x, float y, float vx, float vy, float masa);

    void actualizar(float dt);

    void revisarObstaculos();
    void revisarParticulas();

    void mostrarDatos();

    void guardarDatos();
    void guardarColision(string texto);

    int contarObstaculosActivos();

    Obstaculo& getObstaculo(int i);
    Particula& getParticula(int i);
};

#endif
