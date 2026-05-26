#ifndef ESCENA_H
#define ESCENA_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
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

public:

    Escena(QWidget *parent = nullptr);

    void inicializar();

    void iniciar();
    void pausar();
    void reiniciar();

public slots:

    void actualizarAnimacion();
};

#endif