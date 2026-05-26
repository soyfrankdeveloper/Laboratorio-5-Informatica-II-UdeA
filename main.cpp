#include "interfazgrafica.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InterfazGrafica w;

    w.show();

    return a.exec();
}