#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "usuario.h"
#include "botonesAnimaciones.h"
#include "gotoxy.h"
#include "TDAarboles.h"
#include "TDAlistaSimple.h"
#include "estructuras.h"
#include "sala.h"
#include "puertas.h"
#include "enemigo.h"
#include "personaje.h"

#define PURCLARO "\033[1;35m"
#define ROJO "\033[0;31m"
#define CYAN "\033[0;36m"
#define VERDE "\033[0;32m"
#define VERDESUB "\033[4;32m"
#define AZUL "\033[0;34m"
#define MARRON "\033[0;33m"
#define NORMAL "\033[0m"
#define NORMALSUB "\033[4;1;37m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

#define ESPACIO 32
#define CANCELAR 8
#define ENTER 13
#define SALIR 27
#define C 99
#define A 97
#define E 101

#define ESBIRRO 1
#define BOOS 2



///FUNCIONES DE GAME OVER ///
 void dibujarGame(int x,int y){
 ///G///
printf("%s",ROJO);dibujarCuadroAscii(x,y-1,x+5,y-1,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x-1,y,x,y,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x-1,y+1,x,y+1,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x-1,y+2,x,y+2,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x-1,y+3,x,y+3,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+2,y+3,x+5,y+3,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x-1,y+4,x,y+4,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x,y+5,x+5,y+5,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+6,y+3,x+6,y+5,219);printf("%s",NORMAL);

///A///

printf("%s",ROJO);dibujarCuadroAscii(x+11,y-1,x+13,y-1,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+10,y,x+14,y,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+10,y+1,x+10,y+5,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+9,y+1,x+9,y+5,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+11,y+3,x+13,y+3,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+14,y+1,x+14,y+5,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+15,y+1,x+15,y+5,219);printf("%s",NORMAL);

///M///

printf("%s",ROJO);dibujarCuadroAscii(x+18,y-1,x+18,y+5,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+19,y-1,x+19,y+5,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+20,y+1,x+20,y+1,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+21,y+2,x+21,y+2,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+22,y+2,x+22,y+2,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+23,y+1,x+23,y+1,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+24,y-1,x+24,y+5,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+25,y-1,x+25,y+5,219);printf("%s",NORMAL);

///E/

printf("%s",ROJO);dibujarCuadroAscii(x+28,y-1,x+28,y+5,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+29,y-1,x+29,y+5,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+30,y-1,x+33,y-1,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+30,y+1,x+32,y+1,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+30,y+5,x+33,y+5,219);printf("%s",NORMAL);



}

