#ifndef acaohistorico_h
#define acaohistorico_h

typedef struct Acao {
    int idIncidente;
    char usernameTecnico[50];
    char dataHora[20];
    char descricao[250];
    char ferramenta[50];
    struct Acao *prox;    // Próximo elemento da lista
    struct Acao *ant;     // Elemento anterior da lista (NOVO)
} Acao;

#endif