
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxAlunos 10
#define numNotas 3
#define tamNome 100

//Calcular a media de cada estudante
void calcular_medias(double notas[maxAlunos][numNotas],
                     double *medias, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        double soma = 0.0;

        for (int j = 0; j < numNotas; j++) {
            soma += notas[i][j];
        }

        medias[i] = soma / 3.0;
    }
}

int main(void) {
    int quantidade;
    double notas[maxAlunos][numNotas];
    char nomes[maxAlunos][tamNome];

    //Perguntar qual o número de alunos
    do {
        printf("Quantidade de estudantes (1 a 10): ");

        if (scanf("%d", &quantidade) != 1) {
            printf("Entrada invalida!\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }

            quantidade = 0;
        } else {
            getchar();
        }

        if (quantidade < 1 || quantidade > 10) {
            printf("Digite uma quantidade entre 1 e 10.\n");
        }

    } while (quantidade < 1 || quantidade > 10);

    //Ler os nomes e as notas
    for (int i = 0; i < quantidade; i++) {
        printf("\nNome do estudante %d: ", i + 1);
        //Coloca os nomes no vetor nomes
        fgets(nomes[i], tamNome, stdin);

        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        for (int j = 0; j < numNotas; j++) {
            int resultado;

            do {
                printf("Nota %d de %s (0 a 10): ",
                       j + 1, nomes[i]);

                //Coloca as notas para cada nome
                resultado = scanf("%lf", &notas[i][j]);

                if (resultado != 1) {
                    printf("Entrada invalida! Digite um numero.\n");

                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {
                    }

                    notas[i][j] = -1.0;
                } else if (notas[i][j] < 0.0 ||
                           notas[i][j] > 10.0) {
                    printf("Nota invalida! Digite de 0 a 10.\n");
                }

            } while (notas[i][j] < 0.0 ||
                     notas[i][j] > 10.0);

            //Descarta caracteres restantes na linha
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
        }
    }

    //Aloca dinamicamente o vetor das medias
    double *medias = malloc(quantidade * sizeof(double));

    if (medias == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    calcular_medias(notas, medias, quantidade);

    //Calcular a media geral e a maior media
    double soma_medias = 0.0;
    double maior_media = medias[0];

    for (int i = 0; i < quantidade; i++) {
        soma_medias += medias[i];

        if (medias[i] > maior_media) {
            maior_media = medias[i];
        }
    }

    double media_geral = soma_medias / quantidade;

    //Mostrar o mega boletim
    printf("\n================ BOLETIM ================\n");
    printf("%-20s %7s %7s %7s %8s %20s\n",
           "Nome", "N1", "N2", "N3", "Media", "Situacao");

    for (int i = 0; i < quantidade; i++) {
        printf("%-20s %7.2f %7.2f %7.2f %8.2f %20s\n",
               nomes[i],
               notas[i][0],
               notas[i][1],
               notas[i][2],
               medias[i],
               medias[i] >= 6.0
                   ? "Atingiu a meta"
                   : "Abaixo da meta");
    }

    printf("\nMedia geral da turma: %.2f\n", media_geral);
    printf("Maior media: %.2f\n", maior_media);
    printf("Estudante(s) com a maior media:\n");

    for (int i = 0; i < quantidade; i++) {
        if (medias[i] == maior_media) {
            printf("- %s\n", nomes[i]);
        }
    }

    free(medias);

    return 0;
}
