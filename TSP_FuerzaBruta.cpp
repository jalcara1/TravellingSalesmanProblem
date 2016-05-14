#include <iostream>
#include <fstream>
#include <sstream>
#include "nodos.h"

using namespace std;

int main(int argc, char* argv[]){
  int id;
  double x,y;
  string name, linea,token;
  
  cin>>linea;
 
  while(getline(cin,linea) && linea!=""){
      
      cout<<"linea: "<<linea<<endl;
    
      istringstream cadena(linea);  

      getline(cadena,id, ',');
      getline(cadena,x, ',');
      getline(cadena,y, ',');
      getline(cadena,name, ',');

      cout<<"ID: "<<id<<" X: "<<x<<" y: "<<y<<" nombre: "<<name<<endl;
	  
  }

  cin>>linea;
  

  while(getline(cin,linea) && linea!=""){
    
      cout<<"linea: "<<linea<<endl;
      
      istringstream cadena(linea);  
      
      while(getline(cadena,token, ',')){
	cout<<"Token: "<<token<<endl;
	
      }
  }
  
  
  return 0;
}
