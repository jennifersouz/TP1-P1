#ifndef utilizador_h
#define utilizador_h

typedef struct Utilizador {
    char username[50];
    char password[50];
    int tipo; // 0 = admin, 1 = técnico
    int validado;
} Utilizador;

#endif
