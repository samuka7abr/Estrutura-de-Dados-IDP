#ifndef GRAFO_H
#define GRAFO_H

// Estrutura para um vértice na lista de adjacência
typedef struct vertice {
    int id; // ID do vértice (representa uma capital)
    struct vertice* prox; // Ponteiro para o próximo vértice na lista
} Vertice;

// Estrutura para a lista de adjacência de um vértice
typedef struct listaArestas {
    Vertice* head; // Cabeça da lista de adjacência
} ListaArestas;

// Estrutura para o grafo
typedef struct grafo {
    int nro_vertices; // Número total de vértices (capitais)
    ListaArestas* arestas; // Array de listas de adjacência
} Grafo;

// Funções do grafo
Grafo* cria_grafo(int nro_vertices);
void adiciona_aresta(Grafo* gr, int origem, int destino);
void exibe_grafo(Grafo* gr);
void libera_grafo(Grafo* gr);

// Algoritmos de busca
void dfs(Grafo* gr, int origem, int* visitados, int* resultado, int* index, int* cds, int n_cds);
int bfs(Grafo* gr, int origem, int* cds, int n_cds);

#endif
