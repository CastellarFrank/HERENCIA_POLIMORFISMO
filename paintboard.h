#ifndef PAINTBOARD_H
#define PAINTBOARD_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include "figura.h"
#include "lista_figura.h"
#include <math.h>

class PaintBoard : public QWidget
{
   Q_OBJECT

public:
    PaintBoard(QWidget *parent = 0);

    void setListaFiguras ( lista_figura *l);


private:
     float distancia(int x, int y, int x1, int y1);
     lista_figura *lista;

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // PAINTBOARD_H
