typedef struct paciente {
    int id;
    char tipo[10]; 
} Paciente;

typedef struct elemento {
    Paciente dados;
    struct elemento *prox;
} Elem;

typedef struct fila {
    Elem *inicio;
    Elem *final;
    int qtd;
} Fila;

Fila* cria_fila();
void libera_fila(Fila* fi);
int insere_fila(Fila* fi, Paciente pac);
int remove_fila(Fila* fi);
int tamanho_fila(Fila* fi);
int fila_vazia(Fila* fi);

