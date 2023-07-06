#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int randomMatrix();
int isIndexRepeated(int matrixArray[10], int index);
void showSolution(int matrix[4][4]);
void loadTable(int table[4][4], int matrix[10][4][4], int index);

int main() {
    srand(getpid());
    int matrixSolutions[10][4][4] = {
        {
            {6, 0 ,12, 14}, 
            {9, 1, 13, 8}, 
            {15, 10, 4, 2}, 
            {11, 5, 7, 3}
        },
        {
            {10, 4, 3, 2}, 
            {6, 8, 1, 7}, 
            {11, 5, 9, 15}, 
            {12, 0, 13, 14}
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
    int usedIndex[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    char answer[3];
    int matchesPlayed = 0;
    int processedAnswer = 0;
    int table[4][4];
    //char seguirJugando[2] = "si";
    //int apuesta = 0;
    //int resolvido = 0;
    //int historialPuntos[] = {0};

    for(int i=0; i<10; i++){
        printf("%i,", usedIndex[i]);
    }
    printf("\n");

    while((processedAnswer == 0) && (matchesPlayed != 10)) {

        // while(seguirJugando == "si" && resolvido == 0){
        int matrixIndex = 0;
        while(isIndexRepeated(usedIndex, matrixIndex) == 1){
            printf("La matriz se repitio(matrixIndex), buscamos otra...\n");
            matrixIndex = randomMatrix();
        }

        usedIndex[matchesPlayed] = matrixIndex;
        loadTable(table, matrixSolutions, matrixIndex);
        
        printf("--- Se jugo la partida numero %d, con la Matriz %d ---\n", matchesPlayed, matrixIndex);  
        showSolution(table);
        matchesPlayed++;
        // }
        
        for(int i=0; i<10; i++){
            printf("%i,", usedIndex[i]);
        }
        printf("\n");

        printf("Desea jugar otra partida? (si-no)\n> ");
        //validarRespuesta(respuesta)  -----> esta funcion serviria para validar que el usuario ingrese 'is' o 'no' y no cualquier cosa
        scanf("%s", &answer);
        processedAnswer = strcmp(answer, "si");
    }   

    return 0;
}

int randomMatrix(){
    return (rand() % 10);
}

void showSolution(int matrix[4][4]){
    int f,c;
    for (f = 0; f < 4; f++) {
        for (c = 0; c < 4 ; c++) {
            printf("%i,", matrix[f][c]);
        }
        printf("\n");
    }
}

int isIndexRepeated(int matrixArray[10], int index){
    for (int i = 0; i < 10; i++) {
      if (matrixArray[i] == index) {
        return 1;
      }
    }
    return 0;
}

void loadTable(int table[4][4], int matrix[10][4][4], int index) {
    int f,c;
    for (f = 0; f < 4; f++) {
        for (c = 0; c < 4 ; c++) {
            table[f][c] = matrix[index][f][c];
        }
    }
}