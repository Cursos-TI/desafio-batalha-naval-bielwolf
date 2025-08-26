//------Bibliotecas---------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

//Limpar o buffer
void limparBufferEntrada() {
    int c;
    while ((c = getchar ()) != '\n' && c != EOF);
}

//funcao atacar
void atacar(t *atacante, t *defensor) {
    int intervalo = time (0);
    srand(intervalo);

    //gera um numero aleatorio no intervalo entre 1 e 6
    int dadoAtacante = (intervalo % 6) + 1;
    int dadoDefensor = (intervalo % 6) + 1;

    //exibe mensagem do nome e do resultado no numero
    prinf("\nAtacante entre %s (A) e %s (D)\n", atacante->nome, defensor->nome);
    printf("Dado atacante: %d | Dado defensor: %d\n", dadoAtacante, dadoDefensor);

    //opcao para o ataque
    if(dadoAtacante > dadoDefensor) {
        printf("Vitória do atacante");

        strcpy(defensor->cor, atacante->cor);

        int tropasTransferidas = atacante->tropas / 2;

        atacante->tropas -= tropasTransferidas;
        defensor->tropas += tropasTransferidas;

        //opcao para caso o defensor vence
    } else {
        printf("O defenso resistiu ao ataque!\n");

        if(atacante->tropas > 1) {
            atacante->tropas -= 1;
        } else {
            printf("O atacante não pode perder mais tropas!");
        }
    }
}

void liberarMemoria(t *registro) {
    free(registro);
    printf("Memória liberada com sucesso!");
}

int main () {

    int numterritorios = 0;

    printf("Quantos territórios deseja armazenar?\n");
    scanf("%d", &numterritorios);
    limparBufferEntrada();
    
    //criando que armazena x posições dinamicamente usando calloc
    t *registro = (t*) calloc (numterritorios, sizeof(t));

    //loop para registrar os 5 territorios e suas informações
    for (int i = 0; i < numterritorios; i++) {
        printf("Registre o nome do território: ");
        scanf(" %s", registro[i].nome);
        printf("Registre a cor do território: ");
        scanf(" %s", registro[i].cor);
        printf("Registre o número de tropas no território: ");
        scanf("%d", &registro[i].tropas);
    }

    //chama a funcão atacar
    atacar(&registro[0], &registro[1]);

    //exibição dos registros feitos
    printf("Registro de todos os territorios:\n");
    for (int i = 0; i < numterritorios; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", registro[i].nome);
        printf("Cor: %s\n", registro[i].cor);
        printf("Tropas: %d\n", registro[i].tropas);
        printf("-------------------------------\n");

    }

    liberarMemoria(registro);
    return 0;
    
}