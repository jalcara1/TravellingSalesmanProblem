#include <iostream>
#include <windows.h>
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

typedef pair<string,string> coordenada; //para de cordenadas (x,y)

map<int,coordenada> nodos; //mapa para guardas las coordenadas por el id
map< int, map<int,int> > pesos; //mapa de mapas para llegar a los pesos

bool visitados[MAXN]; //usado por el DFS para marcar los visitados
vector< vector<int> > adj; //lista de adyacencia que recorre el dfs
vector <int> result; // Vector que contiene el ciclo hamiltoniano generado


/**
 * imprime un vector
 **/
void printVector(vector<int> vector){
  for(int i=0 ; i<vector.size() ; i++){
    cout<<vector[i]<<" ";
  }
  cout<<endl;
}


/**
 * coordenadas sin puntos intermedios
 **/
string coord(vector<int>camino){
  string salida="";

  for(int i = 0; i<camino.size() ; i++)
    salida+= nodos[ camino[i] ].first + "," + nodos[ camino[i] ].second + "/";

  return salida;
}

/**
 * Nos da las coordenadas del ciclo, incluyendo los puntos intermedios.
 **/
string getCoordenadas(vector <int> camino, map< int, map<int, vector <int> > > intermedios){

  string salida="";
  vector <int> intermedio;
  int desde,hasta;

  //Se recorre el camino resultante y se sacan los nodos intermedios entre cada par de nodos.
  for(int i=1;i<camino.size();i++){
    desde=camino[i-1];
    hasta=camino[i];
    intermedio= intermedios[desde][hasta]; 

    salida+= nodos[desde].first + "," + nodos[desde].second + "/";
    //cout<<"se agrego la coordenada desde "<<desde<<endl;

    for(int j = 1; j < intermedio.size()-1;j++ ){
      //cout<<"intermedio con "<<intermedio[j]<<endl;
      //cout<<"se agrego la coordenada intermedia "<<intermedio[j]<<endl;
      salida += nodos[ intermedio[j] ].first + "," + nodos[ intermedio[j] ].second + "/";
    }
    salida+= nodos[ hasta].first + "," + nodos[hasta].second + "/";

  }
  
  return salida;
}

/**
 * Usado para calcular la distancia  total de un camino de nodos alamacenado en un vector
 **/
int calcularDist(vector<int> v,map< int, map<int,int> > adj){
  int dist=0;
  for(int i = 1; i< v.size() ; i++){
    dist += adj[ v[i-1] ][ v[i] ];
  }
  cout<<endl;
  return dist;
}

/**
 * Recorrido en profundidad de una lista de adyacencia.
 **/
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

  char buffer[MAXBUF]; //para almacenar cada linea
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
    string x, y;
    ins >> id >> x >> y;
    cNodos++;
    nodos[id] = coordenada(x,y); //se guarda en un mapa las coordenadas de cada id
  }  

  cout << "# nodos: " << cNodos << endl << endl;

  //se leen las aristas
  while(fichero.getline(buffer,MAXBUF)){
    string buffer2(buffer);
    istringstream ins(buffer2);    
    int distancia, id,id2;    

    ins >> id >> id2 >> distancia;

    //se guarda en el mapa de pesos    
    pesos[id][id2] = distancia;  

  }

  
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


    //Se aplica Dijkstra desde cada nodo de la consulta
    Dijkstra dij = Dijkstra(pesos,cNodos);
    map< int, map<int,int> > mini;
    map< int, map< int, vector<int> > > intermedios;
    
    for(int i =0;i< consultas.size(); i++){
      dij.consultar(consultas[i]);
      for(int j =0; j <consultas.size(); j++){
	if(i != j){
	  mini[i][j] = dij.getDistancia(j);
	  intermedios[i][j] = dij.camino(j);
	}
      }
    }
    cout<<endl;
    
    //se crea el objeto de kruskal y se aplica con el minigrafo
    Kruskal k = Kruskal(mini, consultas.size());
    adj = k.consultar();

    //imprimimos el arbol de expancion minima resultante
    cout<<"Lista de adyancencia arbol de expansion minima: "<<endl;
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

    //abrir el link
    string link="https://www.google.com.co/maps/dir/";

    //link sin caminos intermedios
    cout<<endl<<"link sin caminos intermedios: "<<endl<<link+coord(result)<<endl;
    //string link; 
    //ShellExecute(NULL, "open", link+coord(result), NULL, NULL, SW_SHOWNORMAL);
    cout<<"lista completa de coordenadas: "<<link+getCoordenadas(result,intermedios)<<endl;
    
    //limpiamos los mapas para el siguiente archivo
    mini.clear(); 
    intermedios.clear(); 
  }
  

  return 0;
}
