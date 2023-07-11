#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SEPARATOR() printf("\n");
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//Prototipos
int generateRandomIndex();
int isIndexRepeated(int matrixArray[10], int index);
int isMatrixSolved(int table[4][4],int solution[4][4]);
int calculateScore(int moves, int bet);
void displayMatrix(int matrix[][4], int rows, int cols);
void findEmptySpace(int M[4][4],int *f, int *c);
void checkMovements(int M[4][4],int f, int c, char key);
void displayControls();
void fillTable(int table[4][4], int matrix[10][4][4], int index);
void showHistory(int history[10][4],int limit);

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
            {15,9,0,7},
            {5,2,3,8},
            {6,11,13,10},
            {14,12,11,4}
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
char key = 'e';
char answer = 's';
int row = -1;
int col = -1;
int score = 0;
int moves = 0;
int matrixIndex = 0;
int matchesPlayed = 0;
int bet = 0;
int table[4][4];
int history[10][4];
int usedIndex[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int solution[4][4] = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,0}
};
int scoreHistory[10];

//Control entre partidas

while((answer == 's' || answer == 'S') && matchesPlayed < 3){ //matchesPlayed --> indice del historial
    matchesPlayed++;
    //Seleccion de matriz NO REPETIDA
    int matrixIndex = generateRandomIndex();
    while(isIndexRepeated(usedIndex, matrixIndex) == 1){
        printf("La matriz se repitio(matrixIndex), buscamos otra...\n");
        matrixIndex = generateRandomIndex();
    }
    usedIndex[(matchesPlayed - 1)] = matrixIndex;

    fillTable(table, matrixSolutions, matrixIndex);

    //Inicializacion de variables a usar en UNA partida
    moves = 0;
    key = 'x';
    printf("Ingrese su apuesta:\n> ");
    scanf("%i", &bet);
    while(bet < 1 || bet > 50 ){
        printf("La apuesta debe ser mayor a 0 y menor a 50 \n>");
        scanf("%i", &bet);
    }

    system("cls");
    displayMatrix(table, 4, 4);
    SEPARATOR();
    displayControls();
    SEPARATOR();

    time_t startTime = time(NULL);
    //Control Partida Individual
    while(!(isMatrixSolved(table, solution)) && key != 'q'){
        findEmptySpace(table, &row, &col);
        printf("Ingrese Movimiento\n> ");
        scanf(" %c", &key);
        key = tolower(key);
        system("cls");
        if (key == 'a' || key == 's'|| key == 'w' || key == 'd') {
            moves++;
        }
        checkMovements(table, row, col, key);
        displayMatrix(table, 4, 4);
        SEPARATOR();
        displayControls();
        SEPARATOR();
    }

    time_t endTime = time(NULL);

    int timeTaken = endTime - startTime;

    //Muestro datos de esta partida
    system("cls");
    printf("Tardaste %is\n", timeTaken);
    score = calculateScore(moves, bet);
    history[(matchesPlayed - 1)][0] = score;
    history[(matchesPlayed - 1)][1] = moves;
    history[(matchesPlayed - 1)][2] = bet;
    history[(matchesPlayed - 1)][3] = timeTaken;

    if(key != 'q'){
        printf("======================================================================\n");
        printf("Resolviste el Puzzle!!!\n");
        printf("======================================================================\n");
    } else {
        printf("======================================================================\n");
        printf("Abandonaste...\n");
        printf("======================================================================\n");
        history[(matchesPlayed -1)][0] = 0;
    }

    showHistory(history, matchesPlayed);

    //pregunto si quiere jugar otra ronda
    printf("Quiere jugar otra ronda? [s/n] \n> ");
    scanf(" %c", &answer);
    while(answer != 's' && answer != 'n' && answer != 'S' && answer != 'N'){
        system("cls");
        printf("Quiere jugar otra ronda? [s/n]\n> ");
        scanf(" %c", &answer);
    }
    system("cls");
}

    showHistory(history, matchesPlayed);

    return 0;
}

//Funciones
int generateRandomIndex(){
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

void displayMatrix(int matrix[][4], int rows, int cols) {
    printf("========================\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // printf("%4d |", matrix[i][j]); // Adjust the width as needed for your matrix size
        
        if(matrix[i][j] == 0){
                printf(ANSI_COLOR_RED "%4c " ANSI_COLOR_RESET, 'X' );  
                printf("|");
            } else {
                printf("%4d |", matrix[i][j]);  
            }
        }
        printf("\n");
    }
    printf("========================\n");
}

void checkMovements(int M[4][4],int f, int c, char key){  
        switch(key) {
            case 's': {
                if((f-1) >= 0 && (f-1) < 4){
                    int aux = M[(f-1)][c];
                    M[(f-1)][c] = M[f][c];
                    M[f][c] = aux;

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
                } else {
                    printf("No se puede mover hacia la derecha amigo\n ");
                }
            };
                break;
            default:
                printf("key no valida\n");
        }
        SEPARATOR();
}

void displayControls(){
    printf("W - Arriba\n");
    printf("S - Abajo\n");
    printf("A - Izquierda\n");
    printf("D - Derecha\n");
    printf("Q - Salir\n");
}

int isMatrixSolved(int M[4][4],int solution[4][4]){
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


int calculateScore(int moves, int apuesta){
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

void fillTable(int table[4][4], int matrix[10][4][4], int index) {
    int f,c;
    for (f = 0; f < 4; f++) {
        for (c = 0; c < 4 ; c++) {
            table[f][c] = matrix[index][f][c];
        }
    }
}

void showHistory(int history[10][4], int limit) {
    int i, j;
    printf("===Partida===|===Puntos====|=Movimientos=|===Apuesta===|==Tiempo(s)==|\n");
    for (int i = 0; i < limit; i++) {
        printf("%7d      |",(i+1));  
        for (int j = 0; j < 4; j++) {
            if(history[i][j] > 999){
                printf("%9d    |", history[i][j]);
            } else if (history[i][j] > 99){
                printf("%8d     |", history[i][j]);
            }  else {
                printf("%7d      |", history[i][j]);  
            }
        }
        printf("\n");
    }
    printf("======================================================================\n");
}