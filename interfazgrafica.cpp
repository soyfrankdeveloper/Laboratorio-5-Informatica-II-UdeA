#include "interfazgrafica.h"
#include "ui_interfazgrafica.h"

InterfazGrafica::InterfazGrafica(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InterfazGrafica)
{
    ui->setupUi(this);
}

InterfazGrafica::~InterfazGrafica()
{
    delete ui;
}
