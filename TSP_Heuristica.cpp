#include <iostream>
#include <fstream>
#include <sstream>

#include <map>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

//datos para disktra

const int MAXN = 100005;
const int INF = 1 << 30;

typedef pair <int,int> dist_n; //datos del heap (dist,nodo)
//typedef pair <int,int> edge; //Datos de arista (nodo,peso)

map< int, map<int,int> > pesos; //mapa de mapas para llegar a los pesos

//vector<edge> g[MAXN]; //g[u] = (v=nodo, w= peso)

int distancias[MAXN]; //d[u] la distancia mas corta de s a u
int predecesor[MAXN]; //p[u] el predecesor de u en el camino mas corto


/**
 *Método para aplicar dijkstra
 *la funcion recibe S y el número total de nodos n
**/
void dijkstra(int salida,int n){

  for (int i = 0; i <= n; ++i){
    distancias[i] = INF;
    predecesor[i] = -1;
  }

  priority_queue < dist_n , vector <dist_n>, greater<dist_n> > colapr;

  distancias[salida] = 0;
  colapr.push(dist_n(0, salida));

  while (!colapr.empty()){

    int dist = colapr.top().first;
    int actual = colapr.top().second;
    colapr.pop();

    if (dist > distancias[actual]) continue;

    int next,w_extra;

    //para recorrer el mapa
    
    for(map<int, int>::const_iterator it = pesos[actual].begin(); it!=pesos[actual].end() ; ++it){
      next = it->first;
      w_extra = it->second;
      
      if (distancias[actual] + w_extra < distancias[next]){
	distancias[next] = distancias[actual] + w_extra;
	predecesor[next] = actual;
	colapr.push(dist_n(distancias[next],next));
      }
      
    }

    
  }
}

/**
 * Método para encontrar un camino desde S hasta un T
 **/
vector <int> camino(int t){
  vector <int> camino;
  int actual = t;
  
  while(actual != -1){
    camino.push_back(actual);
    actual = predecesor[actual];
  }
  reverse(camino.begin(), camino.end());
  return camino;
}

/**
 * Metodo para imprimir un vector
 **/
void imprimir(vector<int> v){
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}


/**
 *Main para leer el archivo y llamar los métodos
 **/
int main(){

  int id,id2,distancia,contador=0;
  double x,y;
  string linea,token,token2,token3;

  //para ignorar encabezado
  getline(cin,linea);
 
  //leemos los nodos
  while(getline(cin,linea) && linea!=""){

    istringstream cadena(linea);

    //id del nodo
    getline(cadena,token,' ');
    istringstream(token)>>id;

    //coordenada en x
    getline(cadena,token,' ');
    istringstream(token)>>x;

    //coordenada en y
    getline(cadena,token,' ');
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
    getline(cadena,token,' ');
    istringstream(token)>>id;
    
    
    //id destino
    getline(cadena,token,' ');
    istringstream(token)>>id2;


    //distancia
    getline(cadena,token,' ');
    istringstream(token)>>distancia;


    //se guarda en el mapa de pesos
    pesos[id][id2]=distancia;
    cout<<"de "<<id<<" a "<<id2<<" hay "<<distancia<<endl;
    //cout<<"peso en ["<<id<<"]["<<id2<<"]= "<<pesos[id][id2]<<endl;

  }
  dijkstra(1,contador);
  vector<int> ou=camino(6);
  imprimir(ou);
}
