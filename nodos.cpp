#include "nodos.h"

nodo::nodo(int id,float cX,float cY,string name){
  ID=id;
  x=cX;
  y=cY;
  nombre=name;
}

nodo::nodo(){}

int nodo::getID(){
  return ID;
}

float nodo::getX(){
  return x;
}

float nodo::getY(){
  return y;
}

string nodo::getNombre(){
  return nombre;
}
