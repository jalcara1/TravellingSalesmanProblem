#ifndef NODOS_H
#define NODOS_H
#endif

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Nodo{

private:
  int ID;
  float x,y;
  string nombre;
    
public:
  Nodo();
  Nodo(int id,float cX,float cY,string name);
  int getID();
  float getX();
  float getY();
  string getNombre();
};
