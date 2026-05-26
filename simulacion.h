#ifndef SIMULACION_H
#define SIMULACION_H

#include "particula.h"
#include "obstaculo.h"
#include "colisiones.h"
#include <string>

using namespace std;

<<<<<<< HEAD
=======

>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
class Simulacion
{
private:

    Particula particulas[4];

    Obstaculo obstaculos[4];

    int cantidad;
    int cantidadObstaculos;

<<<<<<< HEAD
    float anchoCaja;
    float altoCaja;

=======


    float anchoCaja;
    float altoCaja;


>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
    float tiempo;

    Colisiones colisiones;

public:

    Simulacion();

    void agregarParticula(Particula p);
<<<<<<< HEAD
    void agregarObstaculo(Obstaculo o);

    void prepararProyectil(float x, float y, float vx, float vy, float masa);
=======

    void agregarObstaculo(Obstaculo o);
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9

    void actualizar(float dt);

    void revisarObstaculos();
    void revisarParticulas();

    void mostrarDatos();

    void guardarDatos();
    void guardarColision(string texto);

<<<<<<< HEAD
    int contarObstaculosActivos();

    Obstaculo& getObstaculo(int i);
    Particula& getParticula(int i);
=======
    Obstaculo& getObstaculo(int i);

    Particula& getParticula(int i);



>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
};

#endif
