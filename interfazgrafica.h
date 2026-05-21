#ifndef INTERFAZGRAFICA_H
#define INTERFAZGRAFICA_H

#include <QMainWindow>

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
    ~InterfazGrafica() override;

private:
    Ui::InterfazGrafica *ui;
};
#endif // INTERFAZGRAFICA_H
