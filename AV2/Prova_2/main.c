#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "estrutura.h"

// Função para exibir o menu
void exibir_menu() {
    printf("\n--- Sistema de Gerenciamento de Transplantes ---\n");
    printf("1. Adicionar doação\n");
    printf("2. Processar doação\n");
    printf("3. Exibir estado das estruturas\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

// Função para exibir as capitais e seus IDs
void exibir_capitais() {
    const char* capitais[] = {
        "Rio Branco", "Porto Velho", "Manaus", "Boa Vista", "Belém", 
        "Macapá", "Palmas", "São Luís", "Teresina", "Fortaleza", 
        "Natal", "João Pessoa", "Recife", "Maceió", "Aracaju", 
        "Salvador", "Brasília", "Goiânia", "Cuiabá", "Campo Grande", 
        "Belo Horizonte", "Vitória", "Rio de Janeiro", "São Paulo", 
        "Curitiba", "Florianópolis", "Porto Alegre"
    };

    printf("\n--- Capitais e seus IDs ---\n");
    for (int i = 0; i < 27; i++) {
        printf("ID: %d - %s\n", i, capitais[i]);
    }
    printf("---------------------------\n");
}

// Função para encontrar o CD mais próximo usando BFS
int encontrar_cd_bfs(Grafo* grafo, int origem, int* cds, int n_cds) {
    return bfs(grafo, origem, cds, n_cds);
}

int main() {
    // Inicialização do grafo
    int n_capitais = 27; // Número de capitais
    Grafo* grafo = cria_grafo(n_capitais);
    
    // Adicionar conexões entre capitais
   // Adicionar conexões baseadas na lista manual
    adiciona_aresta(grafo, 0, 2);  // Rio Branco -> Manaus
    adiciona_aresta(grafo, 1, 2);  // Porto Velho -> Manaus
    adiciona_aresta(grafo, 2, 0);  // Manaus -> Rio Branco
    adiciona_aresta(grafo, 2, 1);  // Manaus -> Porto Velho
    adiciona_aresta(grafo, 2, 3);  // Manaus -> Boa Vista
    adiciona_aresta(grafo, 3, 2);  // Boa Vista -> Manaus
    adiciona_aresta(grafo, 3, 4);  // Boa Vista -> Belém
    adiciona_aresta(grafo, 4, 3);  // Belém -> Boa Vista
    adiciona_aresta(grafo, 4, 5);  // Belém -> Macapá
    adiciona_aresta(grafo, 4, 6);  // Belém -> Brasília
    adiciona_aresta(grafo, 4, 7);  // Belém -> São Luís
    adiciona_aresta(grafo, 5, 4);  // Macapá -> Belém
    adiciona_aresta(grafo, 7, 4);  // São Luís -> Belém
    adiciona_aresta(grafo, 7, 9);  // São Luís -> Fortaleza
    adiciona_aresta(grafo, 7, 8);  // São Luís -> Teresina
    adiciona_aresta(grafo, 7, 6);  // São Luís -> Palmas
    adiciona_aresta(grafo, 9, 7);  // Fortaleza -> São Luís
    adiciona_aresta(grafo, 9, 10); // Fortaleza -> Natal
    adiciona_aresta(grafo, 9, 6);  // Fortaleza -> Brasília
    adiciona_aresta(grafo, 10, 9); // atal -> Fortaleza
    adiciona_aresta(grafo, 10, 11); //Natal -> João Pessoa
    adiciona_aresta(grafo, 11, 10); //João Pessoa -> Natal
    adiciona_aresta(grafo, 11, 12); //João Pessoa -> Recife
    adiciona_aresta(grafo, 12, 11); //Recife -> João Pessoa
    adiciona_aresta(grafo, 12, 13); //Recife -> Maceió
    adiciona_aresta(grafo, 13, 12); //Maceió -> Recife
    adiciona_aresta(grafo, 13, 14); //Maceió -> Aracaju
    adiciona_aresta(grafo, 14, 13); //Aracaju -> Maceió
    adiciona_aresta(grafo, 14, 15); //Aracaju -> Salvador
    adiciona_aresta(grafo, 15, 14); //Salvador -> Aracaju
    adiciona_aresta(grafo, 15, 6);  //Salvador -> Brasília
    adiciona_aresta(grafo, 8, 7);   //Teresina -> São Luís
    adiciona_aresta(grafo, 8, 6);   //Teresina -> Palmas
    adiciona_aresta(grafo, 6, 4);   //Palmas -> Belém
    adiciona_aresta(grafo, 6, 7);   //Palmas -> São Luís
    adiciona_aresta(grafo, 6, 8);   //Palmas -> Teresina
    adiciona_aresta(grafo, 6, 9);   //Palmas -> Brasília
    adiciona_aresta(grafo, 6, 15);  //Palmas -> Salvador
    adiciona_aresta(grafo, 6, 16);  //Palmas -> Belo Horizonte
    adiciona_aresta(grafo, 16, 6);  //Brasília -> Palmas
    adiciona_aresta(grafo, 16, 17); //Brasília -> Goiânia
    adiciona_aresta(grafo, 16, 18); //Brasília -> Cuiabá
    adiciona_aresta(grafo, 16, 20); //Brasília -> Belo Horizonte
    adiciona_aresta(grafo, 16, 23); //Brasília -> São Paulo
    adiciona_aresta(grafo, 17, 16); //Goiânia -> Brasília
    adiciona_aresta(grafo, 17, 19); //Goiânia -> Campo Grande
    adiciona_aresta(grafo, 19, 17); //Campo Grande -> Goiânia
    adiciona_aresta(grafo, 19, 18); //Campo Grande -> Cuiabá
    adiciona_aresta(grafo, 19, 23); //Campo Grande -> São Paulo
    adiciona_aresta(grafo, 18, 19); //Cuiabá -> Campo Grande
    adiciona_aresta(grafo, 18, 16); //Cuiabá -> Brasília
    adiciona_aresta(grafo, 20, 16); //Belo Horizonte -> Brasília
    adiciona_aresta(grafo, 20, 21); //Belo Horizonte -> Vitória
    adiciona_aresta(grafo, 20, 22); //Belo Horizonte -> Rio de Janeiro
    adiciona_aresta(grafo, 20, 23); //Belo Horizonte -> São Paulo
    adiciona_aresta(grafo, 21, 20); //Vitória -> Belo Horizonte
    adiciona_aresta(grafo, 22, 20); //Rio de Janeiro -> Belo Horizonte
    adiciona_aresta(grafo, 22, 23); //Rio de Janeiro -> São Paulo
    adiciona_aresta(grafo, 23, 16); //São Paulo -> Brasília
    adiciona_aresta(grafo, 23, 20); //São Paulo -> Belo Horizonte
    adiciona_aresta(grafo, 23, 19); //São Paulo -> Campo Grande
    adiciona_aresta(grafo, 23, 24); //São Paulo -> Curitiba
    adiciona_aresta(grafo, 24, 23); //Curitiba -> São Paulo
    adiciona_aresta(grafo, 24, 25); //Curitiba -> Florianópolis
    adiciona_aresta(grafo, 25, 24); //Florianópolis -> Curitiba
    adiciona_aresta(grafo, 25, 26); //Florianópolis -> Porto Alegre
    adiciona_aresta(grafo, 26, 25); //Porto Alegre -> Florianópolis


    // CDs: IDs das capitais com centros de distribuição
    int cds[] = {9, 16, 23}; // Fortaleza, Brasília, São Paulo
    int n_cds = sizeof(cds) / sizeof(cds[0]);

    // Inicialização das estruturas
    Pilha* pilhaBrasilia = cria_pilha();
    Pilha* pilhaFortaleza = cria_pilha();
    Pilha* pilhaSaoPaulo = cria_pilha();

    Fila* filaBrasilia = cria_fila();
    Fila* filaFortaleza = cria_fila();
    Fila* filaSaoPaulo = cria_fila();

    ListaGlobal* listaGlobal = cria_lista_global();

    // Menu interativo
    int opcao;
    do {
        exibir_menu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Adicionar doação
            exibir_capitais();
            int origem;
            char tipo[20];
            printf("Digite o ID da capital de origem (0 a 26): ");
            scanf("%d", &origem);

            // Validação do ID inserido
            if (origem < 0 || origem > 26) {
                printf("ID inválido! Por favor, escolha um ID entre 0 e 26.\n");
                continue;
            }

            printf("Digite o tipo de órgão (CORAÇÃO, MEDULA, CÓRNEA): ");
            scanf("%s", tipo);

            // Validação do tipo de órgão
            if (strcmp(tipo, "CORAÇÃO") != 0 && strcmp(tipo, "MEDULA") != 0 && strcmp(tipo, "CÓRNEA") != 0) {
                printf("Tipo de órgão inválido! Por favor, escolha entre CORAÇÃO, MEDULA ou CÓRNEA.\n");
                continue;
            }

            // Criar órgão
            Orgao* novo_orgao = (Orgao*) malloc(sizeof(Orgao));
            novo_orgao->id = rand() % 1000;
            strcpy(novo_orgao->tipo, tipo);
            sprintf(novo_orgao->origem, "Capital %d", origem);
            strcpy(novo_orgao->status, "Em espera para transplante");

            // Determinar o CD mais próximo
            int cd_mais_proximo = encontrar_cd_bfs(grafo, origem, cds, n_cds);
            if (cd_mais_proximo == -1) {
                printf("Erro: Não foi possível encontrar um CD conectado à capital de origem.\n");
                free(novo_orgao);
                continue;
            }

            // Adicionar à estrutura apropriada
            if (strcmp(tipo, "CORAÇÃO") == 0) {
                if (cd_mais_proximo == 16) {
                    adiciona_pilha(pilhaBrasilia, novo_orgao);
                } else if (cd_mais_proximo == 9) {
                    adiciona_pilha(pilhaFortaleza, novo_orgao);
                } else if (cd_mais_proximo == 23) {
                    adiciona_pilha(pilhaSaoPaulo, novo_orgao);
                }
            } else {
                if (cd_mais_proximo == 16) {
                    adiciona_fila(filaBrasilia, novo_orgao);
                } else if (cd_mais_proximo == 9) {
                    adiciona_fila(filaFortaleza, novo_orgao);   
                } else if (cd_mais_proximo == 23) {
                    adiciona_fila(filaSaoPaulo, novo_orgao);
                }
            }

            adiciona_lista_global(listaGlobal, novo_orgao);
            printf("Doação adicionada com sucesso no CD mais próximo (%d).\n", cd_mais_proximo);

        } else if (opcao == 2) {
            // Processar doação
            int cd;
            printf("Escolha o CD para processar a doação (1 - Brasília, 2 - Fortaleza, 3 - São Paulo): ");
            scanf("%d", &cd);

            Orgao* orgao_removido = NULL;

            if (cd == 1) { // CD Brasília
                if (!pilha_vazia(pilhaBrasilia)) {
                    orgao_removido = remove_pilha(pilhaBrasilia);
                } else if (!fila_vazia(filaBrasilia)) {
                    orgao_removido = remove_fila(filaBrasilia);
                }
            } else if (cd == 2) { // CD Fortaleza
                if (!pilha_vazia(pilhaFortaleza)) {
                    orgao_removido = remove_pilha(pilhaFortaleza);
                } else if (!fila_vazia(filaFortaleza)) {
                    orgao_removido = remove_fila(filaFortaleza);
                }
            } else if (cd == 3) { // CD São Paulo
                if (!pilha_vazia(pilhaSaoPaulo)) {
                    orgao_removido = remove_pilha(pilhaSaoPaulo);
                } else if (!fila_vazia(filaSaoPaulo)) {
                    orgao_removido = remove_fila(filaSaoPaulo);
                }
            } else {
                printf("CD inválido! Por favor, escolha 1, 2 ou 3.\n");
                continue;
            }

            if (orgao_removido) {
                printf("Órgão do tipo %s processado com sucesso.\n", orgao_removido->tipo);
                atualiza_status_lista_global(listaGlobal, orgao_removido->id, "Órgão transplantado");
                free(orgao_removido);
            } else {
                printf("Não há órgãos disponíveis para transplante neste CD.\n");
            }

        } else if (opcao == 3) {
            // Exibir estado das estruturas
            printf("\n--- Brasília ---\n");
            exibe_pilha(pilhaBrasilia);
            exibe_fila(filaBrasilia);

            printf("\n--- Fortaleza ---\n");
            exibe_pilha(pilhaFortaleza);
            exibe_fila(filaFortaleza);

            printf("\n--- São Paulo ---\n");
            exibe_pilha(pilhaSaoPaulo);
            exibe_fila(filaSaoPaulo);

            printf("\n--- Lista Global ---\n"); 
            exibe_lista_global(listaGlobal);
        }

    } while (opcao != 4);

    // Libera memória
    libera_pilha(pilhaBrasilia);
    libera_pilha(pilhaFortaleza);
    libera_pilha(pilhaSaoPaulo);
    libera_fila(filaBrasilia);
    libera_fila(filaFortaleza);
    libera_fila(filaSaoPaulo);
    libera_lista_global(listaGlobal);
    libera_grafo(grafo);

    printf("Sistema encerrado.\n");
    return 0;
}