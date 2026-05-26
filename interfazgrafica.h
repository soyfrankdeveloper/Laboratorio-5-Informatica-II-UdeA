#ifndef INTERFAZGRAFICA_H
#define INTERFAZGRAFICA_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTimer>

#include "escena.h"

class InterfazGrafica : public QMainWindow
{
    Q_OBJECT

private:

    Escena *escena;

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
