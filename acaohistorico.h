#ifndef acaohistorico_h
#define acaohistorico_h

typedef struct AcaoHistorico {
    int idIncidente;
    char usernameTecnico[50];
    char dataHora[20];
    char descricaoAcao[250];
} AcaoHistorico;

#endif