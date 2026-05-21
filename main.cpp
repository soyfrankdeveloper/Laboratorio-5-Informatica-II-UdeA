#include "simulacion.h"
#include "particula.h"
#include "obstaculo.h"

int main()
{
    Simulacion s;

    Particula p1(10, 10, 5, 3, 1, 5);
    Particula p2(30, 40, -4, 2, 1, 5);
    Particula p3(70, 20, 3, -5, 1, 5);
    Particula p4(50, 80, -2, -4, 1, 5);

    s.agregarParticula(p1);
    s.agregarParticula(p2);
    s.agregarParticula(p3);
    s.agregarParticula(p4);

    Obstaculo o1(20, 20, 10, 10);
    Obstaculo o2(60, 20, 10, 10);
    Obstaculo o3(20, 60, 10, 10);
    Obstaculo o4(60, 60, 10, 10);

    s.agregarObstaculo(o1);
    s.agregarObstaculo(o2);
    s.agregarObstaculo(o3);
    s.agregarObstaculo(o4);

    float dt = 0.1;

    for(int i = 0; i < 100; i++)
    {
        s.actualizar(dt);

        s.mostrarDatos();

        s.guardarDatos();
    }

    return 0;
}