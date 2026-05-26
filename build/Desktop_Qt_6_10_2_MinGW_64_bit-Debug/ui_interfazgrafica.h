/********************************************************************************
** Form generated from reading UI file 'interfazgrafica.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFAZGRAFICA_H
#define UI_INTERFAZGRAFICA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfazGrafica
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InterfazGrafica)
    {
        if (InterfazGrafica->objectName().isEmpty())
            InterfazGrafica->setObjectName("InterfazGrafica");
        InterfazGrafica->resize(800, 600);
        centralwidget = new QWidget(InterfazGrafica);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 801, 561));
        InterfazGrafica->setCentralWidget(centralwidget);
        menubar = new QMenuBar(InterfazGrafica);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        InterfazGrafica->setMenuBar(menubar);
        statusbar = new QStatusBar(InterfazGrafica);
        statusbar->setObjectName("statusbar");
        InterfazGrafica->setStatusBar(statusbar);

        retranslateUi(InterfazGrafica);

        QMetaObject::connectSlotsByName(InterfazGrafica);
    } // setupUi

    void retranslateUi(QMainWindow *InterfazGrafica)
    {
        InterfazGrafica->setWindowTitle(QCoreApplication::translate("InterfazGrafica", "InterfazGrafica", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfazGrafica: public Ui_InterfazGrafica {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZGRAFICA_H
