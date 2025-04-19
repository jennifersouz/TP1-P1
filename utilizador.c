
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilizador.h"

#define MAX 100  // Definido localmente, pois é usado no header

// Função para verificar se a senha contém tanto letras quanto números
int validarSenha(const char *senha) {
    int temLetra = 0, temNumero = 0;
    for (int i = 0; senha[i] != '\0'; i++) {
        if (isalpha(senha[i])) temLetra = 1;
        if (isdigit(senha[i])) temNumero = 1;
        if (temLetra && temNumero) return 1;
    }
    return 0;  // Retorna 0 se não contiver tanto letras quanto números
}

// Função para verificar se os dados já existem (email, username, telefone, nif)
int validarDadosExistentes(Utilizador *u[], int q, const Utilizador *novoUser) {
    for (int i = 0; i < q; i++) {
        if (u[i]->nif == novoUser->nif) {
            printf("Erro: NIF já cadastrado!\n");
            return 1;
        }
        if (u[i]->telefone == novoUser->telefone) {
            printf("Erro: Número de telefone já cadastrado!\n");
            return 1;
        }
        if (strcmp(u[i]->email, novoUser->email) == 0) {
            printf("Erro: Email já cadastrado!\n");
            return 1;
        }
        if (strcmp(u[i]->username, novoUser->username) == 0) {
            printf("Erro: Nome de usuário (username) já cadastrado!\n");
            return 1;
        }
    }
    return 0;  // Retorna 0 se nenhum dado foi encontrado
}

// Função principal para cadastrar um novo utilizador
void cadastrarUtilizador(Utilizador *u[], int q) {
    // Aloca espaço para um novo utilizador
    u[q] = (Utilizador *)malloc(sizeof(Utilizador));
    if (u[q] == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    printf("Digite seu nome completo: ");
    scanf(" %[^\n]", u[q]->nome);

    printf("Digite seu NIF: ");
    scanf("%ld", &u[q]->nif);

    printf("Digite seu número de telefone: ");
    scanf("%ld", &u[q]->telefone);

    printf("Digite seu email: ");
    scanf(" %[^\n]", u[q]->email);

    printf("Escolha um nome de utilizador (username): ");
    scanf(" %[^\n]", u[q]->username);

    printf("Crie uma senha (password): ");
    scanf(" %[^\n]", u[q]->password);

    // Validação dos dados
    if (validarDadosExistentes(u, q, u[q] == 1)) {
        continue;   // Se houver erro, continua o loop
    }

    if (!validarSenha(u[q]->password)) {
        printf("Erro: A senha deve conter tanto letras quanto números!\n");
        continue;   // Se houver erro, continua o loop
    }

    if (q == 0) {
        u[q]->tipo = 1;        // Primeiro utilizador é administrador
        u[q]->status = -1;     // Como é um adm, não é necessária a validação então usei "-1"
    } else {
        u[q]->tipo = 0;        // Técnico padrão
        u[q]->status = 0;      // Ainda não validado
    }

    // Salvar novo utilizador no arquivo
    FILE *arquivo = fopen("..\\usuario.dat", "ab");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo!\n");
        free(u[q]);  // Libera a memória em caso de erro
        return;
    }

    fwrite(u[q], sizeof(Utilizador), 1, arquivo);
    fclose(arquivo);

    printf("Usuário cadastrado com sucesso!\n");
    q++;
    
}

// Exibe os dados do utilizador
void exibirUtilizador(Utilizador u) {
    printf("-----------------------------------------\n");
    printf("Username: %s\n", u.username);
    printf("Nome: %s\n", u.nome);
    printf("NIF: %ld\n", u.nif);
    printf("Telefone: %ld\n", u.telefone);
    printf("Email: %s\n", u.email);
    printf("Tipo: %s\n", u.tipo == 0 ? "Admin" : "Técnico");
    if (u.tipo != 0) {
        printf("Status: %s\n", u.status == 0 ? "Não validado" : "Validado");
    }
    printf("-----------------------------------------\n");
}


