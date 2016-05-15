#include <iostream>
#include <fstream>
#include <sstream>
#include "nodos.h"

using namespace std;

int main(int argc, char* argv[]){
  int id,id2,distancia;
  double x,y;
  string name, linea,token;
  Nodo actual;
  
  getline(cin,linea);
  
  while(getline(cin,linea) && linea!=""){
      
      istringstream cadena(linea);  

      getline(cadena,token, ',');
      istringstream(token)>>id;

      getline(cadena,token, ',');
      istringstream (token)>>x;

      getline(cadena,token, ',');
      istringstream (token)>>y;
      
      getline(cadena,name, ',');

      cout<<"ID:"<<id<<" X:"<<x<<" Y:"<<y<<" nombre:"<<name<<endl;
      cout<<endl;

      actual= Nodo(id,x,y,name);
      cout<<actual.getNombre()<<" creado"<<endl;
  }
  
  getline(cin,linea);
  
  
  while(getline(cin,linea) && linea!=""){
          
      istringstream cadena(linea);  
      
      getline(cadena,token, ',');
      istringstream (token)>>id;

      getline(cadena,token, ',');
      istringstream (token)>>id2;

      getline(cadena,token, ',');
      istringstream (token)>>distancia;

      getline(cadena,name, ',');

      cout<<"Desde "<<id<<" hasta "<<id2<<" hay: "<<distancia<<" por: "<<name<<endl;

      cout<<endl;
  }
  
  
  return 0;
}
