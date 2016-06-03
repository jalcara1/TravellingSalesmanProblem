#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include "nodos.h"

using namespace std;

const int MAXN = -1;
int distancias[10][10];

void TSP(int tam){
  
  int matriz[tam][tam];
  for(int i =0; i< tam; i++){
    for(int j =0; j< tam; j++){
      matriz[i][j] = distancias[i][j];
      cout << matriz[i][j] << ", ";
    }
    cout << endl;
  }
  cout << endl;
  int ensayo;
  int salida =0; int sum =0; int colum =0; int pos =0; int cantNodos =tam; bool entra;
  int nodos[cantNodos];
  int cambioSalida[cantNodos+1];
  for(int i =0; i< cantNodos; i++){
    nodos[pos] = pos;
    pos++;
  }
  int ayuda =0;
  for(int colum =0; colum< sizeof(nodos)/sizeof(nodos[0])-1; colum++){
    //cout << nodos[colum] << " " << nodos[colum+1] << " : " << matriz[nodos[colum]][nodos[colum+1]] << ", " << endl;
    if(matriz[nodos[colum]][nodos[colum+1]] == -1){
      salida == -1;
      break;
    }
    salida += matriz[nodos[colum]][nodos[colum+1]];
    cambioSalida[colum] = nodos[colum];
    ayuda = colum;
  }

  //cout << nodos[ayuda+1] << " " << nodos[0] << " : " << matriz[nodos[ayuda+1]][nodos[0]] << endl;
  if(matriz[nodos[ayuda+1]][nodos[0]] != -1){
    salida += matriz[nodos[ayuda+1]][nodos[0]];
    cambioSalida[ayuda+1] = nodos[ayuda+1];
  }
  cambioSalida[cantNodos] = nodos[0];

  while(next_permutation(nodos, nodos+cantNodos)){
    entra = true;
    //cout << endl;
    while(colum < sizeof(nodos)/sizeof(nodos[0])-1){
      //cout << nodos[colum] << " " << nodos[colum+1] << " : " << matriz[nodos[colum]][nodos[colum+1]] << ", " << endl;
      if(matriz[nodos[colum]][nodos[colum+1]] == -1){
	entra = false;
	break;
      }
      sum += matriz[nodos[colum]][nodos[colum+1]];
      colum++;
    }
    //Ultima posicion de recorrido
    //cout << nodos[colum] << " " << nodos[0] << " : " << matriz[nodos[colum]][nodos[0]] << endl;
    if((entra == true) && matriz[nodos[colum]][nodos[0]] != -1){
      sum += matriz[nodos[colum]][nodos[0]];
    }else{
      entra = false;
    }
    // ----
    //cout << nodos[0] << ", " << nodos[1] << ", " << nodos[2] << ", " << nodos[3] << ", " << nodos[4] << ", " << nodos[0] << endl; 
    if(entra == true && (salida == -1 || sum < salida)){
      salida = sum;
      for(int i =0; i< cantNodos; i++){
	cambioSalida[i] = nodos[i];
      }
      cambioSalida[cantNodos] = nodos[0];
    }
    colum =0;
    sum =0;
  }
  for(int i =0; i< cantNodos; i++){
    cout << cambioSalida[i] << ", ";
  }
  cout << cambioSalida[cantNodos] << " : " << salida << " :Resultado" << endl;
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

    //cout<<"ID:"<<id<<" X:"<<x<<" Y:"<<y<<" nombre:"<<name<<endl;
    //cout<<endl;

    //   Nodo* actual= new Nodo(id,x,y,name);
    //cocout<<actual->getNombre()<<" creado"<<endl;
    contador++;
  }
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
    //cout<<"Desde "<<id<<" hasta "<<id2<<" hay: "<<distancia<<" por: "<<name<<endl;

    //se ingresa en la matriz la distancia.
    distancias[id][id2]=distancia;
    //cout<<endl;
  }  
  TSP(contador);
  //imprimirMatriz(contador);
  return 0;
}
