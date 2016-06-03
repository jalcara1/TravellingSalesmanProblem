#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
#include <vector>
#include "Dijkstra.cpp"
#include "Kruskal.cpp"

using namespace std;

const int MAXBUF = 256;

typedef pair<double,double> coordenada; //para de cordenadas (x,y)
map<int,coordenada> nodos; //mapa para guardas las coordenadas por el id
map< int, map<int,int> > pesos; //mapa de mapas para llegar a los pesos

bool visitados[MAXN];
vector< vector<int> > adj;

void dfs(int nodo){
  visitados[nodo] = true;
  int next;
  cout<<"nodo "<<nodo<<endl;
  for(int i = 0; i < adj[nodo].size(); ++i){
    next = adj[nodo][i];
    if(!visitados[next]){
      //cout<<"visite "<<next<<endl;
      dfs(next);
      //cout<<"visite "<<next<<endl;
    }
    
  }
}

int main(int argc, char* argv[]){
  char buffer[MAXBUF];
  ifstream fichero(argv[1]); //leemos el fichero con el mapa
  int cNodos = 0; //contador para los nodos del mapa
  vector<int> consultas; //Vector para guardar las consltas
  //para ignorar encabezado
  char ignorar[MAXBUF];
  fichero.getline(ignorar,MAXBUF);
  //Leemos el mapa  
  //leemos los nodos
  while(fichero.getline(buffer,MAXBUF) && buffer[0] != 'A'){
    string buffer2(buffer);
    istringstream ins(buffer2);
    int id;
    double x, y;
    ins >> id >> x >> y;
    cNodos++;
    nodos[id] = coordenada(x,y); //se guarda en un mapa las coordenadas de cada id
  }  
  cout << "# nodos: " << cNodos << endl;
  //omitir encabezado aristas
  int contador2 = 0;
  //se leen las aristas
  while(fichero.getline(buffer,MAXBUF)){
    string buffer2(buffer);
    istringstream ins(buffer2);    
    int distancia, id,id2;    
    ins >> id >> id2 >> distancia;
    //se guarda en el mapa de pesos    
    pesos[id][id2] = distancia;  //se guarda la arista con su peso en el mapa
    contador2++;
  }
  cout << "contador de aristas: " << contador2 << endl;
  //Se leen los archivos de consulta
  for(int i =2; i< argc; ++i){    
    ifstream filein(argv[i]);

    while(filein.getline(buffer,MAXBUF)){
      string nodos(buffer);
      istringstream ins(nodos);
      int nodo;
      ins >> nodo;
      if(ins){	
	consultas.push_back(nodo);
	cout << "Nodo: " << consultas.back() << endl;
      }else{
	cerr << "Error en la entrada" << endl;
      }
    }
    Dijkstra dij = Dijkstra(pesos,cNodos);
    map< int, map<int,int> > mini;
    map< int, map< int, vector<int> > > caminos;
    for(int i =0;i< consultas.size(); i++){
      dij.consultar(consultas[i]);
      for(int j =0; j <consultas.size(); j++){
	if(i != j){
	  mini[i][j] = dij.getDistancia(j);
	  caminos[i][j] = dij.camino(j);
	  cout << "Distancia de " << i << " a " << j << " " << mini[i][j] << endl;
	  cout << "camino: ";
	  dij.imprimir(caminos[i][j]); //desde el mapa
	  
	}
      }
      cout << endl;
    }
    Kruskal k = Kruskal(mini, consultas.size());
    adj = k.consultar();
    cout<<"antes de imprimir"<<endl;
    k.imprimirV(adj);
    //adj = salida;
    dfs(consultas[0]);

    //sacar el camino y las coordenadas
    mini.clear(); //limpiarlo para el siguiente archivo
    caminos.clear(); 
  }
  return 0;
}
