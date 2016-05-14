#include <iostream>

class nodo{

private:
  int ID;
  float x,y;
  String nombre;
  
  
public:
  nodo();
  nodo(int id,float cX,float cY,string name);
  int getID();
  float getX();
  float getY();
  string getNombre();
};
