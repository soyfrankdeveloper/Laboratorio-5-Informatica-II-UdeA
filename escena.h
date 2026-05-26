#ifndef ESCENA_H
#define ESCENA_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QTimer>

#include "simulacion.h"

class Escena : public QGraphicsView
{
    Q_OBJECT

private:

    QGraphicsScene *scene;

    QTimer *timer;

    Simulacion simulacion;

    QGraphicsEllipseItem *particulasGraficas[4];

    QGraphicsRectItem *obstaculosGraficos[4];

    QGraphicsTextItem *textosResistencia[4];

    int turnoActual;
    int ultimoJugador;
    int ganador;

    bool juegoTerminado;

public:

    Escena(QWidget *parent = nullptr);

    void inicializar();

    void iniciar();
    void pausar();
    void reiniciar();

    void lanzar(float angulo, float velocidad, float masa);

    void actualizarObstaculos();

    int getTurnoActual();
    int getObstaculosActivos();
    int getGanador();
    bool estaTerminado();

public slots:

    void actualizarAnimacion();
};

#endif
