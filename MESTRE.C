#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs

// Constantes do Tabuleiro
#define TAM 10 // Tamanho do tabuleiro principal (10x10)
#define AGUA 0
#define OCUPADO 3 // Valor para navio
#define MARCA_HABILIDADE 5 // Valor para área de efeito da habilidade

// Constantes das Habilidades
#define HABILIDADE_LIN 3 // Tamanho (linhas) da matriz de habilidade
#define HABILIDADE_COL 5 // Tamanho (colunas) da matriz de habilidade
#define AFETADO 1 // Valor '1' na matriz de habilidade
#define NAO_AFETADO 0 // Valor '0' na matriz de habilidade

/**
 * @brief Verifica se um navio pode ser posicionado nas coordenadas fornecidas.
 * @param tabuleiro O tabuleiro do jogo.
 * @param linha Array com as coordenadas da linha.
 * @param coluna Array com as coordenadas da coluna.
 * @return int 1 (verdadeiro) se puder, 0 (falso) caso contrário.
 */
int pode_posicionar(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    // Itera sobre cada parte do navio (tamanho 3)
    for (int i = 0; i < 3; i++) {
        // 1. Verifica limites do tabuleiro
        if (linha[i] < 0 || linha[i] >= TAM || coluna[i] < 0 || coluna[i] >= TAM)
            return 0; // Fora dos limites
        // 2. Verifica sobreposição
        if (tabuleiro[linha[i]][coluna[i]] != AGUA)
            return 0; // Posição já ocupada
    }
    return 1; // Posição válida
}

/**
 * @brief Posiciona o navio no tabuleiro.
 * @param tabuleiro O tabuleiro do jogo.
 * @param linha Array com as coordenadas da linha.
 * @param coluna Array com as coordenadas da coluna.
 */
void posicionar_navio(int tabuleiro[TAM][TAM], int linha[], int coluna[]) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha[i]][coluna[i]] = OCUPADO;
    }
}

