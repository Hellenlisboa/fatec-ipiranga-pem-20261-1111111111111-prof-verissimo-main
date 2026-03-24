#include <stdio.h>

// Define o tamanho do tabuleiro (8x8)
#define TAM 8

// Função responsável por inicializar o tabuleiro com as peças
void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {

    // Matriz auxiliar com a posição inicial das peças
    char inicial[TAM][TAM] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, // peças pretas
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, // peões pretos
        {'.', '.', '.', '.', '.', '.', '.', '.'}, // casas vazias
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, // peões brancos
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}  // peças brancas
    };

    // Copia os valores da matriz "inicial" para o tabuleiro principal
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = inicial[i][j];
        }
    }
}

// Função que imprime o tabuleiro na tela
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {

    // Percorre todas as linhas
    for (int i = 0; i < TAM; i++) {

        // Percorre todas as colunas
        for (int j = 0; j < TAM; j++) {

            // Imprime cada posição seguida de espaço
            printf("%c ", tabuleiro[i][j]);
        }

        // Quebra de linha ao final de cada linha do tabuleiro
        printf("\n");
    }
}

// Função para exibir uma mensagem e o estado atual do tabuleiro
void mostrarEstado(char mensagem[], char tabuleiro[TAM][TAM]) {

    // Imprime a mensagem da jogada
    printf("\n%s\n", mensagem);

    // Mostra o tabuleiro atualizado
    imprimirTabuleiro(tabuleiro);
}

// Função que move uma peça de uma posição para outra
void moverPeca(char tabuleiro[TAM][TAM], int ox, int oy, int dx, int dy) {

    // Move a peça da origem para o destino
    tabuleiro[dx][dy] = tabuleiro[ox][oy];

    // Deixa a posição de origem vazia
    tabuleiro[ox][oy] = '.';
}

// Função principal do programa
int main() {

    // Declaração do tabuleiro
    char tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com as peças
    inicializarTabuleiro(tabuleiro);

    // Mostra o estado inicial
    printf("Tabuleiro inicial:\n");
    imprimirTabuleiro(tabuleiro);

    // Jogada 1: Peão branco de e2 para e4
    moverPeca(tabuleiro, 6, 4, 4, 4);
    mostrarEstado("Após jogada #1 das Brancas (Peão do Rei e2 para e4):", tabuleiro);

    // Jogada 2: Bispo branco de f1 para c4
    moverPeca(tabuleiro, 7, 5, 4, 2);
    mostrarEstado("Após jogada #2 das Brancas (Bispo do Rei f1 para c4):", tabuleiro);

    // Jogada 2 (pretas): Cavalo de b8 para c6
    moverPeca(tabuleiro, 0, 1, 2, 2);
    mostrarEstado("Após jogada #2 das Pretas (Cavalo da Dama b8 para c6):", tabuleiro);

    // Jogada 3: Dama branca de d1 para h5
    moverPeca(tabuleiro, 7, 3, 3, 7);
    mostrarEstado("Após jogada #3 das Brancas (Dama d1 para h5):", tabuleiro);

    // Jogada 3 (pretas): Cavalo de g8 para f6
    moverPeca(tabuleiro, 0, 6, 2, 5);
    mostrarEstado("Após jogada #3 das Pretas (Cavalo do Rei g8 para f6):", tabuleiro);

    // Jogada 4: Dama branca captura em f7 (xeque-mate)
    moverPeca(tabuleiro, 3, 7, 1, 5);
    mostrarEstado("Após jogada #4 das Brancas (Dama h5 captura Peão f7 - Xeque Mate):", tabuleiro);

    // Finaliza o programa
    return 0;
}