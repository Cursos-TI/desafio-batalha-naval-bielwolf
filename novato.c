//------Bibliotecas---------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----Variaveis Globais------
#define TAM_STRING 30
#define COR 10

//definindo a struct e nomeando
struct territorio {
    char nome[TAM_STRING];
    char cor[COR];
    int tropas;
};

//apelidando
typedef  struct territorio t;

int main () {

    //criando o vetor com 5 posições
    t registro[5];

    //loop para registrar os 5 territorios e suas informações
    for (int i = 0; i < 5; i++) {
        printf("Registre o nome do território: ");
        scanf(" %s", registro[i].nome);
        printf("Registre a cor do território: ");
        scanf(" %s", registro[i].cor);
        printf("Registre o número de tropas no território: ");
        scanf("%d", &registro[i].tropas);
    }

    //exibição dos registros feitos
    printf("Registro de todos os territorios:\n");
    for (int i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", registro[i].nome);
        printf("Cor: %s\n", registro[i].cor);
        printf("Tropas: %d\n", registro[i].tropas);
        printf("-------------------------------\n");

    }

    return 0;
    
}