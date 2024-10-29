#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

#define NUM_INSERCOES 100
#define NUM_REMOCOES 40

const char* gera_tipo_transplante() {
    const char* tipos[] = {"CORAÇÃO", "CÓRNEA", "MEDULA"};
    return tipos[rand() % 3];
}

void simula_operacoes(Fila* fila_transplante) {
    for (int i = 0; i < NUM_INSERCOES; i++) {
        Paciente pac;
        pac.id = i + 1;
        strcpy(pac.tipo, gera_tipo_transplante());
        insere_fila(fila_transplante, pac);
    }

    for (int i = 0; i < NUM_REMOCOES; i++) {
        if (!fila_vazia(fila_transplante)) {
            remove_fila(fila_transplante);
        }
    }
}

int main() {
    srand(time(NULL));

    Fila* fila_transplante = cria_fila();
    simula_operacoes(fila_transplante);
    libera_fila(fila_transplante);

    printf("Simulação de transplante concluída.\n");
    return 0;
}
