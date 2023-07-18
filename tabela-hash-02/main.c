#include "tabelaHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  struct aluno *aluno = (struct aluno *)malloc(sizeof(struct aluno));
  int escolha, matricula;
  char nomeBusca[30];

  Hash *ha = criaHash(1497);

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
      // int resMatricula = matricular_aluno(ha, *aluno);
      // if(resMatricula == 1) {
      //   printf("\nAluno matriculado com sucesso!\n");
      // } else {
      //   printf("\nOcorreu um erro ao matricular!\n");
      // }

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

      struct aluno aluno4 = { 100, "Douglas", 6.8, 7.0, 8.2};
      matricular_aluno(ha, aluno4);

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