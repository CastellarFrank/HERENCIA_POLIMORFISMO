#include "rasgos.h"

Rasgos::Rasgos()
{
    this->url="";
    this->alto=0;
    this->ancho=0;
    this->tFigura='0';
}
Rasgos::Rasgos(int x, int y, QColor color, QColor fondo,
               QString url, int w, int h):Figura(x,y,color,fondo){
    this->url=url;
    this->alto=h;
    this->ancho=w;

}
void Rasgos::setUrl(QString url){
    this->url=url;
}
void Rasgos::Dibujar(QPainter *painter){
    pix=QPixmap(this->url).scaled(this->ancho,
                                  this->alto);
    painter->drawPixmap(this->getX(),this->getY(),pix);
}
void Rasgos::setAlto(int a){
    this->alto=a;
}
void Rasgos::setAncho(int a){
    this->ancho=a;
}
char Rasgos::tipoFigura(){
    return this->tFigura;
}
void Rasgos::setTipoFigura(char t){
    this->tFigura=t;
}
