#include "tabelaHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  struct aluno *aluno = (struct aluno *)malloc(sizeof(struct aluno));
  int escolha, matricula;
  char nomeBusca[30];

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
      int resMatricula = matricular_aluno(ha, *aluno);
      if(resMatricula == 1) {
        printf("\nAluno matriculado com sucesso!\n");
      } else {
        printf("\nOcorreu um erro ao matricular!\n");
      }
      break;

    case 2:
      char nomeCancelar[30];
      printf("\nNome do aluno que deseja cancelar a Matrícula: ");
      scanf("%s", nomeCancelar);
      int res = cancelar_matricula(ha, nomeCancelar);

      if (res == 1) {
        printf("Matricula do aluno '%s' cancelada com sucesso.", nomeCancelar);
      }
      break;

    case 3:
      printf("\nNome do Aluno a ser buscado: ");
      scanf("%s", &nomeBusca);
      struct aluno alunoBuscado;

      int resultado = buscar_por_nome(ha, nomeBusca, &alunoBuscado);
      if (resultado != 0) {
        printf("Aluno encontrado:\n");
        printf("Matricula: %d\n", alunoBuscado.matricula);
        printf("Nome: %s\n", alunoBuscado.nome);
      } else {
        printf("\nNao foi encontrado nenhum aluno com o nome '%s'\n", nomeBusca);
      }
      break;

    default:
      break;
    }
  } while (escolha >= 1 && escolha <= 3);
  return 0;
}
