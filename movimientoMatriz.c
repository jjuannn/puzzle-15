#include <stdio.h>

void showMatrix(int matrix[4][4]);
void findEmptySpace(int M[4][4],int *f, int *c);
void checkMovements(int M[4][4],int f, int c, char tecla);

int main() {

    int fila = -1;
    int col = -1;
    char tecla = 'a';

    int M[4][4] = { 
        {6, 0 ,12, 14}, 
        {9, 1, 13, 8}, 
        {15, 10, 4, 2}, 
        {11, 5, 7, 3}
    };

    //printf("%i", M[-1][-1]);

    printf("fila = %i, col = %i\n", fila, col);
    showMatrix(M);
    printf("\n");
    findEmptySpace(M, &fila, &col);
    printf("El 0 esta en M[%d][%d]\n", fila, col);
    printf("Se presiono la tecla %c\n", tecla);
    checkMovements(M, fila, col, tecla);
    return 0;
}

void checkMovements(int M[4][4],int f, int c, char tecla){  
        switch(tecla) {
            case 'w': {
                if((f-1) >= 0){
                    printf("Arriba del cero esta el M[%i][%i] = %i\n", f,c, M[(f-1)][c]);
                } else {
                    printf("No se puede mover hacia arriba amigo'");
                }
            };
                break;
            case 's': {
                if((f+1) < 4){
                    printf("Abajo del cero esta el M[%i][%i] = %i\n", f,c, M[(f+1)][c]);
                } else {
                    printf("No se puede mover hacia abajo amigo'");
                }
            };
                break;
            case 'a': {
                if((c-1) >= 0){
                    printf("A la izquierda del cero esta el M[%i][%i] = %i\n", f,c, M[f][(c-1)]);
                } else {
                    printf("No se puede mover hacia la izquierda amigo'");
                }
            };
                break;
            case 'd': {
                if((c-1) < 4){
                    printf("A la derecha del cero esta el M[%i][%i] = %i\n", f,c, M[f][(c+1)]);
                } else {
                    printf("No se puede mover hacia la derecha amigo'");
                }
            };
                break;
            //default:;
        }
}

void findEmptySpace(int M[4][4], int *f, int *c) {
    int i, j;
    for (i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(M[i][j] == 0){
                *f = i;
                *c = j;
            }
        }
    }
}

void showMatrix(int matrix[4][4]){
    int f,c;
    printf("[");
    for (f = 0; f < 4; f++) {
        for (c = 0; c < 4 ; c++) {
            if(f==3 && c==3){
                printf("%i]", matrix[f][c]);
            } else {
                printf("%i,", matrix[f][c]);
            }
        }
        printf("\n");
    }
}

