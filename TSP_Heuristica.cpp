#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct nodo{
  int id,cx,cy;

  // nodo(int id
};


int main(){
  int id,id2,distancia,contador=0;
  double x,y;
  string linea,token;

  //para ignorar encabezado
  getline(cin,linea);
  cout<<linea<<endl;

  //leemos los nodos

  while(getline(cin,linea) && linea!=""){

    istringstream cadena(linea);
    cout<<linea<<endl;
    getline(cadena,token);
    istringstream(token)>>id;
    
    getline(cadena,token);
    istringstream(token)>>x;

    getline(cadena,token);
    istringstream(token)>>y;

    contador++;
  }
  
  cout<<"nodos: "<<contador<<endl;

  //omitir encabezado aristas
  getline(cin,linea);

  
  //se leen las aristas
  while(getline(cin,linea) && linea!=""){
    istringstream cadena(linea);

    //id origen
    getline(cadena,token);
    istringstream(token)>>id;

    //id destino
    getline(cadena,token);
    istringstream(token)>>id2;

    //distancia
    getline(cadena,token);
    istringstream(token)>>distancia;
   

  }

}
