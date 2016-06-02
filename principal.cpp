#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;
const int MAXBUF = 256;

typedef pair<double,double> coordenada; //para de cordenadas (x,y)
map<int,coordenada> nodos; //mapa para guardas las coordenadas por el id
map< int, map<int,int> > pesos; //mapa de mapas para llegar a los pesos


int main(int argc, char* argv[]){
  char buffer[MAXBUF];
  ifstream fichero(argv[1]);
  int contador =0;
  //para ignorar encabezado
  char ignorar[MAXBUF];
 

  fichero.getline(ignorar,MAXBUF);
  cout << sizeof(buffer)/sizeof(buffer[0]) << endl;
  cout<<ignorar<<endl;

  //leemos los nodos
  while(fichero.getline(buffer,MAXBUF) && buffer[0] != 'A'){
    // if(buffer == "yaa"){
    //   break;
    // }
    string buffer2(buffer);
    istringstream ins(buffer2);
    int id;
    double x, y;
    ins >> id >> x >> y;
    contador++;
    nodos[id]= coordenada(x,y);
  }
  cout<<"nodos: "<<contador<<endl;
  //omitir encabezado aristas
  //fichero.getline(ignorar,MAXBUF);
  cout << buffer << endl;
  //se leen las aristas
  while(fichero.getline(buffer,MAXBUF)){
    string buffer2(buffer);
    istringstream ins(buffer2);    
    int distancia, id,id2;    
    ins >> id >> id2 >> distancia;
    //se guarda en el mapa de pesos    
    pesos[id][id2]=distancia;
  } 
  for(int i =2; i< argc; ++i){    
    ifstream filein(argv[i]);
    while(filein.getline(buffer,MAXBUF)){
      string nodos(buffer);
      istringstream ins(nodos);
      int nodo;
      ins >> nodo;
      if(ins){
	cout << "Nodo: " << nodo << endl;
      }else{
	cerr << "Error en la entrada" << endl;
      }
    }
  }
  return 0;
}
