#include <stdio.h>

#define TAM 10      // Define o tamanho do tabuleiro (10x10)
#define NAVIO 3     // Define o tamanho fixo dos navios
#define AGUA 0      // Valor para representar a água
#define OCUPADO 3   // Valor para representar um navio

/**
 * @brief Verifica se um navio pode ser posicionado nas coordenadas fornecidas.
 * * @param tabuleiro O tabuleiro do jogo.
 * @param linha Array com as coordenadas da linha para cada parte do navio.
 * @param coluna Array com as coordenadas da coluna para cada parte do navio.
 * @return int 1 (verdadeiro) se puder posicionar, 0 (falso) caso contrário.
 */
int pode_posicionar(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    // Itera sobre cada parte do navio
    for (int i = 0; i < NAVIO; i++) {
        // 1. Verifica se está dentro dos limites do tabuleiro
        if (linha[i] < 0 || linha[i] >= TAM || coluna[i] < 0 || coluna[i] >= TAM)
            return 0; // Posição fora do tabuleiro
        
        // 2. Verifica se a posição já está ocupada (sobreposição)
        if (tabuleiro[linha[i]][coluna[i]] != AGUA)
            return 0; // Posição já ocupada
    }
    return 1; // Posição válida
}