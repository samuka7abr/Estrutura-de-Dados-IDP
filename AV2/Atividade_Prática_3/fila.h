typedef struct pilha{
    int num;
} Pilha;
typedef struct elemento
{
    Pilha dados;
    Elem *prox;
} Elem;

Pilha* cria_pilha();
void libera_pilha(Pilha* p);
int tamanho_pilha(Pilha* pi);
int pilha_vazia(Pilha* pi); 
int insere_pilha(Pilha* pi);