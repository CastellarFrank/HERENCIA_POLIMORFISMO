#include "cabeza.h"

Cabeza::Cabeza():Figura()
{
    this->alto=10;
    this->ancho=10;
    this->radio1=0;
    this->radio2=0;
}
Cabeza::Cabeza(int x, int y, int w, int h,
               QColor color, QColor fondo):Figura(
                       x,y,color,fondo){
    this->alto=h;
    this->ancho=w;
    this->radio1=0;
    this->radio2=0;
}
void Cabeza::Dibujar(QPainter *AreaPintado){
    QPen pen(this->getColor(), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    AreaPintado->setPen( pen);
    AreaPintado->setBrush(this->getFondo());
    QPointF punto(this->getX(),this->getY());

    if(this->tipo==0){
        AreaPintado->drawEllipse(punto,this->radio1,this->radio1);
    }else if(this->tipo==1){
        AreaPintado->drawRect(this->getX()-(this->getAncho()/2),this->getY()-(this->getAlto()/2),this->getAncho(),this->getAlto());
    }else{
        AreaPintado->drawEllipse(punto,this->radio1,this->radio2);
    }
}
void Cabeza::setTipo(int t){
    this->tipo=t;
}
void Cabeza::setAlto(int alto){
    this->alto=alto;
}
void Cabeza::setAncho(int ancho){
    this->ancho=ancho;
}
int Cabeza::getAlto()const{
    return this->alto;
}
int Cabeza::getAncho()const {
    return this->ancho;
}

char Cabeza::tipoFigura(){
    return 'C';
}
void Cabeza::setRadio1(int r){
    this->radio1=r;
}
void Cabeza::setRadio2(int r){
    this->radio2=r;
}




