#ifndef CABEZA_H
#define CABEZA_H
#include "figura.h"

class Cabeza :public Figura
{
public:
    Cabeza();
    Cabeza(int x,int y,int w,int h,QColor color,
           QColor fondo);
    virtual void Dibujar(QPainter *AreaPintado);
    virtual char tipoFigura();

    int getAncho() const;
    int getAlto() const;
    void setAncho(int ancho);
    void setAlto(int alto);
    void setTipo(int t);
    void setRadio1(int r);
    void setRadio2(int r);
private:
    int tipo;
    int ancho;
    int alto;
    int radio1;
    int radio2;


};

#endif // CABEZA_H
