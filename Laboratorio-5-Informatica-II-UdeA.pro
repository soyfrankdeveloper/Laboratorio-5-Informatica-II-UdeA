QT += widgets

CONFIG += c++17

SOURCES += \
    escena.cpp \
    main.cpp \
    interfazgrafica.cpp \
    particula.cpp \
    simulacion.cpp \
    obstaculo.cpp \
    colisiones.cpp

HEADERS += \
    escena.h \
    interfazgrafica.h \
    particula.h \
    simulacion.h \
    obstaculo.h \
    colisiones.h

FORMS += \
    interfazgrafica.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/Desktop_Qt_6_10_2_MinGW_64_bit-Debug/debug/grafica.py