void dibujarOver(int x, int y )
{

///O///
printf("%s",ROJO);dibujarCuadroAscii(x+1,y+8,x+3,y+8,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+1,y+14,x+3,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x,y+9,x,y+13,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+4,y+9,x+4,y+13,219);printf("%s",NORMAL);

///V//

printf("%s",ROJO);dibujarCuadroAscii(x+8,y+8,x+8,y+12,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+9,y+8,x+9,y+13,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+10,y+14,x+11,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+12,y+8,x+12,y+13,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+13,y+8,x+13,y+12,219);printf("%s",NORMAL);

///E///
printf("%s",ROJO);dibujarCuadroAscii(x+16,y+8,x+16,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+17,y+8,x+17,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+18,y+8,x+21,y+8,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+18,y+10,x+20,y+10,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+18,y+14,x+21,y+14,219);printf("%s",NORMAL);

///R//

printf("%s",ROJO);dibujarCuadroAscii(x+24,y+8,x+24,y+14,219);printf("%s",NORMAL);
printf("%s",ROJO);dibujarCuadroAscii(x+25,y+8,x+25,y+14,219);printf("%s",NORMAL);
    printf("%s",ROJO);dibujarCuadroAscii(x+25,y+8,x+29,y+8,219);printf("%s",NORMAL);
    printf("%s",ROJO);dibujarCuadroAscii(x+25,y+11,x+29,y+11,219);printf("%s",NORMAL);
    printf("%s",ROJO);dibujarCuadroAscii(x+30,y+9,x+30,y+10,219);printf("%s",NORMAL);
    printf("%s",ROJO);dibujarCuadroAscii(x+31,y+9,x+31,y+10,219);printf("%s",NORMAL);
    printf("%s",ROJO);dibujarCuadroAscii(x+30,y+12,x+30,y+12,219);printf("%s",NORMAL);
    printf("%s",ROJO);dibujarCuadroAscii(x+31,y+13,x+31,y+13,219);printf("%s",NORMAL);
    printf("%s",ROJO);dibujarCuadroAscii(x+31,y+13,x+31,y+13,219);printf("%s",NORMAL);
    printf("%s",ROJO);dibujarCuadroAscii(x+32,y+14,x+32,y+14,219);printf("%s",NORMAL);
}
///CALAVERA ///
void Calavera()
{
    //DIBUJAR CALAVERITA///
    //FONDO BLANCO Y OJOS//
    dibujarCuadroAscii(46,6,46,6,177);
    dibujarCuadroAscii(47,6,47,6,177);
    dibujarCuadroAscii(50,6,50,6,177);
    dibujarCuadroAscii(50,5,50,5,177);
    dibujarCuadroAscii(46,7,46,7,177);
    dibujarCuadroAscii(48,6,48,6,177);
    dibujarCuadroAscii(49,7,49,7,177);
    dibujarCuadroAscii(47,8,47,8,177);
    dibujarCuadroAscii(48,8,48,8,177);
    dibujarCuadroAscii(50,8,50,8,177);
    dibujarCuadroAscii(47,9,47,9,177);
    dibujarCuadroAscii(51,9,51,9,177);
    dibujarCuadroAscii(45,10,46,6,177);
    dibujarCuadroAscii(46,10,46,10,177);
    dibujarCuadroAscii(48,10,48,10,177);
    dibujarCuadroAscii(49,11,49,11,177);
    ///Contorno Calavera Preguntarle Cuando Venga //
    dibujarCuadroAscii(52,9,52,9,177);
    dibujarCuadroAscii(53,9,53,9,177);
    dibujarCuadroAscii(54,9,54,9,177);
    dibujarCuadroAscii(53,9,53,9,177);
    dibujarCuadroAscii(56,9,53,9,177);
    dibujarCuadroAscii(57,9,53,9,177);
    dibujarCuadroAscii(58,9,53,9,177);
    dibujarCuadroAscii(60,9,53,9,177);
    dibujarCuadroAscii(61,9,53,9,177);
    dibujarCuadroAscii(62,9,62,9,177);
    dibujarCuadroAscii(51,10,51,10,177);
    dibujarCuadroAscii(50,10,50,10,177);
    dibujarCuadroAscii(64,11,64,11,177);
    dibujarCuadroAscii(49,12,49,1,177);
    dibujarCuadroAscii(53,12,53,12,177);
    dibujarCuadroAscii(54,12,54,12,177);
    dibujarCuadroAscii(55,12,55,12,177);
    dibujarCuadroAscii(59,12,59,12,177);
    dibujarCuadroAscii( 60,12,60,12,177);
    dibujarCuadroAscii(61,12,61,12,177);
    dibujarCuadroAscii( 65,12,65,12,177);
    dibujarCuadroAscii(49,13,49,13,177);
    dibujarCuadroAscii(53,13,53,13,177);
    dibujarCuadroAscii(54,13,54,13,177);
    dibujarCuadroAscii(55,13,55,13,177);
    dibujarCuadroAscii(59,13,59,12,177);
    dibujarCuadroAscii(60,13,60,13,177);
    dibujarCuadroAscii(61,13,61,13,177);
    dibujarCuadroAscii(65,13,65,13,177);
    dibujarCuadroAscii(49,14,49,14,177);
    dibujarCuadroAscii(53,14,53,14,177);
    dibujarCuadroAscii(54,14,54,14,177);
    dibujarCuadroAscii(55,14,55,14,177);
    dibujarCuadroAscii(59,14,59,14,177);
    dibujarCuadroAscii(60,14,60,14,177);
    dibujarCuadroAscii(61,14,61,14,177);
    dibujarCuadroAscii(65,14,65,14,177);
    dibujarCuadroAscii(49,15,49,15,177);
    dibujarCuadroAscii(60,14,60,14,177);
    dibujarCuadroAscii(60,14,60,14,177);
    dibujarCuadroAscii(60,14,60,14,177);
    dibujarCuadroAscii(60,14,60,14,177);
    dibujarCuadroAscii(61,14,61,14,177);
    dibujarCuadroAscii(49,15,49,15,177);
    dibujarCuadroAscii(53,15,53,15,177);
    dibujarCuadroAscii(54,15,54,15,177);
    dibujarCuadroAscii(55,15,55,15,177);
    dibujarCuadroAscii(59,15,59,15,177);
    dibujarCuadroAscii(60,15,60,15,177);
    dibujarCuadroAscii(61,15,61,15,177);
    dibujarCuadroAscii(65,15,65,15,177);
    dibujarCuadroAscii(50,16,50,16,177);
    dibujarCuadroAscii(57,16,57,16,177);
    dibujarCuadroAscii(64,16,64,16,177);
    dibujarCuadroAscii(51,17,51,17,177);
    dibujarCuadroAscii(56,17,56,17,177);
    dibujarCuadroAscii(58,17,58,17,177);
    dibujarCuadroAscii(63,17,63,17,177);
    dibujarCuadroAscii(52,18,52,18,177);
    dibujarCuadroAscii(62,18,62,18,177);
    dibujarCuadroAscii(53,19,53,19,177);
    dibujarCuadroAscii(61,19,61,19,177);
    dibujarCuadroAscii(53,20,53,20,177);
    dibujarCuadroAscii(61,20,61,20,177);
    dibujarCuadroAscii(53,21,53,21,177);
    dibujarCuadroAscii(61,21,61,21,177);
    dibujarCuadroAscii(54,22,54,22,177);
    dibujarCuadroAscii(55,22,55,22,177);
    dibujarCuadroAscii(56,22,56,22,177);
    dibujarCuadroAscii(57,22,57,22,177);
    dibujarCuadroAscii(58,22,58,22,177);
    dibujarCuadroAscii(59,22,59,22,177);
    dibujarCuadroAscii(60,22,60,22,177);
    dibujarCuadroAscii(55,21,55,21,177);
    dibujarCuadroAscii(57,21,57,21,177);
    dibujarCuadroAscii(59,21,59,21,177);
    dibujarCuadroAscii(57,20,57,20,177);
    dibujarCuadroAscii(50,17,50,17,177);
    dibujarCuadroAscii(52,19,52,19,177);
    dibujarCuadroAscii(50,20,51,18,177);
    dibujarCuadroAscii(49,18,49,18,177);
    dibujarCuadroAscii(49,19,49,19,177);
    dibujarCuadroAscii(48,19,48,19,177);
    dibujarCuadroAscii(51,20,51,20,177);
    dibujarCuadroAscii(50,19,50,19,177);
    dibujarCuadroAscii(50,21,50,21,177);
    dibujarCuadroAscii(51,22,51,22,177);
    dibujarCuadroAscii(49,22,49,22,177);
    dibujarCuadroAscii(47,18,47,18,177);
    dibujarCuadroAscii(46,18,46,18,177);
    dibujarCuadroAscii(47,20,47,20,177);
    dibujarCuadroAscii(48,21,48,21,177);
    dibujarCuadroAscii(48,22,48,22,177);
    dibujarCuadroAscii(37,19,37,19,177);
///hueso arriba
    dibujarCuadroAscii(63,8,63,8,177);
    dibujarCuadroAscii(64,8,64,8,177);
    dibujarCuadroAscii(67,8,67,8,177);
    dibujarCuadroAscii(65,9,65,9,177);
    dibujarCuadroAscii(66,9,66,9,177);
    dibujarCuadroAscii(68,9,68,9,177);
    dibujarCuadroAscii(65,10,65,10,177);
    dibujarCuadroAscii(67,10,67,10,177);
    dibujarCuadroAscii(64,7,64,7,177);
    dibujarCuadroAscii(66,7,66,7,177);
    dibujarCuadroAscii(67,7,67,7,177);
    dibujarCuadroAscii(63,6,63,6,177);
    dibujarCuadroAscii(65,6,65,6,177);
    dibujarCuadroAscii(66,6,66,6,177);
    dibujarCuadroAscii(64,5,64,5,177);
    //PUNTA ESPADA ///
    dibujarCuadroAscii(63,18,63,18,177);
    dibujarCuadroAscii(62,21,62,21,177);
    dibujarCuadroAscii(63,19,63,19,177);
    dibujarCuadroAscii(63,22,63,22,177);
    dibujarCuadroAscii(64,22,64,22,177);
    dibujarCuadroAscii(65,20,65,20,177);
    dibujarCuadroAscii(65,21,65,21,177);
    dibujarCuadroAscii(66,22,66,22,177);
    dibujarCuadroAscii(65,23,65,23,177);
    dibujarCuadroAscii(66,23,66,23,177);
}

