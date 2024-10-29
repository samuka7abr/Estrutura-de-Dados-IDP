#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void carregar_pacientes(Fila* f) {
    FILE* arquivo = fopen("pacientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de pacientes.\n");
        exit(1);
    }

    Paciente p;
    while (fscanf(arquivo, "%d %49s %49s", &p.id, p.nome, p.tipo) != EOF) {
        if (!enqueue(f, p)) {
            printf("Fila cheia. Não foi possível adicionar o paciente %s.\n", p.nome);
            break;
        }
    }

    fclose(arquivo);
}

void remover_pacientes(Fila* f, int num_remocoes) {
    Paciente p;
    for (int i = 0; i < num_remocoes; i++) {
        if (dequeue(f, &p)) { 
            printf("Paciente removido: ID %d, Nome %s, Tipo %s\n", 
                   p.id, p.nome, p.tipo);
        } else {
            printf("Fila vazia. Não há mais pacientes para remover.\n");
            break;
        }
    }
}

int main() {
    Fila fila_pacientes;
    inicializa_fila(&fila_pacientes);

    printf("Carregando pacientes...\n");
    carregar_pacientes(&fila_pacientes);

    printf("\nFila após a carga inicial:\n");
    exibir_fila(&fila_pacientes);

    printf("\nRemovendo 40 pacientes aleatoriamente...\n");
    remover_pacientes(&fila_pacientes, 40);

    printf("\nFila após remoções:\n");
    exibir_fila(&fila_pacientes);

    return 0;
}
