#include "tabelaHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  struct aluno *aluno = (struct aluno *)malloc(sizeof(struct aluno));
  int escolha, matricula;

  Hash *ha = criaHash(30);

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
      printf("\nMatricula do aluno: ");
      scanf("%d", &(aluno->matricula));
      printf("Nome do aluno: ");
      scanf("%s", aluno->nome);
      matricular_aluno(ha, *aluno);
      printf("Aluno matriculado com sucesso!\n");
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
