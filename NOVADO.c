#include <stdio.h>

int main() {
    // 1. Criando o tabuleiro 10x10 e inicializando com água (valor 0)
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definindo tamanho fixo dos navios
    int tamanho_navio = 3;

    // 3. Definindo coordenadas iniciais dos navios
    // Navio vertical começa na linha 2, coluna C (índice 2)
    int linha_vertical = 1;
    int coluna_vertical = 2;

    // Navio horizontal começa na linha 6, coluna E (índice 4)
    int linha_horizontal = 5;
    int coluna_horizontal = 4;

    // 4. Validando se os navios cabem no tabuleiro
    if (linha_vertical + tamanho_navio > 10 || coluna_horizontal + tamanho_navio > 10) {
        printf("Erro: navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    // 5. Verificando sobreposição simplificada
    for (int i = 0; i < tamanho_navio; i++) {
        if (tabuleiro[linha_vertical + i][coluna_vertical] == 3 ||
            tabuleiro[linha_horizontal][coluna_horizontal + i] == 3) {
            printf("Erro: sobreposição de navios.\n");
            return 1;
        }
    }

    // 6. Posicionando navio vertical
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // 7. Posicionando navio horizontal
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // 8. Exibindo o tabuleiro com letras nas colunas e números nas linhas
    printf("  Tabuleiro Batalha Naval\n ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", 'A' + j); // Cabeçalho das colunas com letras
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // Números das linhas começando em 1
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}