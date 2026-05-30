#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Matriz que representa o tabuleiro 10x10
    int tabuleiro[10][10];

    // Vetores que representam os navios
    // O valor 3 indica uma posição ocupada por navio
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Vetores que representam os navios diagonais
    int navioDiagonalPrincipal[3] = {3, 3, 3};
    int navioDiagonalSecundaria[3] = {3, 3, 3};

    // Variáveis de controle dos loops
    int linha, coluna;

    // Coordenadas iniciais do navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 1;

    // Coordenadas iniciais do navio vertical
    int linhaVertical = 5;
    int colunaVertical = 7;

    // Coordenadas iniciais do navio diagonal principal
    int LinhaDiagonalPrincipal = 0;
    int colunaDiagonalPrincipal = 5;

    // Coordenadas iniciais do navio diagonal secundária
    int linhaDiagonalSecundaria = 7;
    int colunaDiagonalSecundaria = 2;

    // Variável utilizada para validar o posicionamento
    int posicionamentoValido = 1;

    // Inicializa todo o tabuleiro com água (valor 0)
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Verifica se o navio horizontal cabe dentro do tabuleiro
    if (colunaHorizontal + 3 > 10) {
        posicionamentoValido = 0;
    }

    // Verifica se o navio vertical cabe dentro do tabuleiro
    if (linhaVertical + 3 > 10) {
        posicionamentoValido = 0;
    }

    // Verifica se o navio diagonal principal cabe dentro do tabuleiro
    if (LinhaDiagonalPrincipal + 3 > 10 ||
    colunaDiagonalPrincipal + 3 > 10) {
        posicionamentoValido = 0;
    }

    // Verifica se o navio diagonal secundária cabe dentro do tabuleiro
    if (linhaDiagonalSecundaria - 2 < 0 ||
    colunaDiagonalSecundaria + 3 > 10) {
        posicionamentoValido = 0;
    }

    // Posiciona o navio horizontal no tabuleiro
    if (posicionamentoValido) {
        for (coluna = 0; coluna < 3; coluna++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + coluna] =
            navioHorizontal[coluna];
        }
    }

    // Verifica se existe sobreposição antes de posicionar o navio vertical
    if (posicionamentoValido) {
        for (linha = 0; linha < 3; linha++) {
            if (tabuleiro[linhaVertical + linha][colunaVertical] == 3) {
                posicionamentoValido = 0;
            }
        }
    }

    // Posiciona o navio vertical caso não exista sobreposição
    if (posicionamentoValido) {
        for (linha = 0; linha < 3; linha++) {
            tabuleiro[linhaVertical + linha][colunaVertical] = 
            navioVertical[linha];
        }
    }

    // Verifica sobreposição do navio diagonal principal
    if (posicionamentoValido) {
        for (linha = 0; linha < 3; linha++) {
            if (tabuleiro[LinhaDiagonalPrincipal + linha]
                         [colunaDiagonalPrincipal + linha] == 3) {
                            posicionamentoValido = 0;
            }
        }
    }

    // Posiciona o navio diagonal principal
    if (posicionamentoValido) {
        for (linha = 0; linha < 3; linha++) {
            tabuleiro[LinhaDiagonalPrincipal + linha]
                     [colunaDiagonalPrincipal + linha] =
                navioDiagonalPrincipal[linha];
        }
    }

    // Verifica sobreposição do navio diagonal secundária
    if (posicionamentoValido) {
        for (linha = 0; linha < 3; linha++) {
        if (tabuleiro[linhaDiagonalSecundaria - linha]
                     [colunaDiagonalSecundaria + linha] == 3) {
                     posicionamentoValido = 0;
            }  
        }
    }

    // Posiciona o navio diagonal secundária
    if (posicionamentoValido) {
        for (linha = 0; linha < 3; linha++) {
            tabuleiro[linhaDiagonalSecundaria - linha]
                     [colunaDiagonalSecundaria + linha] =
                navioDiagonalSecundaria[linha];
        }
    }

    // Exibe as coordenadas do navio horizontal
    printf("Coordenadas do Navio Horizontal:\n");
    for (coluna = 0; coluna < 3; coluna++) {
        printf("(%d, %d)\n",
            linhaHorizontal,
            colunaHorizontal + coluna);
    }

    // Exibe coordenadas do navio vertical
    printf("\nCoordenadas do Navio Vertical:\n");
    for (linha = 0; linha < 3; linha++) {
        printf("(%d, %d)\n",
            linhaVertical + linha,
            colunaVertical);
    }

    // Exibe coordenadas do navio diagonal principal
    printf("\nCoordenadas do Navio Diagonal Principal:\n");
    for (linha = 0; linha < 3; linha++) {
        printf("(%d, %d)\n",
            LinhaDiagonalPrincipal + linha,
            colunaDiagonalPrincipal + linha);
    }

    // Exibe coordenadas do navio diagonal secundária
    printf("\nCoordenadas do Navio Diagonal Secundária:\n");
    for (linha = 0; linha < 3; linha++) {
    printf("(%d, %d)\n",
            linhaDiagonalSecundaria - linha,
            colunaDiagonalSecundaria + linha);
    }

    // Exibe mensagem caso haja erro no posicionamento
    if (!posicionamentoValido) {
        printf("\nErro: os navios possuem coordenadas invalidas ou estao sobrepostos.\n");
        return 1;
    }

    // Exibe o tabuleiro completo
    printf("\nTabuleiro Batalha Naval:\n\n");

    // Exibe  o cabeçalho das colunas
    printf ("  ");
    for(coluna = 0; coluna < 10; coluna++) {
        printf("%c ", 'A' + coluna);
        }
        printf("\n");

    // Exibe as linhas numeradas e o conteúdo do tabuleiro
    for (linha = 0; linha < 10; linha++) {

        // Exibe o número da linha
        printf("%2d ", linha + 1);

        // Exibe os valores da linha
        for (coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