void frontGameOver()
{
    system("cls");
    Calavera();
    dibujarCuadro(0,0,119,39,CYAN);
    dibujarGame(22,20);
    dibujarOver(64,11);
    gotoxy(20,30);printf(" printf(%cSe ve que no aguantaste contra los errores en el codigo y te rendiste",34);
    gotoxy(20,31);printf("   Levantate de la compu, toca pasto, hacete un cafe y seguro que lo sacas%c)",34);
    getch();
}



//FUNCION CARGA UNA MATRIZ CON ELEMENTOS;
void cargaMatriz(int **matriz,int filas, int columnas)
{
    cuadrado(matriz,0,0,118,23,219);
    cuadrado(matriz,3,3,7,4,250);
    cuadrado(matriz,10,3,12,4,250);
    cuadrado(matriz,4,7,9,9,250);
    cuadrado(matriz,5,13,7,14,250);
    cuadrado(matriz,4,16,7,18,250);
    cuadrado(matriz,3,20,8,22,250);
    cuadrado(matriz,12,7,13,8,250);
    cuadrado(matriz,11,13,15,15,250);
    cuadrado(matriz,10,18,12,20,250);
    cuadrado(matriz,16,4,19,6,250);
    cuadrado(matriz,15,9,20,11,250);
    cuadrado(matriz,16,18,19,20,250);
    cuadrado(matriz,16,18,19,20,250);
    cuadrado(matriz,23,3,27,4,250);
    cuadrado(matriz,23,6,27,8,250);
    cuadrado(matriz,25,11,30,12,250);
    cuadrado(matriz,22,14,26,16,250);
    cuadrado(matriz,22,20,24,22,250);
    cuadrado(matriz,25,20,26,21,250);
    cuadrado(matriz,33,4,36,5,250);
    cuadrado(matriz,32,8,36,9,250);
    cuadrado(matriz,34,11,38,12,250);
    cuadrado(matriz,34,15,38,17,250);
    cuadrado(matriz,29,18,32,19,250);
    cuadrado(matriz,35,20,36,21,250);
    cuadrado(matriz,44,3,47,5,250);
    cuadrado(matriz,39,6,42,8,250);
    cuadrado(matriz,42,13,44,15,250);
    cuadrado(matriz,44,17,49,18,250);
    cuadrado(matriz,40,21,44,22,250);
    cuadrado(matriz,52,5,55,7,250);
    cuadrado(matriz,48,10,53,11,250);
    cuadrado(matriz,50,14,54,15,250);
    cuadrado(matriz,54,19,56,20,250);
    cuadrado(matriz,59,3,62,4,250);
    cuadrado(matriz,59,8,62,9,250);
    cuadrado(matriz,56,16,59,17,250);
    cuadrado(matriz,56,11,57,12,250);
    cuadrado(matriz,60,12,62,14,250);
    cuadrado(matriz,66,5,69,6,250);
    cuadrado(matriz,65,10,66,11,250);
    cuadrado(matriz,68,13,71,14,250);
    cuadrado(matriz,63,17,67,18,250);
    cuadrado(matriz,65,20,68,21,250);
    cuadrado(matriz,74,3,79,4,250);
    cuadrado(matriz,74,6,77,7,250);
    cuadrado(matriz,70,9,74,10,250);
    cuadrado(matriz,74,13,77,14,250);
    cuadrado(matriz,72,17,76,18,250);
    cuadrado(matriz,71,20,75,22,250);
    cuadrado(matriz,82,5,86,6,250);
    cuadrado(matriz,80,9,83,11,250);
    cuadrado(matriz,80,15,83,16,250);
    cuadrado(matriz,78,18,81,20,250);
    cuadrado(matriz,89,3,94,4,250);
    cuadrado(matriz,88,8,90,10,250);
    cuadrado(matriz,86,12,90,14,250);
    cuadrado(matriz,86,17,89,19,250);
    cuadrado(matriz,85,21,89,22,250);
    cuadrado(matriz,94,6,96,7,250);
    cuadrado(matriz,93,9,99,10,250);
    cuadrado(matriz,95,12,98,13,250);
    cuadrado(matriz,93,15,94,16,250);
    cuadrado(matriz,97,16,99,17,250);
    cuadrado(matriz,93,19,96,21,250);
    cuadrado(matriz,100,3,103,4,250);
    cuadrado(matriz,104,10,106,11,250);
    cuadrado(matriz,102,14,106,15,250);
    cuadrado(matriz,103,17,106,18,250);
    cuadrado(matriz,100,20,103,22,250);
    cuadrado(matriz,107,4,115,8,250);
    cuadrado(matriz,110,10,115,11,250);
    cuadrado(matriz,109,13,112,14,250);
    cuadrado(matriz,110,16,114,17,250);
    cuadrado(matriz,107,20,110,22,250);
    cuadrado(matriz,113,19,115,20,250);
    // CAMINO 1
    matriz[9][22] = 250;
    matriz[10][22] = 250;
    matriz[11][22] = 250;
    matriz[12][22] = 250;
    matriz[12][21] = 250;
    // CAMINO 2
    matriz[13][18] = 250;
    matriz[14][18] = 250;
    matriz[14][19] = 250;
    matriz[14][20] = 250;
    matriz[14][21] = 250;
    matriz[14][22] = 250;
    matriz[15][22] = 250;
    matriz[16][22] = 250;
    matriz[16][21] = 250;
    cuadrado(matriz,21,11,24,11,250);
    // CAMINO 3
    matriz[18][19] = 250;
    matriz[18][17] = 250;
    matriz[18][16] = 250;
    matriz[18][15] = 250;
    matriz[18][15] = 250;
    matriz[19][16] = 250;
    matriz[20][16] = 250;
    matriz[21][16] = 250;
    matriz[17][15] = 250;
    matriz[16][15] = 250;
    // CAMINO 4
    cuadrado(matriz,9,13,9,17,250);
    matriz[10][13] = 250;
    matriz[8][17] = 250;
    // CAMINO 5
    matriz[5][15] = 250;
    // CAMINO 6
    cuadrado(matriz,6,10,6,12,250);
    // CAMINO 7
    matriz[8][6] = 250;
    matriz[8][5] = 250;
    matriz[7][5] = 250;
    matriz[9][5] = 250;
    matriz[10][5] = 250;
    // CAMINO 8
    matriz[10][7] = 250;
    matriz[11][7] = 250;
    // CAMINO 9
    cuadrado(matriz,13,3,16,3,250);
    cuadrado(matriz,19,3,22,3,250);
    // CAMINO 10
    matriz[27][5] = 250;
    cuadrado(matriz,28,8,31,8,250);
    cuadrado(matriz,35,5,35,7,250);
    //CAMINO 11
    cuadrado(matriz,36,4,43,4,250);
    cuadrado(matriz,47,6,47,7,250);
    cuadrado(matriz,43,7,47,7,250);
    cuadrado(matriz,39,9,39,11,250);
    matriz[31][11] = 250;
    matriz[32][11] = 250;
    matriz[33][11] = 250;
    //CAMINO 12
    matriz[26][17] = 250;
    matriz[26][18] = 250;
    matriz[22][18] = 250;
    matriz[22][19] = 250;
    cuadrado(matriz,22,18,26,18,250);
    cuadrado(matriz,27,21,29,21,250);
    matriz[29][20] = 250;
    //CAMINO 13
    matriz[33][16] = 250;
    matriz[32][16] = 250;
    matriz[32][17] = 250;
    matriz[35][18] = 250;
    matriz[35][19] = 250;
    //CAMINO 14
    cuadrado(matriz,40,13,40,19,250);
    cuadrado(matriz,38,19,38,21,250);
    matriz[37][21] = 250;
    matriz[39][19] = 250;
    matriz[41][13] = 250;
    matriz[41][13] = 250;
    matriz[44][16] = 250;
    matriz[44][19] = 250;
    matriz[44][20] = 250;
    //CAMINO 15
    cuadrado(matriz,49,22,58,22,250);
    cuadrado(matriz,49,18,49,21,250);
    cuadrado(matriz,58,21,64,21,250);
    matriz[56][18] = 250;
    matriz[54][16] = 250;
    matriz[55][16] = 250;
    matriz[50][12] = 250;
    matriz[50][13] = 250;
    matriz[53][8] = 250;
    matriz[53][9] = 250;
    matriz[55][4] = 250;
    cuadrado(matriz,55,3,73,3,250);
    //CAMINO 16
    matriz[68][18] = 250;
    matriz[68][19] = 250;
    cuadrado(matriz,65,12,65,15,250);
    matriz[68][19] = 250;
    matriz[63][15] = 250;
    matriz[63][16] = 250;
    matriz[64][15] = 250;
    matriz[56][10] = 250;
    //CAMINO 17
    matriz[67][11] = 250;
    matriz[68][11] = 250;
    matriz[68][12] = 250;
    matriz[71][11] = 250;
    matriz[71][12] = 250;
    matriz[74][11] = 250;
    matriz[74][12] = 250;
    //CAMINO 18
    cuadrado(matriz,75,9,77,9,250);
    matriz[77][8] = 250;
    cuadrado(matriz,71,7,73,7,250);
    matriz[70][5] = 250;
    matriz[71][5] = 250;
    matriz[71][6] = 250;
    cuadrado(matriz,62,6,65,6,250);
    matriz[62][7] = 250;
    cuadrado(matriz,56,9,58,9,250);
    matriz[57][13] = 250;
    matriz[54][21] = 250;
    cuadrado(matriz,57,14,59,14,250);
    //CAMINO 19
    matriz[76][15] = 250;
    cuadrado(matriz,76,16,79,16,250);
    matriz[77][12] = 250;
    cuadrado(matriz,77,11,79,11,250);
    matriz[83][7] = 250;
    matriz[83][8] = 250;
    cuadrado(matriz,86,4,88,4,250);
    matriz[81][17] = 250;
    matriz[81][16] = 250;
    matriz[76][20] = 250;
    matriz[77][20] = 250;
    cuadrado(matriz,76,22,84,22,250);
    //CAMINO 20
    matriz[89][20] = 250;
    matriz[86][15] = 250;
    matriz[86][16] = 250;
    matriz[90][11] = 250;
    matriz[88][7] = 250;
    cuadrado(matriz,88,6,93,6,250);
    //CAMINO 21
    matriz[97][6] = 250;
    matriz[99][3] = 250;
    cuadrado(matriz,98,3,98,6,250);
    cuadrado(matriz,103,5,103,10,250);
    matriz[106][12] = 250;
    matriz[106][13] = 250;
    matriz[102][16] = 250;
    matriz[102][17] = 250;
    //CAMINO 22
    matriz[106][19] = 250;
    matriz[106][20] = 250;
    matriz[104][20] = 250;
    matriz[105][20] = 250;
    cuadrado(matriz,96,22,103,22,250);
    matriz[99][18] = 250;
    cuadrado(matriz,96,19,99,19,250);
    matriz[95][16] = 250;
    matriz[96][16] = 250;
    matriz[93][14] = 250;
    matriz[93][13] = 250;
    matriz[94][13] = 250;
    matriz[99][11] = 250;
    matriz[99][12] = 250;
    //FINAL
    cuadrado(matriz,110,22,115,22,250);
    matriz[115][21] = 250;
    matriz[113][18] = 250;
    matriz[109][15] = 250;
    matriz[109][16] = 250;
    matriz[115][12] = 250;
    cuadrado(matriz,112,13,115,13,250);
    matriz[115][12] = 250;
    matriz[111][9] = 250;

}

