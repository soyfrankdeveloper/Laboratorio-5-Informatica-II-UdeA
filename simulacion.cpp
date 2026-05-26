#include <iostream>
#include <fstream>
#include "simulacion.h"

using namespace std;

Simulacion::Simulacion()
{
    cantidad = 0;
    cantidadObstaculos = 0;

    anchoCaja = 600;
    altoCaja = 600;

    tiempo = 0;

    for(int i = 0; i < 4; i++)
    {
        particulas[i].setMasa(0);
        particulas[i].setRadio(0);
        particulas[i].setVx(0);
        particulas[i].setVy(0);
    }

    ofstream archivo;

    archivo.open("datos.txt");
    archivo.close();

    archivo.open("colisiones.txt");
    archivo.close();
}

void Simulacion::agregarParticula(Particula p)
{
    if(cantidad < 4)
    {
        particulas[cantidad] = p;
        cantidad++;
    }
}

void Simulacion::agregarObstaculo(Obstaculo o)
{
    if(cantidadObstaculos < 4)
    {
        obstaculos[cantidadObstaculos] = o;
        cantidadObstaculos++;
    }
}

void Simulacion::prepararProyectil(float x, float y, float vx, float vy, float masa)
{
    cantidad = 4;

    Particula proyectil(x, y, vx, vy, masa, 10);

    particulas[0] = proyectil;

    for(int i = 1; i < 4; i++)
    {
        Particula vacia(0, 0, 0, 0, 0, 0);
        particulas[i] = vacia;
    }
}

void Simulacion::actualizar(float dt)
{
    tiempo = tiempo + dt;

    for(int i = 0; i < cantidad; i++)
    {
        if(particulas[i].getMasa() > 0)
        {
            particulas[i].mover(dt);
            particulas[i].rebotar(anchoCaja, altoCaja);
        }
    }

    revisarObstaculos();
    revisarParticulas();
}

void Simulacion::revisarObstaculos()
{
    string texto;

    for(int i = 0; i < cantidad; i++)
    {
        for(int j = 0; j < cantidadObstaculos; j++)
        {
            if(particulas[i].getMasa() > 0)
            {
                if(colisiones.choqueObstaculo(particulas[i], obstaculos[j], tiempo, texto))
                {
                    guardarColision(texto);
                }
            }
        }
    }
}

void Simulacion::revisarParticulas()
{
    string texto;

    for(int i = 0; i < cantidad; i++)
    {
        for(int j = i + 1; j < cantidad; j++)
        {
            if(colisiones.choqueParticulas(particulas[i], particulas[j], tiempo, texto))
            {
                guardarColision(texto);
            }
        }
    }
}

void Simulacion::mostrarDatos()
{
    cout << "Tiempo: " << tiempo << endl;

    for(int i = 0; i < cantidad; i++)
    {
        if(particulas[i].getMasa() > 0)
        {
            cout << "Particula " << i + 1 << " ";

            cout << "X: "
                 << particulas[i].getX();

            cout << " Y: "
                 << particulas[i].getY();

            cout << " Masa: "
                 << particulas[i].getMasa();

            cout << endl;
        }
    }

    cout << endl;
}

void Simulacion::guardarDatos()
{
    ofstream archivo;

    archivo.open("datos.txt", ios::app);

    for(int i = 0; i < cantidad; i++)
    {
        if(particulas[i].getMasa() > 0)
        {
            archivo << tiempo << " "
                    << i + 1 << " "
                    << particulas[i].getX() << " "
                    << particulas[i].getY() << " "
                    << particulas[i].getVx() << " "
                    << particulas[i].getVy() << " "
                    << particulas[i].getMasa()
                    << endl;
        }
    }

    archivo.close();
}

void Simulacion::guardarColision(string texto)
{
    ofstream archivo;

    archivo.open("colisiones.txt", ios::app);

    archivo << texto << endl;

    archivo.close();
}

int Simulacion::contarObstaculosActivos()
{
    int activos = 0;

    for(int i = 0; i < cantidadObstaculos; i++)
    {
        if(obstaculos[i].estaActivo())
        {
            activos++;
        }
    }

    return activos;
}

Particula& Simulacion::getParticula(int i)
{
    return particulas[i];
}

Obstaculo& Simulacion::getObstaculo(int i)
{
    return obstaculos[i];
}
