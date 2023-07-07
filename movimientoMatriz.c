#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define SEPARATOR() printf("\n");

void showMatrix(int matrix[4][4]);
void findEmptySpace(int M[4][4],int *f, int *c);
void checkMovements(int M[4][4],int f, int c, char tecla);
void keysScreen();
int isResolved(int table[4][4],int solution[4][4]);
int getPoints(int moves, int bet);

int main() {

    int fila = -1;
    int col = -1;
    char tecla = 'e';
    int moves = 0;
    int apuesta = 0;
    int score = 0;

    int solution[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,0}
    };

    int M[4][4] = { 
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,0,15}
    };

    printf("Ingrese su apuesta:\n> ");
    scanf("%i", &apuesta);
    while(apuesta < 1){
        printf("La apuesta debe ser mayor a 0\n> ");
        scanf("%i", &apuesta);
    }
    system("cls");
    showMatrix(M);
    SEPARATOR();
    keysScreen();
    SEPARATOR();

    while(!(isResolved(M, solution)) && tecla != 'q'){
        findEmptySpace(M, &fila, &col);
        printf("Ingrese Movimiento\n> ");
        tecla = tolower(getch());
        system("cls");
        if (tecla == 'a' || tecla == 's'|| tecla == 'w' || tecla == 'd') {
            moves++;
        }
        checkMovements(M, fila, col, tecla);
        showMatrix(M);
        SEPARATOR();
        keysScreen();
        SEPARATOR();
    }
    system("cls");

    score = getPoints(moves, apuesta);

    if(tecla != 'q'){
        printf("Resolviste el Puzzle!!!\n");
        printf("Movimientos Realizados: %i\n", moves);
        printf("Puntos Obtenidos: %i\n", score);
    } else {
       printf("Abandonaste...\n");
       printf("Movimientos Realizados: %i\n", moves);
       printf("Puntos Obtenidos: 0, sos horrible loco.\n");
    }

    return 0;
}

void keysScreen(){
    printf("W - Arriba\n");
    printf("S - Abajo\n");
    printf("A - Izquierda\n");
    printf("D - Derecha\n");
    printf("Q - Salir\n");
}

int getPoints(int moves, int apuesta){
    if (moves > (apuesta-10) &&  moves < apuesta){
        return 500;
    } else if(moves > apuesta && moves <= (apuesta + 10)){
        return 100;
    } else if (moves == apuesta){
        return 1000;
    } else{
        return 0;
    }
}

int isResolved(int M[4][4],int solution[4][4]){
    int f,c;
    for (f = 0; f < 4; f++) {
        for (c = 0; c < 4 ; c++) {
            if(M[f][c] != solution[f][c]){//Si encuentra un elemento distinto
                return 0;//no esta resuelta
            }
        }
    }
    return 1; //esta resuelta
}

void checkMovements(int M[4][4],int f, int c, char tecla){  
        switch(tecla) {
            case 's': {
                if((f-1) >= 0 && (f-1) < 4){
                    int aux = M[(f-1)][c];
                    M[(f-1)][c] = M[f][c];
                    M[f][c] = aux;
                    //printf("Arriba del cero esta el M[%i][%i] = %i\n", f - 1,c, M[(f-1)][c]);

                } else {
                    printf("No se puede mover hacia arriba amigo ");
                }
            };
                break;
            case 'w': {
                if((f+1) >= 0 && (f+1) < 4){
                    int aux = M[(f+1)][c];
                    M[(f+1)][c] = M[f][c];
                    M[f][c] = aux;
                    //printf("Abajo del cero esta el M[%i][%i] = %i\n", f + 1,c, M[(f+1)][c]);
                } else {
                    printf("No se puede mover hacia abajo amigo ");
                }
            };
                break;
            case 'a': {
                if((c+1) >= 0 && (c+1) < 4){
                    int aux = M[f][(c + 1)];
                    M[f][(c + 1)] = M[f][c];
                    M[f][c] = aux;
                    //printf("A la izquierda del cero esta el M[%i][%i] = %i\n", f,c - 1, M[f][(c-1)]);
                } else {
                    printf("No se puede mover hacia la izquierda amigo ");
                }
            };
                break;
            case 'd': {
                if((c-1) >= 0 && (c-1) < 4){
                    int aux = M[f][(c - 1)];
                    M[f][(c - 1)] = M[f][c];
                    M[f][c] = aux;
                    //printf("A la derecha del cero esta el M[%i][%i] = %i\n", f, c + 1, M[f][(c+1)]);
                } else {
                    printf("No se puede mover hacia la derecha amigo ");
                }
            };
                break;
            default:
                printf("Tecla no valida");
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
            if(matrix[f][c] == 0){
                printf("%c,", ' ');  
            } else {
                printf("%i,", matrix[f][c]);  
            }
            if(f==3 && c==3){
                printf("]");
            }
        }
        printf("\n");
    }
}

