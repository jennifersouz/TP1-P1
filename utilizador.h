#ifndef utilizador_h
#define utilizador_h

typedef struct Utilizador {
    char username[50];
    char password[50];
    char nome[MAX];
    long nif;
    long telefone;
    char email[MAX];
    int tipo; // 0 = admin, 1 = técnico
    int status; // 0 = não validado, 1 = validado
} Utilizador;

#endif
