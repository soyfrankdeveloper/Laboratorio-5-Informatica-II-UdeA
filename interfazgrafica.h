#ifndef INTERFAZGRAFICA_H
#define INTERFAZGRAFICA_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "simulacion.h"
#include "escena.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class InterfazGrafica;
}
QT_END_NAMESPACE

class InterfazGrafica : public QMainWindow
{
    Q_OBJECT

public:
    explicit InterfazGrafica(QWidget *parent = nullptr);
    ~InterfazGrafica();

private:

    Escena *escena;

    Ui::InterfazGrafica *ui;

    QGraphicsScene *scene;

    QTimer *timer;

    Simulacion simulacion;
};

#endif