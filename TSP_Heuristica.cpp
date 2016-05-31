#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

//datos para disktra

const int MAXN = 100005;
const int INF = 1 << 30;

typedef pair <int,int> dist; //datos del heap (dist,nodo)
//typedef pair <int,int> edge; //Datos de arista (nodo,peso)

map< int, map<int,int> > pesos; //mapa de mapas para llegar a los pesos

//vector<edge> g[MAXN]; //g[u] = (v=nodo, w= peso)
int d[MAXN]; //d[u] la distancia mas corta de s a u
int p[MAXN]; //p[u] el predecesor de u en el camino mas corto


/**
 *Método para aplicar dijkstra
 *la funcion recibe S y el número total de nodos n
**/
void dijkstra(int s,int n){

  for (int i = 0; i <= n; ++i){
    d[i] = INF;
    p[i] = -1;
  }

  priority_queue < dist , vector <dist>, greater<dist> > q;

  d[s] = 0;
  q.push(dist(0, s));

  while (!q.empty()){

    int dist = q.top().first;
    int cur = q.top().second;
    q.pop();

    if (dist > d[cur])
      continue;

    for (int i = 0; i < g[cur].size(); ++i){
      int next = g[cur][i].first;
      //int w_extra = g[cur][i].second;
      int w_extra= pesos[cur][i];

      if (d[cur] + w_extra < d[next]){
	d[next] = d[cur] + w_extra;
	p[next] = cur;
	q.push(dist(d[next], next));
      }
    }
    
  }
}

vector <int> camino(int t){
  vector <int> camino;
  int actual = t;
  
  while(actual != -1){
    camino.push_back(actual);
    actual = p[actual];
  }
  reverse(camino.begin(), camino.end());
  return camino;
}



//Main para leer el archivo y llamar los métodos

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
