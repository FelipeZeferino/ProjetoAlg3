/* Projeto Algoritmos 3 - Pokedex.
Victor Mendes Silva Zeferino - 522.
Felipe Mendes Silva Zeferino - 511
Gustavo Delfino Ribeiro       - 292    .    */
#include <iostream>
#include<list>
using namespace std;

struct pokemon
{
    string nome;
    string tipo;
    unsigned int id; // unsigned int, já que um ID nao deve ser negativo
    int posX, posY;
};

struct Adjacencia {
int origem;
int destino;
int custo;
};
struct cidade
{
    unsigned int id; // unsigned int, já que um ID nao deve ser negativo
    string nome;
    bool centro;
    list<Adjacencia> adj;
    // adicionar lista de adjacencia aqui?
};
bool centro_valido(int centrobool, bool centro)
{ // funcao que impede a leitura invalida do valor para o CIN do centro, tranformar int em Bool

    while (centrobool != 0 | centrobool != 1)
    {
        cout << "valor inválido, digite 0 se houver centro e 1 se nao houver";
        cin >> centrobool;
    }
    if (centrobool == 0)
    {
        return centro = true;
    }
    else
    {
        return centro = false;
    }
}

// funcoes para imprimir os valores das structs pokemon e cidade
void mostrar_pokemon(pokemon pokemon)
{
    cout << "Pokemon Registrado:" << endl
         << "nome: " << pokemon.nome << endl
         << "Tipo: " << pokemon.tipo << endl
         << "ID: " << pokemon.id << endl
         << "Posicao: " << pokemon.posX << pokemon.posY << endl;
}

void mostrar_cidade(cidade cidade)
{
    cout << "Cidade Registrada:" << endl
         << "nome: " << cidade.nome << endl
         << "Tem centro?: " << cidade.centro << endl
         << "ID: " << cidade.id << endl;
}

int main()
{
    int centrobool = 0;

    pokemon pokemon;
    cidade cidade;

    // leitura de dados do pokemon.
    cout << "entre com o nome,tipo e posicao (x e y) do pokemon: " << endl;
    getline(cin, pokemon.nome);
    getline(cin, pokemon.tipo);
    cin >> pokemon.id >> pokemon.posX >> pokemon.posY;

    // leitura dos dados da cidade.
    cout << "entre com o nome, id, e se tem centro Pokemon(0 sim, 1 nao)";
    getline(cin, cidade.nome);
    cin >> cidade.id >> centrobool;
    centro_valido(centrobool, cidade.id); // funcao retorna o valor como bool para guardar na struct

    // impressao dos dados do pokemon.
    mostrar_pokemon(pokemon);
    // impressao dos dados da cidade;
    mostrar_cidade(cidade);
}
