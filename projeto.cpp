/* Projeto Algoritmos 3 - Pokedex.
Victor Mendes Silva Zeferino - 522.
Felipe Mendes Silva Zeferino - 511
Gustavo Delfino Ribeiro       - 292    .    */
#include <iostream>
#include <list>

using namespace std;

#define INT_MAX 99999;
struct pokemon {
  string nome;
  string tipo;
  unsigned int id;  // unsigned int, já que um ID nao deve ser negativo
  int posX, posY;
};

struct Adjacencia {
  cidade origem;
  cidade destino;
  int custo;
};
struct cidade {
  unsigned int id;  // unsigned int, já que um ID nao deve ser negativo
  string nome;
  bool centro;
  list<Adjacencia> adj;
  // adicionar lista de adjacencia aqui?
};
// funcoes para imprimir os valores das structs pokemon e cidade
void mostrar_pokemon(pokemon pokemon) {
  cout << "Pokemon Registrado:" << endl
       << "nome: " << pokemon.nome << endl
       << "Tipo: " << pokemon.tipo << endl
       << "ID: " << pokemon.id << endl
       << "Posicao: " << pokemon.posX << pokemon.posY << endl;
}

void mostrar_cidade(cidade cidade) {
  cout << "Cidade Registrada:" << endl;
  cout << "nome: " << cidade.nome << endl;
  cout << "Tem centro?: " << cidade.centro << endl;
  cout << "ID: " << cidade.id << endl;
}

void cria_aresta(cidade cidades[], int u, int v, int custo) {
  Adjacencia aux;

  aux.origem = cidades[u]; 
  aux.destino = cidades[v];  
  aux.custo = custo;         
  cidades[u].adj.push_back(
      aux);  

  aux.origem = cidades[v];
  aux.destino = cidades[u];
  cidades[v].adj.push_back(aux);
}

int shortest_path_dijkstra(cidade cidades[], int numCidades, int start, int end){
	bool intree[numCidades];
	int distance[numCidades], parent[numCidades];
	
	for(int u = 0; u < numCidades; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
	}
    distance[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
		list<Adjacencia>::iterator p;
    	for(p = cidades[v].adj.begin(); p != cidades[v].adj.end(); p++){
            int dest = p->destino.id;
            int weight = p->custo;
            if(distance[dest] > distance[v]+weight){
                distance[dest] = distance[v]+weight;
                parent[dest] = v;
			}
		}
        v = 0;
        int dist = INT_MAX;
        for(int u = 0; u < numCidades; u++){
            if(intree[u]==false && dist>distance[u]){
                dist = distance[u];
                v = u;
			}
		}
	}
	return distance[end];
}
void cadastroCidades(cidade cidades[]) {
  cout << "Entre com a adjacência: " << endl;
  int aux1, aux2;
  while (aux1 != -1 && aux2 != -1) {
    float custo;
    cout << "Id da cidade origem: " << endl;
    cin >> aux1;
    cout << "Id da cidade destino: " << endl;
    cin >> aux2;
    cout << "Custo: " << endl;
    cin >> custo;
    cria_aresta(cidades, aux1, aux2, custo);
  }
}

// fazer um djiktra calculando qual a cidade mais próxima com centro pokemon
// calcular para todas as cidades com centro pokemon e retornar a mais próxima

//for (int i = 0; i < ){
// if(cidades[i].id != atual && cidades[i].centrobool)
// dijkstra(atual, i); função que retorna a distância da cidade mais próxima
// }

int main() {
  // for entradas cidades com id = index

  bool centrobool;
  pokemon pokemon;
  cidade cidades[100];
  int numCidades;

  // leitura de dados do pokemon.
  cout << "entre com o nome,tipo e posicao (x e y) do pokemon: " << endl;
  getline(cin, pokemon.nome);
  getline(cin, pokemon.tipo);
  cin >> pokemon.id >> pokemon.posX >> pokemon.posY;

  // leitura dos dados da cidade.
  cout << "Entre com o número de cidades";
  cin >> numCidades;
  for (int i = 0; i < numCidades; i++) {
    cout << "entre com o nome e se tem centro Pokemon(0 não, 1 sim)";
    cin >> cidades[i].nome >> cidades[i].centro;
    cidades[i].id = i;
    cin >> centrobool;

    cadastroCidades(cidades);
  }

  // impressao dos dados do pokemon.
  mostrar_pokemon(pokemon);
  // impressao dos dados da cidade;
  mostrar_cidade(cidades[0]);
  return 0;
}
