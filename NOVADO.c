#include <stdio.h>

int main() {
    // 1. Criando o tabuleiro 10x10 e inicializando com água (valor 0)
    int tabuleiro[10][10];
    tabuleiro[0][0] = 0; tabuleiro[0][1] = 0; tabuleiro[0][2] = 0; tabuleiro[0][3] = 0; tabuleiro[0][4] = 0;
    tabuleiro[0][5] = 0; tabuleiro[0][6] = 0; tabuleiro[0][7] = 0; tabuleiro[0][8] = 0; tabuleiro[0][9] = 0;
    tabuleiro[1][0] = 0; tabuleiro[1][1] = 0; tabuleiro[1][2] = 0; tabuleiro[1][3] = 0; tabuleiro[1][4] = 0;
    tabuleiro[1][5] = 0; tabuleiro[1][6] = 0; tabuleiro[1][7] = 0; tabuleiro[1][8] = 0; tabuleiro[1][9] = 0;
    tabuleiro[2][0] = 0; tabuleiro[2][1] = 0; tabuleiro[2][2] = 0; tabuleiro[2][3] = 0; tabuleiro[2][4] = 0;
    tabuleiro[2][5] = 0; tabuleiro[2][6] = 0; tabuleiro[2][7] = 0; tabuleiro[2][8] = 0; tabuleiro[2][9] = 0;
    tabuleiro[3][0] = 0; tabuleiro[3][1] = 0; tabuleiro[3][2] = 0; tabuleiro[3][3] = 0; tabuleiro[3][4] = 0;
    tabuleiro[3][5] = 0; tabuleiro[3][6] = 0; tabuleiro[3][7] = 0; tabuleiro[3][8] = 0; tabuleiro[3][9] = 0;
    tabuleiro[4][0] = 0; tabuleiro[4][1] = 0; tabuleiro[4][2] = 0; tabuleiro[4][3] = 0; tabuleiro[4][4] = 0;
    tabuleiro[4][5] = 0; tabuleiro[4][6] = 0; tabuleiro[4][7] = 0; tabuleiro[4][8] = 0; tabuleiro[4][9] = 0;
    tabuleiro[5][0] = 0; tabuleiro[5][1] = 0; tabuleiro[5][2] = 0; tabuleiro[5][3] = 0; tabuleiro[5][4] = 0;
    tabuleiro[5][5] = 0; tabuleiro[5][6] = 0; tabuleiro[5][7] = 0; tabuleiro[5][8] = 0; tabuleiro[5][9] = 0;
    tabuleiro[6][0] = 0; tabuleiro[6][1] = 0; tabuleiro[6][2] = 0; tabuleiro[6][3] = 0; tabuleiro[6][4] = 0;
    tabuleiro[6][5] = 0; tabuleiro[6][6] = 0; tabuleiro[6][7] = 0; tabuleiro[6][8] = 0; tabuleiro[6][9] = 0;
    tabuleiro[7][0] = 0; tabuleiro[7][1] = 0; tabuleiro[7][2] = 0; tabuleiro[7][3] = 0; tabuleiro[7][4] = 0;
    tabuleiro[7][5] = 0; tabuleiro[7][6] = 0; tabuleiro[7][7] = 0; tabuleiro[7][8] = 0; tabuleiro[7][9] = 0;
    tabuleiro[8][0] = 0; tabuleiro[8][1] = 0; tabuleiro[8][2] = 0; tabuleiro[8][3] = 0; tabuleiro[8][4] = 0;
    tabuleiro[8][5] = 0; tabuleiro[8][6] = 0; tabuleiro[8][7] = 0; tabuleiro[8][8] = 0; tabuleiro[8][9] = 0;
    tabuleiro[9][0] = 0; tabuleiro[9][1] = 0; tabuleiro[9][2] = 0; tabuleiro[9][3] = 0; tabuleiro[9][4] = 0;
    tabuleiro[9][5] = 0; tabuleiro[9][6] = 0; tabuleiro[9][7] = 0; tabuleiro[9][8] = 0; tabuleiro[9][9] = 0;

    // 2. Posicionando navio vertical (linha 2, coluna C)
    tabuleiro[1][2] = 3;
    tabuleiro[2][2] = 3;
    tabuleiro[3][2] = 3;

    // 3. Posicionando navio horizontal (linha 6, coluna E)
    tabuleiro[5][4] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[5][6] = 3;

    // 4. Exibindo tabuleiro (simplificado, sem for)
    printf("  Tabuleiro Batalha Naval\n A B C D E F G H I J\n");
    printf(" 1 %d %d %d %d %d %d %d %d %d %d\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2], tabuleiro[0][3], tabuleiro[0][4], tabuleiro[0][5], tabuleiro[0][6], tabuleiro[0][7], tabuleiro[0][8], tabuleiro[0][9]);
    printf(" 2 %d %d %d %d %d %d %d %d %d %d\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2], tabuleiro[1][3], tabuleiro[1][4], tabuleiro[1][5], tabuleiro[1][6], tabuleiro[1][7], tabuleiro[1][8], tabuleiro[1][9]);
    // ... repita para todas as linhas até 10

    return 0;
}