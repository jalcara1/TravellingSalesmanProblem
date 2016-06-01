#include "nodos.h"

Nodo::Nodo(int id,double cX,double cY){
  ID=id;
  x=cX;
  y=cY;
}

Nodo::Nodo(){}

int Nodo::getID(){
  return ID;
}

double Nodo::getX(){
  return x;
}

double Nodo::getY(){
  return y;
}
