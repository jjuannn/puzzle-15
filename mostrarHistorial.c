#include <stdio.h>

void mostrarMatriz(int matriz[][3], int f, int c) {
    int i, j;
    //movimientos
//printf("===Puntos===|============|=============|\n");
printf("===Puntos====|=Movimientos=|===Apuesta===|\n");
    for (int i = 0; i < f; i++) {
        
        for (int j = 0; j < c; j++) {
            printf("%7d      |", matriz[i][j]);  
        }
        printf("\n");
    }
//printf("===Puntos====|=Movimientos=|===Apuesta===|\n");
printf("==========================================\n");
}

int main() {
    int matriz[3][3] = { {1, 0, 45},
                         {4, 15, 6},
                         {7, 8, 9} };

    mostrarMatriz(matriz, 3, 3);

    return 0;
}