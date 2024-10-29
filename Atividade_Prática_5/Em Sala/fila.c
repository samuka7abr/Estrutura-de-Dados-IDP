#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila* cria_fla(){
    Fila* f = (Fila*) malloc(sizeof(Fila)); //cria um ponteiro tipo fla e armazena na memória o tamanho da fla
    if(f != NULL){
        f->inicio = NULL; //defne o início e o fm como NULL, pois a fla está vazia
        f->final = NULL;
    }
}

void libera_fla(Fila* f){
    if(f != NULL){
        Elem* no; //cria um ponteiro (tipo Elem, pois vai acessar os elementos da fila) para percorrer a fila
        while(f->inicio != NULL){
            no = f->inicio; //iguala ele ao índice 1 
            f->inicio = f->inicio->prox; //iguala o indice 1 ao proximo para ir liberando
            free(no);
        }
        free(f);
    }

}

int insere_fila(Fila* f, Paciente p){
    if(f == NULL){return 0;}
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){return 0;}
    no->dados = p;
    no->prox = NULL;
    
}