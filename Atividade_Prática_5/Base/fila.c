#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializa_fila(Fila* f) {
    f->front = 0; 
    f->rear = -1;
}

int enqueue(Fila *f, Paciente p) {
    if (isFull(f)) return 0;  
    f->rear++;
    f->elementos[f->rear] = p; 
    return 1;  
}

int dequeue(Fila* f, Paciente* p) {
    if (isEmpty(f)) return 0;  
    *p = f->elementos[f->front];  
    f->front++;  
    return 1;  
}

int isEmpty(Fila* f) {
    return f->front > f->rear;  
}

int isFull(Fila* f) {
    return f->rear == TAMANHO - 1;  
}

void exibir_fila(Fila* f) {
    if (isEmpty(f)) {
        printf("Fila vazia.\n");
        return;
    }
    for (int i = f->front; i <= f->rear; i++) {
        printf("ID: %d, Nome: %s, Tipo: %s\n", 
               f->elementos[i].id, 
               f->elementos[i].nome, 
               f->elementos[i].tipo);
    }
}
