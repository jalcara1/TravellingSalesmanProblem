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

  getline(cin,linea);

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
  


}
