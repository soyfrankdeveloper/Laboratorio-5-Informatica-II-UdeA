#include "escena.h"

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

    inicializar();

    connect(timer, &QTimer::timeout,
            this, &Escena::actualizarAnimacion);
}

void Escena::inicializar()
{
    scene->addRect(0, 0, 600, 600, QPen(Qt::white));

    Particula p1(100, 100, 4, 3, 1, 10);
    Particula p2(300, 100, -3, 2, 1, 10);
    Particula p3(200, 300, 2, -4, 1, 10);
    Particula p4(400, 400, -2, -3, 1, 10);

    simulacion.agregarParticula(p1);
    simulacion.agregarParticula(p2);
    simulacion.agregarParticula(p3);
    simulacion.agregarParticula(p4);

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
        particulasGraficas[i] =
            scene->addEllipse(0, 0, 20, 20);

        obstaculosGraficos[i] =
            scene->addRect(0, 0, 60, 60);
    }

    particulasGraficas[0]->setBrush(Qt::red);
    particulasGraficas[1]->setBrush(Qt::blue);
    particulasGraficas[2]->setBrush(Qt::green);
    particulasGraficas[3]->setBrush(Qt::yellow);

    obstaculosGraficos[0]->setBrush(Qt::gray);
    obstaculosGraficos[1]->setBrush(Qt::gray);
    obstaculosGraficos[2]->setBrush(Qt::gray);
    obstaculosGraficos[3]->setBrush(Qt::gray);

    obstaculosGraficos[0]->setPos(150, 150);
    obstaculosGraficos[1]->setPos(350, 150);
    obstaculosGraficos[2]->setPos(150, 350);
    obstaculosGraficos[3]->setPos(350, 350);
}

void Escena::actualizarAnimacion()
{
    simulacion.actualizar(1);

    for(int i = 0; i < 4; i++)
    {
        Particula &p = simulacion.getParticula(i);

        if(p.getMasa() > 0)
        {
            float r = p.getRadio();

            particulasGraficas[i]->setTransformOriginPoint(r, r);

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
}

void Escena::iniciar()
{
    timer->start(16);
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

    inicializar();

    timer->start(16);
}
