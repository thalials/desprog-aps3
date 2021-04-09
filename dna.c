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
        // n = 0 ou m = 0 
        length[n][m] = 0;
        return 0;
    }
    // analisa de o valor o valor é invalido 
    if (length[n][m] != -1){
        return length[n][m];
    }

    // passo
    if (a[n - 1] == b[m - 1]) {
        length[n][m] = mlcs_w(a, n - 1, b, m - 1, length) + 1;
    }

    else {
        int max;
        if(mlcs_w(a, n - 1, b, m, length) > mlcs_w(a, n, b, m - 1, length)){            
            max = mlcs_w(a, n - 1, b, m, length);
        }
        else {
            max = mlcs_w(a, n, b, m - 1, length);
        }

        length[n][m] = max;
    }

    return length[n][m];
}

// funcao de embrulho => chama mlcs_w
int mlcs(char a[], int n, char b[], int m) {
    // inicializa a matriz;
    int length[MAX_SIZE + 1][MAX_SIZE + 1];

    // preenche os valores da matriz com -1
    for(int linha = 0; linha <= n; linha++){
        for  (int coluna = 0; coluna <= m; coluna++){
            length[linha][coluna] = -1;
        }
    }

    mlcs_w(a, n, b, m, length);
    return length[n][m];
}

int dlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE + 1][MAX_SIZE + 1];

    for(int linha = 0; linha < n; linha++){
        for(int coluna = 0; coluna < m; coluna++){
            if (linha == 0 || coluna == 0){
                // linha = 0 ou coluna = 0 
                length[linha][coluna] = 0;
            }

            if(a[linha-1] == b[coluna-1]){
                length[linha][coluna] = length[linha-1][coluna-1];

            }
            else{
                if(length[linha-1][coluna] > length[linha][coluna-1]){
                    length[linha][coluna] = length[linha-1][coluna];
                }
                else{
                    length[linha][coluna] = length[linha][coluna-1];
                }
            }
        }
    }
    return length[n][m];
    
}
