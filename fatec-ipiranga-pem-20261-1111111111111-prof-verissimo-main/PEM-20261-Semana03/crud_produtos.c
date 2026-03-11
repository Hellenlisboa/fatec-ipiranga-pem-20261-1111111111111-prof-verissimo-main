#include <stdio.h>

#define MAX 10
#define VAZIO 0

int idProduto[MAX];
int total = 0;

void exibir_menu() {
  printf("\n=== CADASTRO DE PRODUTOS ===\n");
  printf("1. Incluir produto\n");
  printf("2. Consultar produto\n");
  printf("3. Alterar produto\n");
  printf("4. Excluir produto\n");
  printf("5. Listar todos\n");
  printf("0. Sair\n");
    printf("Opcao: ");
}

void incluir() {
    if (total >= MAX) {
      printf("Cadastro cheio! Limite de %d produtos.\n", MAX);
      return;
    }
    int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);
  idProduto[total] = id;
  total++;
    printf("Produto %d cadastrado com sucesso!\n", id);
}

void consultar() {
    int id, i;
    printf("Digite o ID para consultar: ");
    scanf("%d", &id);

  for (i = 0; i < MAX; i++) {
      if (idProduto[i] == id) {
        printf("Produto %d encontrado na posicao %d.\n", id, i);
        return;
      }
  }
    printf("Produto nao encontrado.\n");
}

void alterar() {
  int id, novo_id, i;
  printf("Digite o ID do produto a alterar: ");
  scanf("%d", &id);

    for (i = 0; i < MAX; i++) {
      if (idProduto[i] == id) {
          printf("ID encontrado na posicao %d. Novo ID: ", i);
          scanf("%d", &novo_id);
        idProduto[i] = novo_id;
          printf("Produto alterado com sucesso!\n");
          return;
      }
    }
  printf("Produto nao encontrado.\n");
}

void excluir() {
    int id, i;
    printf("Digite o ID do produto a excluir: ");
    scanf("%d", &id);

  for (i = 0; i < MAX; i++) {
    if (idProduto[i] == id) {
        idProduto[i] = VAZIO;
        printf("Produto %d excluido com sucesso!\n", id);
        return;
    }
  }
    printf("Produto nao encontrado.\n");
}

void listar() {
  int i, encontrou = 0;
  printf("\n--- Lista de Produtos ---\n");
  for (i = 0; i < MAX; i++) {
      if (idProduto[i] != VAZIO) {
        printf("Posicao [%d]: ID = %d\n", i, idProduto[i]);
        encontrou = 1;
      }
  }
  if (!encontrou)
      printf("Nenhum produto cadastrado.\n");
}

int main() {
    int opcao, i;

  for (i = 0; i < MAX; i++)
    idProduto[i] = VAZIO;

    do {
      exibir_menu();
      scanf("%d", &opcao);

        switch (opcao) {
          case 1: incluir();   break;
          case 2: consultar(); break;
          case 3: alterar();   break;
          case 4: excluir();   break;
          case 5: listar();    break;
          case 0: printf("Encerrando...\n"); break;
          default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
