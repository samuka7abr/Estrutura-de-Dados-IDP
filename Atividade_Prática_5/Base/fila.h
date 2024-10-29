#define TAMANHO 100

typedef struct{
    int id;
    char nome[50];
    char tipo[50];
} Paciente; 

typedef struct{
    Paciente elementos[TAMANHO]; 
    int front; 
    int rear; 
} Fila;

void inicializa_fila(Fila* f);
int enqueue(Fila* f, Paciente p);
int dequeue(Fila* f, Paciente* p);
int isEmpty(Fila* f);
int isFull(Fila* f);
void exibir_fila(Fila* f);
