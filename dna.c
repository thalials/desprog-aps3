#include <stdio.h>

#include "dna.h"

void load_string(FILE *file, int *p, char *s, int t){
    if (fscanf(file, "%d", p) != 1){
        fprintf(stderr, "erro ao ler string do teste %d\n", t);
    }

    char c;
    do{
        c = getc(file);
    } while (c != '\n');

    fgets(s, *p + 1, file);
}

// recursiva
int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]){
    
    // menor caso
    if (n == 0 || m == 0) {
        // n = or m = 0 
        length[n][0] = 0;
        length[0][m] = 0;
        return 0;
    }

    // chamada recursiva
    mlcs_w(a, n-1, b, m, length);
    mlcs_w(a, n, b, m-1, length);

    // passo
    if (a[n - 1] == b[m - 1]) {
        length[n][m] = length[n - 1][m - 1] + 1;
    }

    else {
        int max;
        if (length[n - 1][m] < length[n][m - 1]) {
            max = length[n][m - 1];
        }
        else {
            max = length[n - 1][m];
        }

        // atualiza o valor de length[n][m]
        length[n][m] = max;
    }

    return length[n][m];
}

// funcao de embrulho => chama mlcs_w
int mlcs(char a[], int n, char b[], int m) {
    // inicializa a matriz;
    int length[MAX_SIZE + 1][MAX_SIZE + 1];

    // chamada da funcao recusiva
    mlcs_w(a, n, b, m, length);

    return length[n][m];
}

int dlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE + 1][MAX_SIZE + 1];

    // preenche a matriz
    return 2;
}
