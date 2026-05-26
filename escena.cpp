#include "escena.h"
#include <cmath>
#include <QPen>

Escena::Escena(QWidget *parent)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    setRenderHint(QPainter::Antialiasing);

    setScene(scene);

    setFixedSize(620, 620);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0, 0, 600, 600);
    scene->setBackgroundBrush(Qt::black);

    timer = new QTimer(this);

    turnoActual = 1;
    ultimoJugador = 1;
    ganador = 0;
    juegoTerminado = false;

    inicializar();

    connect(timer, &QTimer::timeout,
            this, &Escena::actualizarAnimacion);
}

void Escena::inicializar()
{
    scene->addRect(0, 0, 600, 600, QPen(Qt::white));

    Obstaculo o1(150, 150, 60, 60);
    Obstaculo o2(350, 150, 60, 60);
    Obstaculo o3(150, 350, 60, 60);
    Obstaculo o4(350, 350, 60, 60);

    simulacion.agregarObstaculo(o1);
    simulacion.agregarObstaculo(o2);
    simulacion.agregarObstaculo(o3);
    simulacion.agregarObstaculo(o4);

    for(int i = 0; i < 4; i++)
    {
        particulasGraficas[i] = scene->addEllipse(0, 0, 20, 20);
        obstaculosGraficos[i] = scene->addRect(0, 0, 60, 60);
        textosResistencia[i] = scene->addText("100");

        particulasGraficas[i]->hide();
    }

    particulasGraficas[0]->setBrush(Qt::red);
    particulasGraficas[1]->setBrush(Qt::blue);
    particulasGraficas[2]->setBrush(Qt::green);
    particulasGraficas[3]->setBrush(Qt::yellow);

    obstaculosGraficos[0]->setBrush(Qt::gray);
    obstaculosGraficos[1]->setBrush(Qt::gray);
    obstaculosGraficos[2]->setBrush(Qt::gray);
    obstaculosGraficos[3]->setBrush(Qt::gray);

    for(int i = 0; i < 4; i++)
    {
        textosResistencia[i]->setDefaultTextColor(Qt::white);
    }

    obstaculosGraficos[0]->setPos(150, 150);
    obstaculosGraficos[1]->setPos(350, 150);
    obstaculosGraficos[2]->setPos(150, 350);
    obstaculosGraficos[3]->setPos(350, 350);

    textosResistencia[0]->setPos(165, 125);
    textosResistencia[1]->setPos(365, 125);
    textosResistencia[2]->setPos(165, 325);
    textosResistencia[3]->setPos(365, 325);
}

void Escena::actualizarAnimacion()
{
    if(juegoTerminado)
    {
        timer->stop();
        return;
    }

    simulacion.actualizar(1);

    simulacion.guardarDatos();

    for(int i = 0; i < 4; i++)
    {
        Particula &p = simulacion.getParticula(i);

        if(p.getMasa() > 0)
        {
            float r = p.getRadio();

            particulasGraficas[i]->setRect(0, 0, r * 2, r * 2);

            particulasGraficas[i]->setPos(
                p.getX() - r,
                p.getY() - r
                );

            particulasGraficas[i]->show();
        }
        else
        {
            particulasGraficas[i]->hide();
        }
    }

    actualizarObstaculos();

    if(simulacion.contarObstaculosActivos() == 0)
    {
        juegoTerminado = true;
        ganador = ultimoJugador;
        timer->stop();
    }
}

void Escena::actualizarObstaculos()
{
    for(int i = 0; i < 4; i++)
    {
        Obstaculo &o = simulacion.getObstaculo(i);

        textosResistencia[i]->setPlainText(QString::number((int)o.getResistencia()));

        if(o.estaActivo())
        {
            obstaculosGraficos[i]->show();
            textosResistencia[i]->show();
        }
        else
        {
            obstaculosGraficos[i]->hide();
            textosResistencia[i]->hide();
        }
    }
}

void Escena::iniciar()
{
    if(juegoTerminado == false)
    {
        timer->start(16);
    }
}

void Escena::pausar()
{
    timer->stop();
}

void Escena::reiniciar()
{
    timer->stop();

    scene->clear();

    simulacion = Simulacion();

    turnoActual = 1;
    ultimoJugador = 1;
    ganador = 0;
    juegoTerminado = false;

    inicializar();
}

void Escena::lanzar(float angulo, float velocidad, float masa)
{
    if(juegoTerminado)
    {
        return;
    }

    timer->stop();

    float pi = 3.14159265;
    float radianes = angulo * pi / 180.0;

    float vx;
    float vy;

    float posX;
    float posY;

    ultimoJugador = turnoActual;

    if(turnoActual == 1)
    {
        posX = 80;
        posY = 520;

        vx = velocidad * cos(radianes);
        vy = -velocidad * sin(radianes);

        turnoActual = 2;
    }
    else
    {
        posX = 520;
        posY = 80;

        vx = -velocidad * cos(radianes);
        vy = velocidad * sin(radianes);

        turnoActual = 1;
    }

    simulacion.prepararProyectil(posX, posY, vx, vy, masa);

    actualizarAnimacion();

    timer->start(16);
}

int Escena::getTurnoActual()
{
    return turnoActual;
}

int Escena::getObstaculosActivos()
{
    return simulacion.contarObstaculosActivos();
}

int Escena::getGanador()
{
    return ganador;
}

bool Escena::estaTerminado()
{
    return juegoTerminado;
}
