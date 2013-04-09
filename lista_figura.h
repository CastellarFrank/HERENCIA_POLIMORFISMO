#ifndef LISTA_FIGURA_H
#define LISTA_FIGURA_H
#include "figura.h"
class nodo_figura
{
  public:
    nodo_figura(){ anterior=siguiente=0; Fig=0;}
    nodo_figura(Figura *F) {anterior=siguiente=0; Fig=F;}
    nodo_figura *anterior;
    nodo_figura *siguiente;
    Figura *Fig;


};
class Posiciones
{
public:
    Posiciones(int x,int y){this->posX=x; this->posY=y;
        this->ancho=0; this->alto=0; this->pos=0;}
    int posX;
    int posY;
    int ancho;
    int alto;
    int pos;
};

class lista_figura
{
public:
    lista_figura();
    void ir_a_inicio();
    void ir_a_final();
    void siguiente();
    void anterior();
    Figura *recuperar();
    Figura *recuperar(int pos);
    int getCuantos();
    void agregar(Figura *F,bool t);
    void limpiar();
    int buscarFigura(char tipo);
    ~lista_figura();
    void iniciarNodosPrincipales();


private:
     nodo_figura *inicio;
     nodo_figura *final;
     nodo_figura *actual;
     int cuantos;
     void limpiar_recursivamente(nodo_figura *n);
};

#endif // LISTA_FIGURA_H










