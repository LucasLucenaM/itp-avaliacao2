
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxAlunos 10
#define numNotas 3
#define tamNome 100

//Função que calcula a media de cada estudante
void calcular_medias(double notas[maxAlunos][numNotas],
                     double *medias, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        double soma = 0.0;

        for (int j = 0; j < numNotas; j++) {
            soma += notas[i][j];
        }

        medias[i] = soma / numNotas;
    }
}

int main(void) {
    int numAlunos;
    double notas[maxAlunos][numNotas];
    char nomes[maxAlunos][tamNome];

    //Perguntar qual o número de alunos
    do {

        printf("Quantidade de estudantes (1 a 10): ");
        scanf("%d", &numAlunos);

        if (numAlunos < 1 || numAlunos > 10) {
            printf("Digite uma quantidade entre 1 e 10.\n");
        }

        } while (numAlunos < 1 || numAlunos > 10);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
    }

    //Ler os nomes e as notas
    for (int i = 0; i < numAlunos; i++) {
        printf("\nNome do estudante %d: ", i + 1);

        fgets(nomes[i], tamNome, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        for (int j = 0; j < numNotas; j++) {
            do {
                printf("Nota %d de %s (0 a 10): ",
                       j + 1, nomes[i]);

                if (scanf("%lf", &notas[i][j]) != 1) {
                    printf("Entrada inválida! Digite um número.\n");

                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    notas[i][j] = -1.0;
                } else {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    if (notas[i][j] < 0.0 ||
                        notas[i][j] > 10.0) {
                        printf("Nota invalida! Digite de 0 a 10.\n");
                    }
                }

            } while (notas[i][j] < 0.0 ||
                     notas[i][j] > 10.0);
        }
    }

    //Alocar dinamicamente o vetor das medias
    double *medias = malloc(numAlunos * sizeof(double));

    if (medias == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    calcular_medias(notas, medias, numAlunos);

    //Calcular a média geral e mostrar a maior media
    double soma_medias = 0.0;
    double maior_media = medias[0];

    for (int i = 0; i < numAlunos; i++) {
        soma_medias += medias[i];

        if (medias[i] > maior_media) {
            maior_media = medias[i];
        }
    }

    double media_geral = soma_medias / numAlunos;

    //Mostrar o mega boletim
    printf("\n======================= BOLETIM =======================\n");
    printf("\n");

    printf("%-25s | %6s | %6s | %6s | %7s | %-15s\n",
           "Nome", "N1", "N2", "N3", "Média", "Situação");

    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < numAlunos; i++) {
        printf("%-25s | %6.2f | %6.2f | %6.2f | %6.2f | ",
               nomes[i],
               notas[i][0],
               notas[i][1],
               notas[i][2],
               medias[i]);

        if (medias[i] >= 6.0) {
            printf("%-15s\n", "Atingiu a meta");
        } else {
            printf("%-15s\n", "Abaixo da meta");
        }
    }

    printf("\nMedia geral da turma: %.2f\n", media_geral);
    printf("Maior media: %.2f\n", maior_media);
    printf("Estudante(s) com a maior media:\n");

    for (int i = 0; i < numAlunos; i++) {
        if (medias[i] == maior_media) {
            printf("-> %s\n", nomes[i]);
        }
    }

    free(medias);

    return 0;
}
