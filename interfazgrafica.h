#ifndef INTERFAZGRAFICA_H
#define INTERFAZGRAFICA_H

#include <QMainWindow>
<<<<<<< HEAD
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTimer>

#include "escena.h"

=======
#include <QGraphicsScene>
#include <QTimer>

#include "simulacion.h"
#include "escena.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class InterfazGrafica;
}
QT_END_NAMESPACE

>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
class InterfazGrafica : public QMainWindow
{
    Q_OBJECT

<<<<<<< HEAD
=======
public:
    explicit InterfazGrafica(QWidget *parent = nullptr);
    ~InterfazGrafica();

>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
private:

    Escena *escena;

<<<<<<< HEAD
    QWidget *contenedorPrincipal;
    QWidget *panelControles;

    QPushButton *botonIniciar;
    QPushButton *botonPausar;
    QPushButton *botonReiniciar;
    QPushButton *botonLanzar;
    QPushButton *botonSalir;

    QLabel *titulo;
    QLabel *estado;
    QLabel *descripcion;

    QLabel *labelAngulo;
    QLabel *labelVelocidad;
    QLabel *labelMasa;

    QLabel *labelTurno;
    QLabel *labelObstaculos;
    QLabel *labelGanador;

    QLineEdit *entradaAngulo;
    QLineEdit *entradaVelocidad;
    QLineEdit *entradaMasa;

    QTimer *timerPanel;

public:

    explicit InterfazGrafica(QWidget *parent = nullptr);
    ~InterfazGrafica();

private slots:

    void iniciarSimulacion();
    void pausarSimulacion();
    void reiniciarSimulacion();
    void lanzarProyectil();

    void actualizarPanel();
};

#endif
=======
    Ui::InterfazGrafica *ui;

    QGraphicsScene *scene;

    QTimer *timer;

    Simulacion simulacion;
};

#endif
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
