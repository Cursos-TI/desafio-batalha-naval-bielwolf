#include <stdio.h>

int main () {
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // Navios de tamanho 3
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};
    
    // Posição do navio horizontal
    int linha_horizontal = 2;
    int coluna_horizontal = 1;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    // Posição do navio vertical
    int linha_vertical = 5;
    int coluna_vertical = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    // Imprime letras das colunas
    printf("  ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", coluna[j]);
    }
    printf("\n");

    // Imprime o tabuleiro com numeração das linhas
    for(int i = 0; i < 9; i++){
        if (i < 8) {
            printf("%d ", i); // alinhar 0 
        } else {
            printf("%d ", i + 1); // para o 9
        }

        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}