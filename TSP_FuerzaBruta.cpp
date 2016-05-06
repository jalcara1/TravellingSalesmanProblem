#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
  int id;
  double x,y;
  string name, linea;
  
  
  for(int i=0;i<argc;i++){
    ifstream archivo("argv[i]");
    
    while(archivo.getLine(linea)){
      cout<<linea<<endl;

    }

  }
  return 0;
}
