#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void showMatrix(int matrix[4][4]);
void findEmptySpace(int M[4][4],int *f, int *c);
void checkMovements(int M[4][4],int f, int c, char tecla);

int main() {

    int fila = -1;
    int col = -1;

    int solution[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,0}
    };

    int M[4][4] = { 
        {6, 0 ,12, 14}, 
        {9, 1, 13, 8}, 
        {15, 10, 4, 2}, 
        {11, 5, 7, 3}
    };

   /*
    {6 , 0 , 12 , 14 }, 
    {9 , 1 , 13 , 8  }, 
    {15, 10, 4  , 2  }, 
    {11, 5 , 7  , 3  }

    s -> M[f+1][c]
    w -> M[f-1][c]
    d -> M[f][c+1]
    a -> M[f][c-1]
   */

    showMatrix(M);
    // printf("fila = %i, col = %i\n", fila, col);
    while(1){
    printf("\n");
    findEmptySpace(M, &fila, &col);
    // printf("El 0 esta en M[%d][%d]\n", fila, col);

    // printf("Press any key...\n");
    int tecla = getch();

    printf("Se presiono la tecla %c\n", tecla);
    checkMovements(M, fila, col, tecla);

    showMatrix(M);
    printf("\n \n ");
    }
    return 0;
}

void checkMovements(int M[4][4],int f, int c, char tecla){  
        switch(tolower(tecla)) {
            case 's': {
                if((f-1) >= 0 && (f-1) < 4){
                    int aux = M[(f-1)][c];
                    M[(f-1)][c] = M[f][c];
                    M[f][c] = aux;
                    printf("Arriba del cero esta el M[%i][%i] = %i\n", f - 1,c, M[(f-1)][c]);

                } else {
                    printf("No se puede mover hacia arriba amigo \n");
                }
            };
                break;
            case 'w': {
                if((f+1) >= 0 && (f+1) < 4){
                    int aux = M[(f+1)][c];
                    M[(f+1)][c] = M[f][c];
                    M[f][c] = aux;
                    printf("Abajo del cero esta el M[%i][%i] = %i\n", f + 1,c, M[(f+1)][c]);
                } else {
                    printf("No se puede mover hacia abajo amigo \n");
                }
            };
                break;
            case 'a': {
                if((c+1) >= 0 && (c+1) < 4){
                    int aux = M[f][(c + 1)];
                    M[f][(c + 1)] = M[f][c];
                    M[f][c] = aux;
                    printf("A la izquierda del cero esta el M[%i][%i] = %i\n", f,c - 1, M[f][(c-1)]);
                } else {
                    printf("No se puede mover hacia la izquierda amigo \n");
                }
            };
                break;
            case 'd': {
                if((c-1) >= 0 && (c-1) < 4){
                    int aux = M[f][(c - 1)];
                    M[f][(c - 1)] = M[f][c];
                    M[f][c] = aux;
                    printf("A la derecha del cero esta el M[%i][%i] = %i\n", f, c + 1, M[f][(c+1)]);
                } else {
                    printf("No se puede mover hacia la derecha amigo \n");
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
    for (f = 0; f < 4; f++) {
        for (c = 0; c < 4 ; c++) {
            if(matrix[f][c] == 0){
                printf("%c,", ' ');  
            } else {
                printf("%i,", matrix[f][c]);  
            }
        }
        printf("\n");
    }
}

