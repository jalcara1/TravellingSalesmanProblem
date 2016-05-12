#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
  int id;
  double x,y;
  string name, linea,token;

  
  for(int i=0;i<argc;i++){

    ifstream archivo(argv[i]);
    //archivo.close();
    
    while(getline(archivo,linea)){
      
      cout<<"linea: "<<linea<<endl;
    
      istringstream cadena(linea);  

      while(getline(cadena,token, ',')){
	cout<<"Token: "<<token<<endl;
      
      }
    }

  }

  
  return 0;
}
