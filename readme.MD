# Trabajo Práctico N°1: Puzzle 15

## Taller De Programación I - Profesor : Diego A. Botallo

## Alumnos : Juan Avero y Román Alvarez

### Objetivo:

El juego consiste de una cuadrícula de 16 casillas, rellenada por 15 números enteros del 1 al 15, ordenados aleatoriamente, más una cuadrícula vacía.
El objetivo es lograr ubicar los números del tablero, de forma que queden ordenados de menor a mayor, con el espacio vacío posicionado en la esquina inferior derecha.
El usuario puede hacer una apuesta para tratar de adivinar en qué cantidad de movimientos va a llegar a la resolución del juego y en base a este dato ingresado se calculan los puntos obtenidos en una partida. Además al finalizar cada partida, se le dará al usuario la posibilidad de seguir jugando hasta un máximo de 10 partidas.

### Práctica C

En este programa se emplean los siguientes conceptos de programación en C:

- Array multidimensionales
- Macros
- Punteros
- Bucles

### Estructura del programa:

El programa está compuesto de un solo archivo llamado main.c, el cual contiene todo el código fuente del juego, incluyendo las funciones necesarias para la ejecución del mismo, y variables y macros que van a ser utilizadas durante el juego.
El juego tiene un total aproximado de 350 líneas de código.

### Librerías Utilizadas:

- stdio.h: Utilizada para hacer uso de las funciones de entrada y salida del programa, como printf y scanf
- stdlib.h: Utilizada para la generación de números aleatorio con srand()
- unistd.h: Utilizada para la obtención de un número aleatorio con getpid().
- ctype.h: Utilizada para la transformación de caracteres a minúscula como, tolower().
- time.h: Utilizada para la obtención del tiempo de resolución de una partida, con time().

## Funcionamiento del programa

El funcionamiento del juego consiste de dos bucles while,uno “global” se encarga de llevar a cabo la transición entre partidas dependiendo de si el usuario quiere seguir jugando y otro while interno cuya finalidad es controlar el funcionamiento de una partida individual con tareas como, el movimiento de piezas y la validación del tablero resuelto.

Al entrar al primer bucle se genera un índice aleatorio para seleccionar una matriz del array tridimensional que contiene las matrices iniciales que poseen solución para el juego. Si este índice ya se ha utilizado, volverá a pedir otro índice, sino guardamos el índice en un arreglo. De esta manera nos aseguramos de que nunca se repita una matriz en las partidas.

Una vez seleccionada la matriz, guardamos todos sus elementos en otra matriz llamada tablero, la cual va a ser modificada según los movimientos que elija el usuario.

Luego, se le pedirá al usuario que ingrese manualmente un número en el rango [40, 200] para apostar en qué cantidad de movimientos va a llegar a la resolución del tablero.

Una vez ingresada la apuesta, comienza el juego. El usuario va a poder introducir manualmente una letra para realizar el movimiento de una casilla de las que están a los lados de la casilla vacía, siendo la letra W para mover la casilla de abajo, A para mover la casilla de la derecha, D para mover la casilla de la izquierda, S para mover la casilla de arriba, o Q para abandonar el juego siempre que quiera.
En cada movimiento que realice el usuario se realizará la validación para determinar si la disposición actual del tablero es la solución del juego. En caso de no serlo, se le pedirá que ingrese una tecla nuevamente para realizar otro movimiento.

Si la disposición del tablero es igual a la solución del juego o el usuario decidió abandonar la partida, se calcularán los puntos dependiendo de la apuesta y cantidad de movimientos hechos, y el tiempo que tomó la partida. Estos datos se guardan en una matriz y se muestran en pantalla.

Seguido de esto, el usuario tendrá la posibilidad de ingresar si quiere jugar o no otra partida. En caso de indicar que no, el programa cortará su ejecución, mostrando el historial de partidas final.
En caso de indicar que quiere jugar otra partida, el programa volverá el bucle del primer paso, generando una nueva partida, pudiendo jugar hasta un máximo de 10.

### Compilacion y ejecucion del programa

Para ejecutar el programa, se deben realizar los siguientes pasos en orden:

- Descargar y descomprimir en un directorio el archivo puzzle-15.rar
- Acceda al directorio generado con `cd puzzle-15`
- Compilar el programa con `gcc main.c -o main`
- Ejecutar el programa con `./main`
