#include "paintboard.h"

PaintBoard::PaintBoard(QWidget *parent): QWidget(parent)
{
   this->lista =0;
}

float PaintBoard::distancia(int x, int y, int x1, int y1){
  return (sqrt( (x1-x)*(x1-x) + (y1-y)*(y1-y) ));
}


void PaintBoard::paintEvent( QPaintEvent * event ){
    QPainter painter( this ); // Inicializar el Painter
    // Dibujar el tablero primero SIEMPRE
   painter.setBrush(Qt::white);
   painter.drawRect(0,0,this->geometry().width()-1,this->geometry().height()-1);

   if(lista!=0) // Si el apuntador de lista es diferente de nulo
   {
       // Recorrer la lista y dibujar
       lista->ir_a_inicio();
       for (int i=0; i < lista->getCuantos(); i++)
       {
         Figura *temp = lista->recuperar();
            if(temp!=0){
                temp->Dibujar(&painter);
            }
            lista->siguiente();
       }
   }

}
void PaintBoard::setListaFiguras(lista_figura *l)
{
    this->lista = l;
}
