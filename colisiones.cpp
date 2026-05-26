#include "colisiones.h"
#include <cmath>
<<<<<<< HEAD
#include <string>
=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9

Colisiones::Colisiones()
{
    restitucion = 0.8;
}

float Colisiones::distancia(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    return sqrt(dx * dx + dy * dy);
}

bool Colisiones::choqueObstaculo(Particula &p, Obstaculo &o, float tiempo, string &texto)
{
<<<<<<< HEAD
    if(o.estaActivo() == false)
    {
        return false;
    }

=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
    float px = p.getX();
    float py = p.getY();
    float r  = p.getRadio();

    float izquierda = o.getX();
    float derecha   = o.getX() + o.getAncho();
    float arriba    = o.getY();
    float abajo     = o.getY() + o.getAlto();

    bool tocaX = px + r >= izquierda && px - r <= derecha;
    bool tocaY = py + r >= arriba    && py - r <= abajo;

    if(tocaX && tocaY)
    {
<<<<<<< HEAD
        float velocidadImpacto = sqrt(p.getVx() * p.getVx() + p.getVy() * p.getVy());

        float factorDanio = 0.5;

        float danio = factorDanio * p.getMasa() * velocidadImpacto;

        o.recibirDanio(danio);

=======
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
        float centroX = o.getX() + o.getAncho() / 2;
        float centroY = o.getY() + o.getAlto()  / 2;

        float difX = px - centroX;
        float difY = py - centroY;

        if(fabs(difX) > fabs(difY))
        {
            p.setVx(-p.getVx() * restitucion);

            if(difX > 0)
<<<<<<< HEAD
            {
                p.setX(derecha + r);
            }
            else
            {
                p.setX(izquierda - r);
            }
=======
                p.setX(derecha + r);
            else
                p.setX(izquierda - r);
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
        }
        else
        {
            p.setVy(-p.getVy() * restitucion);

            if(difY > 0)
<<<<<<< HEAD
            {
                p.setY(abajo + r);
            }
            else
            {
                p.setY(arriba - r);
            }
=======
                p.setY(abajo + r);
            else
                p.setY(arriba - r);
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
        }

        texto = "Choque con obstaculo en t=" +
                to_string(tiempo) +
<<<<<<< HEAD
                " danio=" +
                to_string(danio) +
                " resistencia restante=" +
                to_string(o.getResistencia());
=======
                " posicion " +
                to_string(p.getX()) +
                " " +
                to_string(p.getY());
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9

        return true;
    }

    return false;
}

bool Colisiones::choqueParticulas(Particula &p1, Particula &p2, float tiempo, string &texto)
{
    if(p1.getMasa() <= 0 || p2.getMasa() <= 0)
    {
        return false;
    }

    float d = distancia(p1.getX(), p1.getY(), p2.getX(), p2.getY());

    if(d <= p1.getRadio() + p2.getRadio())
    {
        float m1 = p1.getMasa();
        float m2 = p2.getMasa();

        float masaTotal = m1 + m2;

        float nuevaVx = (m1 * p1.getVx() + m2 * p2.getVx()) / masaTotal;
        float nuevaVy = (m1 * p1.getVy() + m2 * p2.getVy()) / masaTotal;

        float nuevaX = (m1 * p1.getX() + m2 * p2.getX()) / masaTotal;
        float nuevaY = (m1 * p1.getY() + m2 * p2.getY()) / masaTotal;

        float nuevoRadio = sqrt(p1.getRadio() * p1.getRadio()
                                + p2.getRadio() * p2.getRadio());

        p1.setX(nuevaX);
        p1.setY(nuevaY);

        p1.setVx(nuevaVx);
        p1.setVy(nuevaVy);

        p1.setMasa(masaTotal);
        p1.setRadio(nuevoRadio);

        p2.setMasa(0);
        p2.setRadio(0);
        p2.setVx(0);
        p2.setVy(0);

        texto = "Choque entre particulas en t=" +
<<<<<<< HEAD
                to_string(tiempo) +
                " masa final=" +
                to_string(masaTotal) +
                " velocidad=" +
=======
                to_string(tiempo) +  " masa final " +
                to_string(masaTotal) +
                " velocidad " +
>>>>>>> 83b9b8fe9b44a5208812709ff0ce8710805ce5d9
                to_string(nuevaVx) +
                " " +
                to_string(nuevaVy);

        return true;
    }

    return false;
}
