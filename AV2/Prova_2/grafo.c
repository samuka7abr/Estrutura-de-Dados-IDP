#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

// Cria o grafo
Grafo* cria_grafo(int nro_vertices) {
    Grafo* gr = (Grafo*) malloc(sizeof(Grafo));
    gr->nro_vertices = nro_vertices;
    gr->arestas = (ListaArestas*) malloc(nro_vertices * sizeof(ListaArestas));
    for (int i = 0; i < nro_vertices; i++) {
        gr->arestas[i].head = NULL;
    }
    return gr;
}

// Adiciona uma aresta ao grafo (não direcionada)
void adiciona_aresta(Grafo* gr, int origem, int destino) {
    Vertice* novo = (Vertice*) malloc(sizeof(Vertice));
    novo->id = destino;
    novo->prox = gr->arestas[origem].head;
    gr->arestas[origem].head = novo;

    // Adiciona a conexão reversa, pois o grafo é não direcionado
    novo = (Vertice*) malloc(sizeof(Vertice));
    novo->id = origem;
    novo->prox = gr->arestas[destino].head;
    gr->arestas[destino].head = novo;
}

// Exibe o grafo
void exibe_grafo(Grafo* gr) {
    for (int i = 0; i < gr->nro_vertices; i++) {
        printf("Cidade %d conecta-se com: ", i);
        Vertice* atual = gr->arestas[i].head;
        while (atual) {
            printf("%d ", atual->id);
            atual = atual->prox;
        }
        printf("\n");
    }
}

// Libera a memória do grafo
void libera_grafo(Grafo* gr) {
    for (int i = 0; i < gr->nro_vertices; i++) {
        Vertice* atual = gr->arestas[i].head;
        while (atual) {
            Vertice* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(gr->arestas);
    free(gr);
}

// Algoritmo DFS (Busca em Profundidade)
void dfs(Grafo* gr, int origem, int* visitados, int* resultado, int* index, int* cds, int n_cds) {
    visitados[origem] = 1;
    for (int i = 0; i < n_cds; i++) {
        if (origem == cds[i]) {
            resultado[*index] = origem;
            (*index)++;
            return;
        }
    }

    Vertice* atual = gr->arestas[origem].head;
    while (atual) {
        if (!visitados[atual->id]) {
            dfs(gr, atual->id, visitados, resultado, index, cds, n_cds);
        }
        atual = atual->prox;
    }
}

// Algoritmo BFS (Busca em Largura)
int bfs(Grafo* gr, int origem, int* cds, int n_cds) {
    int* visitados = (int*) calloc(gr->nro_vertices, sizeof(int));
    int* fila = (int*) malloc(gr->nro_vertices * sizeof(int));
    int inicio = 0, fim = 0;

    visitados[origem] = 1;
    fila[fim++] = origem;

    while (inicio < fim) {
        int atual = fila[inicio++];
        for (int i = 0; i < n_cds; i++) {
            if (atual == cds[i]) {
                free(visitados);
                free(fila);
                return atual; // Retorna o CD encontrado
            }
        }

        Vertice* adj = gr->arestas[atual].head;
        while (adj) {
            if (!visitados[adj->id]) {
                visitados[adj->id] = 1;
                fila[fim++] = adj->id;
            }
            adj = adj->prox;
        }
    }

    free(visitados);
    free(fila);
    return -1; // Nenhum CD encontrado (teoricamente impossível agora)
}

