#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define SEPARATOR() printf("\n");

//Prototipos
int randomMatrix();
int isIndexRepeated(int matrixArray[10], int index);
int isResolved(int table[4][4],int solution[4][4]);
int getPoints(int moves, int bet);
void showMatrix(int matrix[4][4]);
void findEmptySpace(int M[4][4],int *f, int *c);
void checkMovements(int M[4][4],int f, int c, char tecla);
void keysScreen();
void loadTable(int table[4][4], int matrix[10][4][4], int index);


int main () {
srand(getpid());
//Constantes 
int matrixSolutions[10][4][4] = {
        {
            {1,2,3,0},
            {5,6,7,4},
            {9,10,11,8},
            {13,14,15,12}
        },
        {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {0,13,14,15}
        },
        {
            {14, 7, 9, 13}, 
            {0, 12, 8, 3},
            {10, 6, 2, 5}, 
            {4, 1, 11, 15}
        },
        {
            {13, 4, 14, 1}, 
            {10, 9, 8, 5}, 
            {2, 11, 6, 0}, 
            {12, 7, 3, 15}
        },
        {
            {2, 8, 6, 15}, 
            {9, 3, 12, 1}, 
            {11, 4, 0, 7}, 
            {5, 14, 10, 13}
        },
        {
            {10, 8, 13, 2}, 
            {15, 0, 5, 9}, 
            {3, 11, 1, 14}, 
            {6, 4, 12, 7}
        },
        {
            {11, 15, 4, 0}, 
            {9, 12, 3, 14}, 
            {5, 8, 6, 7}, 
            {2, 13, 10, 1}
        },
        {
            {6, 10, 2, 9}, 
            {14, 1, 3, 4}, 
            {0, 11, 12, 15}, 
            {5, 7, 8, 13}
        },
        {   {13, 12, 8, 15}, 
            {0, 6, 2, 1}, 
            {7, 5, 4, 9},
            {14, 3, 11, 10}
        },
        {   {2, 1, 11, 15}, 
            {0, 3, 13, 4}, 
            {12, 7, 8, 6}, 
            {10, 14, 9, 5}
        },
    };

//Variables Globales   
char tecla = 'e';
char answer = 's';
int fila = -1;
int col = -1;
int score = 0;
int moves = 0;
int matrixIndex = 0;
int matchesPlayed = 0;
int bet = 0;
int table[4][4];
int usedIndex[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int solution[4][4] = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,0}
};

//Control entre partidas

while(answer == 's' && matchesPlayed < 3){ //matchesPlayed --> indice del historial
    matchesPlayed++;
    //Seleccion de matriz NO REPETIDA
    int matrixIndex = 0;
    //int matrixIndex = randomMatrix();
    // while(isIndexRepeated(usedIndex, matrixIndex) == 1){
    //     printf("La matriz se repitio(matrixIndex), buscamos otra...\n");
    //     matrixIndex = randomMatrix();
    // }

    loadTable(table, matrixSolutions, matrixIndex);

    //Inicializacion de variables a usar en UNA partida
    moves = 0;
    tecla = 'x';
    printf("Ingrese su apuesta:\n> ");
    scanf("%i", &bet);
    while(bet < 40 || bet > 200 ){
        printf("La apuesta debe ser mayor a 0\n> ");
        scanf("%i", &bet);
    }

    system("cls");
    showMatrix(table);
    SEPARATOR();
    keysScreen();
    SEPARATOR();

    //Control Partida Individual
    while(!(isResolved(table, solution)) && tecla != 'q'){
        findEmptySpace(table, &fila, &col);
        printf("Ingrese Movimiento\n> ");
        tecla = tolower(getch());
        system("cls");
        if (tecla == 'a' || tecla == 's'|| tecla == 'w' || tecla == 'd') {
            moves++;
        }
        checkMovements(table, fila, col, tecla);
        showMatrix(table);
        SEPARATOR();
        keysScreen();
        SEPARATOR();
    }

    //Muestro datos de esta partida
    system("cls");

    score = getPoints(moves, bet);

    if(tecla != 'q'){
        printf("Resolviste el Puzzle!!!\n");
        printf("Movimientos Realizados: %i\n", moves);
        printf("Puntos Obtenidos: %i\n", score);
    } else {
       printf("Abandonaste...\n");
       printf("Movimientos Realizados: %i\n", moves);
       printf("Puntos Obtenidos: 0, sos horrible loco.\n");
    }

    //sumo a historial


    //pregunto si quiere jugar otra ronda
    printf("Quiere jugar otra ronda?\n>");
    scanf("%c", &answer);
    while(answer != 's' && answer != 'n'){
        printf("Solo se acepta s-SI | n-NO\n>");
        scanf("%c", &answer);
    }
}

//Muestro Historial


    return 0;
}

//Funciones
int randomMatrix(){
    return (rand() % 10);
}

int isIndexRepeated(int matrixArray[10], int index){
    for (int i = 0; i < 10; i++) {
      if (matrixArray[i] == index) {
        return 1;
      }
    }
    return 0;
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

void checkMovements(int M[4][4],int f, int c, char tecla){  
        switch(tecla) {
            case 's': {
                if((f-1) >= 0 && (f-1) < 4){
                    int aux = M[(f-1)][c];
                    M[(f-1)][c] = M[f][c];
                    M[f][c] = aux;
                    //printf("Arriba del cero esta el M[%i][%i] = %i\n", f - 1,c, M[(f-1)][c]);

                } else {
                    printf("No se puede mover hacia arriba amigo\n");
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
                    printf("No se puede mover hacia abajo amigo\n");
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
                    printf("No se puede mover hacia la izquierda amigo\n");
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
                    printf("No se puede mover hacia la derecha amigo\n ");
                }
            };
                break;
            default:
                printf("Tecla no valida");
        }
}

void keysScreen(){
    printf("W - Arriba\n");
    printf("S - Abajo\n");
    printf("A - Izquierda\n");
    printf("D - Derecha\n");
    printf("Q - Salir\n");
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


int getPoints(int moves, int apuesta){
    if (moves >= (apuesta-10) &&  moves < apuesta){ // [M-10,M)
        return 1200;
    } else if(moves > apuesta && moves <= (apuesta + 10)){  // (M,M+10]
        return 500;
    } else if (moves == apuesta){ //M
        return 1000;
    } else if (moves < (apuesta - 10)){     // M-10
        return 1500;
    } else {
        return 0;
    }
}

void loadTable(int table[4][4], int matrix[10][4][4], int index) {
    int f,c;
    for (f = 0; f < 4; f++) {
        for (c = 0; c < 4 ; c++) {
            table[f][c] = matrix[index][f][c];
        }
    }
}