//MUESTRA UNA MATRIZ EN UNA POSICION DESIGNADA
void muestraMatriz(int **matriz,int filas, int columnas,int posX,int posY)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            if(matriz[i][j] == 219)
            {
                gotoxy(posX+i,posY+j);
                printf("%s%c%s",MARRON, matriz[i][j],NORMAL);
            }
            if(matriz[i][j] == 250)
            {
                gotoxy(posX+i,posY+j);
                printf("%s%c%s",VERDE, matriz[i][j],NORMAL);
            }
            if(matriz[i][j] == 35)
            {
                gotoxy(posX+i,posY+j);
                printf("%c",matriz[i][j]);
            }
        }
        printf("\n");
    }

}

//CREA UN SALA
stSala * creaSala(int filas,int columnas,int xSpawn,int ySpawn,int posX,int posY)
{
    stSala * sala = (stSala*)malloc(sizeof(stSala));
    sala->matriz = inicializarSala(filas,columnas);
    sala->filas = filas;
    sala->columnas = columnas;
    sala->spawn.x = xSpawn;
    sala->spawn.y = ySpawn;
    sala->posicion.x = posX;
    sala->posicion.y = posY;
    sala->listaEnemigos = cargarListaEnemigos();
    sala->listaDeObjetos = cargarListaObjetos();
    sala->listaPuertas = cargarPuertas();

    return sala;
}


//FUNCION INICIALIZA UNA MATRIZ DINAMICA;
int ** inicializarSala(int filas, int columnas)
{
    int ** matriz;
    matriz = (int**)calloc(filas, sizeof(int*));
    for(int i = 0; i < filas; i++)
    {
        matriz[i] = (int*)calloc(columnas,sizeof(int));
    }
    return matriz;
}


void cargarJuego(stPj * heroe,char archivo[])
{

    stSala * room1;

    room1 = creaSala(119,25,4,21,0,0);

    cargaMatriz(room1->matriz,room1->filas,room1->columnas);
    cargarPuertasMapa(room1);

    bool gameOver = false;

    gameOver = movimientoPersonaje(gameOver,room1,heroe,archivo);

}




















