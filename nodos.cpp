#include "nodos.h"

Nodo::Nodo(int id,float cX,float cY,string name){
  ID=id;
  x=cX;
  y=cY;
  nombre=name;
}

Nodo::Nodo(){}

int Nodo::getID(){
  return ID;
}

float Nodo::getX(){
  return x;
}

float Nodo::getY(){
  return y;
}

string Nodo::getNombre(){
  return nombre;
}
