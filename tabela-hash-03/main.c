#include "tabelaHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  struct aluno *aluno = (struct aluno *)malloc(sizeof(struct aluno));
  int escolha, matricula;

  Hash *ha = criaHash(47);

  do {
    printf("\nMenu:\n");
    printf("1. Matricular aluno\n");
    printf("2. Cancelar matricula\n");
    printf("3. Pesquisar aluno\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      // printf("\nMatricula do aluno: ");
      // scanf("%d", &(aluno->matricula));
      // printf("Nome do aluno: ");
      // scanf("%s", aluno->nome);
      // matricular_aluno_teste(ha, aluno);
      // printf("Aluno matriculado com sucesso!\n");
      struct aluno aluno = { 123, "Joao", 8.5, 9.0, 7.5};
      for (int i = 0; i < 10; i++) {
        matricular_aluno(ha, aluno);
      }

      // Test Case 2: Insert 10 students with the same name
      struct aluno aluno2 = { 321, "Maria", 7.2, 8.0, 6.5};
      for (int i = 0; i < 10; i++) {
        matricular_aluno(ha, aluno2);
      }

      // Test Case 3: Insert 5 students with the same matricula, and 5 students with the same name
      struct aluno aluno3 = { 456, "Mario", 6.8, 7.0, 8.2};
      for (int i = 0; i < 5; i++) {
        matricular_aluno(ha, aluno3);
        matricular_aluno(ha, aluno2);
      }
      break;

    case 2:
      printf("\nMatricula do aluno: ");
      scanf("%d", &matricula);
      int res = cancelar_matricula(ha, matricula);

      if (res == 1) {
        printf("Matricula: %d cancelada com sucesso.", matricula);
      }
      break;

    case 3:
      printf("\nMatricula do aluno: ");
      scanf("%d", &matricula);
      struct aluno alunoBuscado;

      int resultado = buscar_por_matricula(ha, matricula, &alunoBuscado);
      if (resultado != 0) {
        printf("Aluno encontrado:\n");
        printf("Matricula: %d\n", alunoBuscado.matricula);
        printf("Nome: %s\n", alunoBuscado.nome);
      } else {
        printf("Nao foi encontrado nenhum aluno com a matricula '%d'",
               matricula);
      }
      break;

    default:
      break;
    }
  } while (escolha >= 1 && escolha <= 3);
  return 0;
}
