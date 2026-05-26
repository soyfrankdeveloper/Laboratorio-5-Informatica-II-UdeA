#include "interfazgrafica.h"

InterfazGrafica::InterfazGrafica(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Simulacion de particulas");
    resize(950, 650);

    contenedorPrincipal = new QWidget(this);

    QHBoxLayout *layoutPrincipal = new QHBoxLayout(contenedorPrincipal);

    escena = new Escena(this);

    panelControles = new QWidget(this);
    panelControles->setFixedWidth(280);

    QVBoxLayout *layoutControles = new QVBoxLayout(panelControles);

    titulo = new QLabel("Controles", this);

    descripcion = new QLabel("Juego por turnos con proyectiles, obstaculos y colisiones.", this);
    descripcion->setWordWrap(true);

    estado = new QLabel("Estado: detenido", this);

    labelTurno = new QLabel("Turno: Jugador 1", this);
    labelObstaculos = new QLabel("Obstaculos activos: 4", this);
    labelGanador = new QLabel("Ganador: ninguno", this);

    labelAngulo = new QLabel("Angulo:", this);
    labelVelocidad = new QLabel("Velocidad:", this);
    labelMasa = new QLabel("Masa:", this);

    entradaAngulo = new QLineEdit(this);
    entradaVelocidad = new QLineEdit(this);
    entradaMasa = new QLineEdit(this);

    entradaAngulo->setText("45");
    entradaVelocidad->setText("10");
    entradaMasa->setText("5");

    botonIniciar = new QPushButton("Iniciar", this);
    botonPausar = new QPushButton("Pausar", this);
    botonReiniciar = new QPushButton("Reiniciar", this);
    botonLanzar = new QPushButton("Lanzar", this);
    botonSalir = new QPushButton("Salir", this);

    layoutControles->addWidget(titulo);
    layoutControles->addWidget(descripcion);
    layoutControles->addSpacing(10);

    layoutControles->addWidget(labelTurno);
    layoutControles->addWidget(labelObstaculos);
    layoutControles->addWidget(labelGanador);

    layoutControles->addSpacing(15);

    layoutControles->addWidget(labelAngulo);
    layoutControles->addWidget(entradaAngulo);

    layoutControles->addWidget(labelVelocidad);
    layoutControles->addWidget(entradaVelocidad);

    layoutControles->addWidget(labelMasa);
    layoutControles->addWidget(entradaMasa);

    layoutControles->addSpacing(15);

    layoutControles->addWidget(botonLanzar);
    layoutControles->addWidget(botonIniciar);
    layoutControles->addWidget(botonPausar);
    layoutControles->addWidget(botonReiniciar);
    layoutControles->addWidget(botonSalir);

    layoutControles->addSpacing(15);
    layoutControles->addWidget(estado);
    layoutControles->addStretch();

    layoutPrincipal->addWidget(escena);
    layoutPrincipal->addWidget(panelControles);

    setCentralWidget(contenedorPrincipal);

    connect(botonIniciar, &QPushButton::clicked,
            this, &InterfazGrafica::iniciarSimulacion);

    connect(botonPausar, &QPushButton::clicked,
            this, &InterfazGrafica::pausarSimulacion);

    connect(botonReiniciar, &QPushButton::clicked,
            this, &InterfazGrafica::reiniciarSimulacion);

    connect(botonLanzar, &QPushButton::clicked,
            this, &InterfazGrafica::lanzarProyectil);

    connect(botonSalir, &QPushButton::clicked,
            this, &InterfazGrafica::close);

    timerPanel = new QTimer(this);

    connect(timerPanel, &QTimer::timeout,
            this, &InterfazGrafica::actualizarPanel);

    timerPanel->start(200);

    actualizarPanel();
}

InterfazGrafica::~InterfazGrafica()
{
}

void InterfazGrafica::iniciarSimulacion()
{
    escena->iniciar();

    estado->setText("Estado: ejecutando");
}

void InterfazGrafica::pausarSimulacion()
{
    escena->pausar();

    estado->setText("Estado: pausado");
}

void InterfazGrafica::reiniciarSimulacion()
{
    escena->reiniciar();

    estado->setText("Estado: reiniciado");

    actualizarPanel();
}

void InterfazGrafica::lanzarProyectil()
{
    float angulo = entradaAngulo->text().toFloat();
    float velocidad = entradaVelocidad->text().toFloat();
    float masa = entradaMasa->text().toFloat();

    escena->lanzar(angulo, velocidad, masa);

    estado->setText("Estado: proyectil lanzado");

    actualizarPanel();
}

void InterfazGrafica::actualizarPanel()
{
    labelTurno->setText("Turno: Jugador " + QString::number(escena->getTurnoActual()));

    labelObstaculos->setText("Obstaculos activos: " + QString::number(escena->getObstaculosActivos()));

    if(escena->estaTerminado())
    {
        labelGanador->setText("Ganador: Jugador " + QString::number(escena->getGanador()));
        estado->setText("Estado: juego terminado");
    }
    else
    {
        labelGanador->setText("Ganador: ninguno");
    }
}
