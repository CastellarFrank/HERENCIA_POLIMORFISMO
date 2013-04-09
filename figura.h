#ifndef FIGURA_H
#define FIGURA_H
#include <Qt>
#include <QPainter>
#include <QPolygonF>
#include <QPointF>

class Figura
{
public:
    Figura();
    Figura(int x, int y, QColor color, QColor fondo);
    // Dos Metodos VIRTUALES PUROS
    virtual void Dibujar (QPainter *painter) = 0;
    virtual char tipoFigura() = 0;

    // Metodos virtuales NO puros, que seran heredados
    // Pero que definen un comportamiento Default, pero pueden sobre escribirse
    virtual void setX(int newx);  // Por ejemplo este no valida negativos
    virtual void setY(int newy);  // Se puede sobre escribir por las clases derivadas
                                  // Y llamar a la clase base
    // Metodos publicos NO virtuales
    int getX() const ;
    int getY() const;
    void setColor(QColor color);
    void setFondo(QColor fondo);
    QColor getColor() const;
    QColor getFondo() const;

protected:
    virtual void Mover (int newx, int newy);  // PAra explicar lo de protected

 private:
    int x,y;
    QColor color,fondo;
};

#endif // FIGURA_H
