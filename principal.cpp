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

const int MAXBUF = 256; //usado para la lectura del archivo

typedef pair<double,double> coordenada; //para de cordenadas (x,y)

map<int,coordenada> nodos; //mapa para guardas las coordenadas por el id
map< int, map<int,int> > pesos; //mapa de mapas para llegar a los pesos

bool visitados[MAXN]; //usado por el DFS para marcar los visitados
vector< vector<int> > adj; //lista de adyacencia que recorre el dfs
vector <int> result; // Vector que contiene el ciclo hamiltoniano generado


/**
 * imprime un vector
 **/
void printVector(vector<int> a){
  for(int i=0 ; i<a.size() ; i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}


void resultado(){
  

}


int calcularDist(vector<int> v,map< int, map<int,int> > adj){
  int dist=0;
  for(int i = 1; i< v.size() ; i++){
    dist += adj[ v[i-1] ][ v[i] ];
  }
  return dist;
}


dfs(int nodo){
  visitados[nodo] = true;
  result.push_back(nodo);
  int next;
  
  for(int i = 0; i < adj[nodo].size(); ++i){
    next = adj[nodo][i];
    if(!visitados[next]){
      dfs(next);
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

    //se crea el objeto de kruskal y se aplica con el minigrafo
    Kruskal k = Kruskal(mini, consultas.size());
    adj = k.consultar();

    //imprimimos el arbol de expancion minima resultante
    cout<<"Lista de adyancencia final: "<<endl;
    k.imprimirV(adj);
    cout<<endl;
    
    //aplicamos dfs con el primer nodo de las consultas
    dfs(consultas[0]);
    result.push_back(consultas[0]);

    //imprimir ciclo
    cout<<"Ciclo: "<<endl;
    printVector(result);

    //calcular e imprimir distancia
    cout<<"Distancia total: "<<calcularDist(result,mini)<<endl;

    //sacar el camino y las coordenadas

    //limpiamos los mapas para el siguiente archivo
    mini.clear(); 
    caminos.clear(); 
  }


  return 0;
}
