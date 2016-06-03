#include <map>

//const int INF=1<<30;

class Kruskal{
  
private:
  int cn; //cantidad de nodos
  map< int, map<int,int> > adyacencia; //matriz de adyacencia

public:
  Kruskal();
  Kruskal(map< int, map<int,int> >, int);
  vector< vector<int> >  consultar();
  void imprimirV(vector < vector<int> >);
};


Kruskal::Kruskal(){}

Kruskal::Kruskal(map<int, map<int,int> > arcos,int n):
  cn(n),adyacencia(arcos){}

// Devuelve la matriz de adyacencia del árbol mínimo.
vector< vector<int> > Kruskal:: consultar(){

  vector< vector<int> > arbol(cn);
  vector<int> pertenece(cn); // indica a que árbol pertenece el nodo

  int nodoA,nodoB;
  
  for(int i = 0; i < cn; i++){
    //arbol[i] = vector<int> (cn, 0);
    pertenece[i] = i;
  }

  int arcos = 1;
  while(arcos < cn){
    //cout<<"while"<<endl;
    // Encontrar  el arco mínimo que no forma ciclo y guardar los nodos y la distancia.
    int min = INF;

    //recorre el mapa de adyacencia 
    for(int i = 0; i < adyacencia.size(); i++)
      for(int j = 0; j < adyacencia[i].size(); j++)
	if(min > adyacencia[i][j] && adyacencia[i][j]!=0 && pertenece[i] != pertenece[j]){
	  min = adyacencia[i][j];
	  nodoA = i;
	  nodoB = j;
	}
  
    //cout<<"sali del for"<<endl;
    // Si los nodos no pertenecen al mismo árbol agrego el arco al árbol mínimo.
    if(pertenece[nodoA] != pertenece[nodoB]){
      arbol[nodoA].push_back(nodoB);
      arbol[nodoB].push_back(nodoA);
      // Todos los nodos del árbol del nodoB ahora pertenecen al árbol del nodoA.

      int temp = pertenece[nodoB];
      pertenece[nodoB] = pertenece[nodoA];

      for(int k = 0; k < cn; k++)
	if(pertenece[k] == temp)
	  pertenece[k] = pertenece[nodoA];

      arcos++;
    }
  }
  return arbol;
}

void Kruskal::imprimirV(vector< vector<int> > ve){
  for(int i=0;i<ve.size(); i++){
    cout<<"de "<<i<<" a ";
    for(int j=0; j<ve[i].size();j++){
      cout<<ve[i][j]<<" ";
    }
    cout<<endl;
  }
}
