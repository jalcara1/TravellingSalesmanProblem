#include <iostream>
#include <iomanip>
#include <algorithm>

#include <map>
#include <queue>
#include <vector>

using namespace std;

//datos para disktra
const int MAXN = 100005;
const int INF = 1 << 30;

typedef pair <int,int> dist_n; //datos del heap (dist,nodo)


class Dijkstra{
private:
  map< int, map<int,int> > pesos; //mapa de mapas para llegar a los pesos
  int distancias[MAXN]; //d[u] la distancia mas corta de s a u
  int predecesor[MAXN]; //p[u] el predecesor de u en el camino mas corto
  
public:
  Dijkstra();
  Dijkstra(map<int, map<int,int> >);
  int* getDistancias();
  void consultar(int,int);
  vector<int> camino(int);
  void limpiarArreglos();
};



Dijkstra::Dijkstra(){}

Dijkstra::Dijkstra(map<int,map<int,int> > arcos):
  pesos(arcos) {}

int* Dijkstra::getDistancias(){
  return distancias;
}

/**
 * Método para encontrar un camino desde S hasta un T
 **/
vector<int> Dijkstra::camino(int t){
  vector <int> camino;
  int actual = t;
  
  while(actual != -1){
    camino.push_back(actual);
    actual = predecesor[actual];
  }
  reverse(camino.begin(), camino.end());
  return camino;
}

void Dijkstra::limpiarArreglos(){  
  for (int i = 0; i <= n; ++i){
    distancias[i] = INF;
    this->predecesor[i] = -1;
  }
}


/**
 *Método para aplicar dijkstra
 *la funcion recibe S y el número total de nodos n
**/
void Dijkstra::consultar(int origen,int n){
  limpiarArreglos();
  priority_queue < dist_n , vector <dist_n>, greater<dist_n> > colapr;

  distancias[origen] = 0;
  colapr.push(dist_n(0, origen));

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

 
