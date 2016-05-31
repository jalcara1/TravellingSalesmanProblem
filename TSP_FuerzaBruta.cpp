#include <iostream>
#include <fstream>
#include <sstream>
#include "nodos.h"

using namespace std;

const int MAXN=1000000;
int distancias[10][10];

void imprimirMatriz(int tam){

  for(int i=0;i<tam;i++){
    for(int j=0;j<tam;j++){
      cout<<"distancias["<<i<<"]["<<j<<"]="<<distancias[i][j]<<endl;
    }
    cout<<endl;
  }

}


int main(int argc, char* argv[]){
  int id,id2,distancia=MAXN,contador=0;
  double x,y;
  string name, linea,token;
  //Nodo actual;


  //se ingnora el encabezado
  getline(cin,linea);


  //se leen los nodos hasta un espacio
  while(getline(cin,linea) && linea!=""){
      
      istringstream cadena(linea);  

      getline(cadena,token, ',');
      istringstream(token)>>id;

      getline(cadena,token, ',');
      istringstream (token)>>x;

      getline(cadena,token, ',');
      istringstream (token)>>y;
      
      getline(cadena,name,',');

      //      cout<<"ID:"<<id<<" X:"<<x<<" Y:"<<y<<" nombre:"<<name<<endl;
      //cout<<endl;

      //   Nodo* actual= new Nodo(id,x,y,name);
      //cocout<<actual->getNombre()<<" creado"<<endl;
      contador++;
  }
  cout<<contador<<endl;

  //para ignorar el encabezado de las entradas
  getline(cin,linea);



  //Se crea la matriz segun los nodos
  //int distancias[contador][contador];


  /*se llena todo con infinito, mirar como hacer el recorrido
    solo del triángulo */
  
  for(int i=0;i<contador;i++){
    for(int j=0;j<contador;j++){
      if(j!=i)
	distancias[i][j]=MAXN;
      else
	distancias[i][j]=0;
    }
  }



  //se leen las aristas
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

      //se ingresa en la matriz la distancia.
      distancias[id][id2]=distancia;
      cout<<endl;
  }
  
  //  imprimirMatriz(contador);
  return 0;
}
