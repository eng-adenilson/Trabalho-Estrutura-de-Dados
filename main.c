#include <stdio.h>
#include <stdlib.h>

#define MAX_COORDENADAS 100 // Defina o número máximo de coordenadas que seu arquivo pode conter

int main() {
    FILE *arquivo;
    char nome_arquivo[] = "C:\\Users\\adeni\\OneDrive\\AppReadiness\\Documentos\\cordenadas.txt";
    float coordenadas[MAX_COORDENADAS][2]; // Matriz para armazenar as coordenadas
    int num_coordenadas = 0;

    // Abrindo o arquivo
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return 1;
    }

    // Lendo as coordenadas do arquivo
    while (fscanf(arquivo, "%f %f", &coordenadas[num_coordenadas][0], &coordenadas[num_coordenadas][1]) == 2) {
        num_coordenadas++;
    }

    // Fechando o arquivo
    fclose(arquivo);

    // Verificando se houve erro na leitura
    if (ferror(arquivo)) {
        printf("Erro na leitura do arquivo.\n");
        return 1;
    } else {
        printf("Leitura do arquivo concluída.\n");
    }

    // Imprimindo as coordenadas lidas
    printf("Coordenadas lidas do arquivo:\n");
    for (int i = 0; i < num_coordenadas; i++) {
        printf("(%.2f, %.2f)\n", coordenadas[i][0], coordenadas[i][1]);
    }

    // Cálculo do determinante
    int Det = 0;
    Det = Det + coordenadas[0][0] * coordenadas[1][1] * 1;
    Det = Det + coordenadas[0][1] * 1 * coordenadas[1][0];
    Det = Det + 1 * coordenadas[1][0] * coordenadas[0][1];
    Det = Det - coordenadas[1][0] * coordenadas[1][1] * 1;
    Det = Det - 1 * coordenadas[0][1] * coordenadas[0][0];
    Det = Det - 1 * coordenadas[1][1] * coordenadas[0][0];

    // Imprimindo o determinante
    printf("Det: %d.\n\n", Det);

    return 0;
}
