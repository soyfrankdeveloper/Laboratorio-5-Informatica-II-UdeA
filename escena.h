#ifndef ESCENA_H
#define ESCENA_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
<<<<<<< HEAD
#include <QGraphicsTextItem>
=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
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

<<<<<<< HEAD
    QGraphicsTextItem *textosResistencia[4];

    int turnoActual;
    int ultimoJugador;
    int ganador;

    bool juegoTerminado;

=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
public:

    Escena(QWidget *parent = nullptr);

    void inicializar();

    void iniciar();
    void pausar();
    void reiniciar();

<<<<<<< HEAD
    void lanzar(float angulo, float velocidad, float masa);

    void actualizarObstaculos();

    int getTurnoActual();
    int getObstaculosActivos();
    int getGanador();
    bool estaTerminado();

=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
public slots:

    void actualizarAnimacion();
};

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
