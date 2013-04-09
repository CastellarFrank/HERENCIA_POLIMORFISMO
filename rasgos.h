#ifndef RASGOS_H
#define RASGOS_H
#include "figura.h"

class Rasgos : public Figura
{
public:
    Rasgos();
    Rasgos(int x,int y, QColor color,QColor fondo,QString url,int w,int h);
    virtual void Dibujar(QPainter *painter);
    virtual char tipoFigura();
    void setUrl(QString url);
    void setAlto(int a);
    void setAncho(int a);
    void setTipoFigura(char t);
private:
    QString url;
    int ancho;
    int alto;
    QPixmap pix;
    char tFigura;

};

#endif // RASGOS_H
