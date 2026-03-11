#include <stdio.h>

#define VAZIO ' '

char tabuleiro[3][3];
char jogador_atual;

void inicializar() {
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      tabuleiro[i][j] = VAZIO;
  jogador_atual = 'X';
}

void exibir_tabuleiro() {
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
  printf("\n");
}

int verificar_vitoria() {
  int i;
  for (i = 0; i < 3; i++) {
      if (tabuleiro[i][0] == jogador_atual &&
          tabuleiro[i][1] == jogador_atual &&
          tabuleiro[i][2] == jogador_atual)
        return 1;

      if (tabuleiro[0][i] == jogador_atual &&
          tabuleiro[1][i] == jogador_atual &&
          tabuleiro[2][i] == jogador_atual)
        return 1;
  }

  if (tabuleiro[0][0] == jogador_atual &&
    tabuleiro[1][1] == jogador_atual &&
    tabuleiro[2][2] == jogador_atual)
    return 1;

  if (tabuleiro[0][2] == jogador_atual &&
    tabuleiro[1][1] == jogador_atual &&
    tabuleiro[2][0] == jogador_atual)
    return 1;

  return 0;
}

int contar_vazios() {
  int i, j, cont = 0;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      if (tabuleiro[i][j] == VAZIO)
          cont++;
  return cont;
}

int main() {
    int linha, coluna;
    int vencedor = 0;

    inicializar();

    printf("=== JOGO DA VELHA ===\n");
    printf("Linhas e colunas: 0, 1 ou 2\n");

  while (contar_vazios() > 0 && !vencedor) {
      exibir_tabuleiro();

      do {
        printf("Jogador %c - Digite linha e coluna (ex: 1 2): ", jogador_atual);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Posicao invalida! Use valores entre 0 e 2.\n");
            continue;
        }

        if (tabuleiro[linha][coluna] != VAZIO) {
            printf("Posicao ocupada! Escolha outra.\n");
            continue;
        }

        break;
      } while (1);

      tabuleiro[linha][coluna] = jogador_atual;

      if (verificar_vitoria()) {
          vencedor = 1;
        exibir_tabuleiro();
          printf("O jogador %c venceu!\n", jogador_atual);
      } else {
        jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
      }
  }

  if (!vencedor) {
      exibir_tabuleiro();
      printf("O jogo terminou em empate.\n");
  }

    return 0;
}
