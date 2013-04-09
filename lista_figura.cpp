#include "lista_figura.h"
#include <QDebug>

lista_figura::lista_figura()
{
    inicio=final=actual=0;
    cuantos=0;
}

void lista_figura::ir_a_inicio()
{ this->actual = this->inicio; }
void lista_figura::ir_a_final()
{ this->actual = this->final; }
void lista_figura::siguiente()
{ this->actual = this->actual->siguiente; }
void lista_figura::anterior()
{ this->actual = this->actual->anterior; }

Figura* lista_figura::recuperar()
{
    if(actual!=0)
         return actual->Fig;
    else
        return 0;
}

Figura* lista_figura::recuperar(int pos)
{
    if(cuantos==0 || pos>cuantos || pos <=0)
        return 0;
    else
    {
        this->ir_a_inicio();
        for(int i=1; i<pos;i++)
        {
            this->siguiente();
        }
        return this->actual->Fig;
    }
}

int lista_figura::getCuantos()
{
    return cuantos;
}
void lista_figura::agregar(Figura *F, bool t)
{
    int pos=-1;
    if(this->cuantos==0)
        this->iniciarNodosPrincipales();
      char t_figura=F->tipoFigura();

      if(t_figura=='C')
          pos=0;
      else if(t_figura=='O')
          pos=1;
      else if(t_figura=='N')
          pos=2;
      else if(t_figura=='B')
          pos=3;
      else if(t_figura=='H')
          pos=4;

      if(pos==-1){
          nodo_figura *nuevo;
          nuevo=new nodo_figura(F);
          this->final->siguiente=nuevo;
          nuevo->anterior=final;
          final=nuevo;
          final->siguiente=0;
          this->cuantos++;
      }else{
          this->ir_a_inicio();
          for(int i=0;i<pos;i++){
            this->siguiente();
          }
          if(t){
              delete this->actual->Fig;
            this->actual->Fig=F;
        }else{
            this->actual->Fig=0;
        }

      }
}

lista_figura::~lista_figura()
{
   this->limpiar();
}
void lista_figura::limpiar()
{
   //this->limpiar_recursivamente(this->inicio);
   this->actual = this->inicio;
   while(this->actual!=0)
   {
       this->inicio=this->inicio->siguiente;
       delete actual;
       actual = this->inicio;
   }
   this->inicio =0;
   this->final = 0;
   this->actual =0;
   this->cuantos =0;

}
void lista_figura::limpiar_recursivamente(nodo_figura *n)

{
    if (n==0)  return;
    else
    {
        this->limpiar_recursivamente(n->siguiente);
        delete n;
    }
}

void lista_figura::iniciarNodosPrincipales(){
    this->ir_a_inicio();

    for(int i=0;i<5;i++){
        nodo_figura *nuevo;
        nuevo = new nodo_figura();
        if(this->cuantos==0)
        {
            inicio=final=actual=nuevo;
        }
        else
        {
            final->siguiente=nuevo;
            nuevo->anterior = final;
            final = nuevo;
            final->siguiente=0;
        }
        this->cuantos++;
    }
}


















