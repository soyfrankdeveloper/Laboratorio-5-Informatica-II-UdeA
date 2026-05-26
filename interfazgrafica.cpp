#include "interfazgrafica.h"
#include "ui_interfazgrafica.h"

InterfazGrafica::InterfazGrafica(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InterfazGrafica)
{
    ui->setupUi(this);

    escena = new Escena(this);

    escena->iniciar();

    setCentralWidget(escena);
}

InterfazGrafica::~InterfazGrafica()
{
    delete ui;
}