/**
 * @brief Exibe o tabuleiro completo no console.
 * @param tabuleiro O tabuleiro do jogo.
 */
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   A B C D E F G H I J\n"); // Cabeçalho de colunas
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i); // Cabeçalho de linhas (usei 'i' 0-9)
        for (int j = 0; j < TAM; j++) {
            // Imprime o valor da célula (0, 3 ou 5)
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Inicializa uma matriz de habilidade com 0s (NAO_AFETADO).
 * @param matriz A matriz de habilidade a ser inicializada.
 */
void inicializar_matriz_hab(int matriz[HABILIDADE_LIN][HABILIDADE_COL]) {
    for (int i = 0; i < HABILIDADE_LIN; i++) {
        for (int j = 0; j < HABILIDADE_COL; j++) {
            matriz[i][j] = NAO_AFETADO;
        }
    }
}

/**
 * @brief Cria dinamicamente o padrão de Cone.
 * A lógica preenche com '1' baseado na distância da coluna central,
 * aumentando a largura a cada linha.
 * @param matriz A matriz de habilidade 3x5 a ser preenchida.
 */
void criar_cone(int matriz[HABILIDADE_LIN][HABILIDADE_COL]) {
    inicializar_matriz_hab(matriz);
    int centro_col = HABILIDADE_COL / 2; // Coluna central (2)

    // Loop aninhado obrigatório para gerar o padrão
    for (int i = 0; i < HABILIDADE_LIN; i++) {
        for (int j = 0; j < HABILIDADE_COL; j++) {
            // Condicional: (j >= centro - i) E (j <= centro + i)
            // i=0 -> j=2 (1 ponto)
            // i=1 -> j=1,2,3 (3 pontos)
            // i=2 -> j=0,1,2,3,4 (5 pontos)
            if (j >= (centro_col - i) && j <= (centro_col + i)) {
                matriz[i][j] = AFETADO;
            }
        }
    }
}

/**
 * @brief Cria dinamicamente o padrão de Cruz.
 * A lógica preenche com '1' se a célula está na linha
 * central OU na coluna central.
 * @param matriz A matriz de habilidade 3x5 a ser preenchida.
 */
void criar_cruz(int matriz[HABILIDADE_LIN][HABILIDADE_COL]) {
    inicializar_matriz_hab(matriz);
    int centro_lin = HABILIDADE_LIN / 2; // Linha central (1)
    int centro_col = HABILIDADE_COL / 2; // Coluna central (2)

    for (int i = 0; i < HABILIDADE_LIN; i++) {
        for (int j = 0; j < HABILIDADE_COL; j++) {
            // Condicional: Está na linha central OU na coluna central
            if (i == centro_lin || j == centro_col) {
                matriz[i][j] = AFETADO;
            }
        }
    }
}

/**
 * @brief Cria dinamicamente o padrão de Octaedro (Losango).
 * A lógica usa a "Distância de Manhattan" do centro.
 * (dist_linha + dist_coluna) <= raio
 * @param matriz A matriz de habilidade 3x5 a ser preenchida.
 */
void criar_octaedro(int matriz[HABILIDADE_LIN][HABILIDADE_COL]) {
    inicializar_matriz_hab(matriz);
    int centro_lin = HABILIDADE_LIN / 2; // 1
    int centro_col = HABILIDADE_COL / 2; // 2
    int raio = centro_lin; // Raio do losango (1)

    for (int i = 0; i < HABILIDADE_LIN; i++) {
        for (int j = 0; j < HABILIDADE_COL; j++) {
            // Distância da linha atual até a linha central
            int dist_i = abs(i - centro_lin);
            // Distância da coluna atual até a coluna central
            int dist_j = abs(j - centro_col);

            // Condicional: Se a soma das distâncias for <= ao raio
            if (dist_i + dist_j <= raio) {
                matriz[i][j] = AFETADO;
            }
        }
    }
}

/**
 * @brief Sobrepõe a matriz de habilidade no tabuleiro principal.
 * @param tabuleiro O tabuleiro 10x10.
 * @param habilidade A matriz de habilidade 3x5 preenchida.
 * @param origem_l A linha no tabuleiro onde a habilidade se origina.
 * @param origem_c A coluna no tabuleiro onde a habilidade se origina.
 */
void sobrepor_habilidade(int tabuleiro[TAM][TAM],
                           int habilidade[HABILIDADE_LIN][HABILIDADE_COL],
                           int origem_l, int origem_c) {
    
    // Ponto central da matriz de habilidade (1, 2)
    int centro_lin_hab = HABILIDADE_LIN / 2;
    int centro_col_hab = HABILIDADE_COL / 2;

    // Percorre a matriz de habilidade 3x5
    for (int i = 0; i < HABILIDADE_LIN; i++) {
        for (int j = 0; j < HABILIDADE_COL; j++) {
            
            // Só aplica a lógica se for um ponto 'AFETADO' (1)
            if (habilidade[i][j] == AFETADO) {
                
                // Calcula a posição correspondente no tabuleiro principal
                // (Origem + (posição atual - centro da habilidade))
                int tab_l = origem_l + (i - centro_lin_hab);
                int tab_c = origem_c + (j - centro_col_hab);

                // Validação de limites (simplificada):
                // Verifica se a coordenada calculada está DENTRO do tabuleiro 10x10
                if (tab_l >= 0 && tab_l < TAM && tab_c >= 0 && tab_c < TAM) {
                    // Marca o tabuleiro com '5', sobrepondo água (0) ou navio (3)
                    tabuleiro[tab_l][tab_c] = MARCA_HABILIDADE;
                }
            }
        }
    }
}


/*
 * ==========================================
 * FUNÇÃO PRINCIPAL
 * ==========================================
 */
int main() {
    int tabuleiro[TAM][TAM];

    // 1. Inicializa o tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posiciona os 4 navios (do Nível Aventureiro)
    // Navio vertical
    int l1[] = {1, 2, 3}, c1[] = {1, 1, 1};
    if (pode_posicionar(tabuleiro, l1, c1))
        posicionar_navio(tabuleiro, l1, c1);

    // Navio horizontal
    int l2[] = {5, 5, 5}, c2[] = {4, 5, 6};
    if (pode_posicionar(tabuleiro, l2, c2))
        posicionar_navio(tabuleiro, l2, c2);

    // Navio diagonal principal
    int l3[] = {7, 8, 9}, c3[] = {7, 8, 9};
    if (pode_posicionar(tabuleiro, l3, c3))
        posicionar_navio(tabuleiro, l3, c3);

    // Navio diagonal secundária
    int l4[] = {0, 1, 2}, c4[] = {9, 8, 7};
    if (pode_posicionar(tabuleiro, l4, c4))
        posicionar_navio(tabuleiro, l4, c4);

    // 3. Cria as matrizes de habilidade
    int mat_cone[HABILIDADE_LIN][HABILIDADE_COL];
    int mat_cruz[HABILIDADE_LIN][HABILIDADE_COL];
    int mat_octaedro[HABILIDADE_LIN][HABILIDADE_COL];

    criar_cone(mat_cone);
    criar_cruz(mat_cruz);
    criar_octaedro(mat_octaedro);

    // 4. Sobrepõe as habilidades no tabuleiro (posições definidas no código)
    
    // Posiciona um cone centrado em (2, 3)
    sobrepor_habilidade(tabuleiro, mat_cone, 2, 3);

    // Posiciona uma cruz centrada em (5, 6) -> vai atingir o navio horizontal
    sobrepor_habilidade(tabuleiro, mat_cruz, 5, 6);

    // Posiciona um octaedro centrado em (8, 8) -> vai atingir o navio diagonal
    sobrepor_habilidade(tabuleiro, mat_octaedro, 8, 8);

    // 5. Exibe o tabuleiro final
    printf("Tabuleiro Final com Habilidades (0=Agua, 3=Navio, 5=Efeito)\n");
    exibir_tabuleiro(tabuleiro);

    return 0;
}