#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void color(int x){                                                              /// Cambia la combinacion de color de fondo y frente
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

void gotoxy(int X,int Y){                                                       /// Cambia las coordenadas del cursor
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X=X;
      dwPos.Y=Y;
      SetConsoleCursorPosition(hcon,dwPos);
}

int whereX(){                                                                     /// Devuelve la posicion de X
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.X;
}

int whereY(){                                                                   /// Devuelve la posicion de Y
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.Y;
}

void hidecursor(int ver){                                                       /// funcion para mostrar o esconder el cursor
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 1;
   info.bVisible = ver;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void dibujarCuadro(int x1,int y1,int x2,int y2,char color[])
{
    printf("%s",color);
    int i;

    for (i=x1; i<x2; i++)
    {
        gotoxy(i,y1);
        printf("%c",219); //linea horizontal superior
        gotoxy(i,y2);
        printf("%c",219); //linea horizontal inferior
    }

    for (i=y1; i<y2; i++)
    {
        gotoxy(x1,i);
        printf("%c",219); //linea vertical izquierda
        gotoxy(x2,i);
        printf("%c",219); //linea vertical derecha
    }
    //superior izq
    gotoxy(x1,y1);printf("%c",219);
    //inferior izq
    gotoxy(x1,y2);printf("%c",219);
    //superior der
    gotoxy(x2,y1);printf("%c",219);
    //inferior der
    gotoxy(x2,y2);printf("%c",219);
    printf("\033[0m");
}


void dibujarCuadroAscii(int x1,int y1,int x2,int y2,int ascii)
{
    int i;

    for (i=x1; i<x2; i++)
    {
        gotoxy(i,y1);
        printf("%c",ascii); //linea horizontal superior
        gotoxy(i,y2);
        printf("%c",ascii); //linea horizontal inferior
    }

    for (i=y1; i<y2; i++)
    {
        gotoxy(x1,i);
        printf("%c",ascii); //linea vertical izquierda
        gotoxy(x2,i);
        printf("%c",ascii); //linea vertical derecha
    }
    //superior izq
    gotoxy(x1,y1);printf("%c",ascii);
    //inferior izq
    gotoxy(x1,y2);printf("%c",ascii);
    //superior der
    gotoxy(x2,y1);printf("%c",ascii);
    //inferior der
    gotoxy(x2,y2);printf("%c",ascii);
}

void dibujarLinea(int x, int y,int fin, int ascii)
{
    for(int i = x ; i<=fin ; i++ )
    {
        gotoxy (i,y); printf("%c",ascii);
    }
}

void centrarTexto(char *texto,int x,int x2,int y)
{
    int valor = x - x2;
    int longitud = strlen(texto);
    gotoxy(valor-(longitud/2),y);
    printf(texto);
}

// - FUNCION QUE HACE UN FONDO BLANCO

void fondoBlanco(int x, int xfin,int limite)
{
    for(int i = 0; i< limite;i++)
    {
        dibujarLinea(x,i,xfin,32);
    }
}

void cuadradoAscii(int x1, int y1,int x2,int y2,int ascii)
{
    for (int i = x1; i < x2 ; i++ )
    {
        for (int j = y1; j < y2 ; j++ )
        {
            gotoxy(i,j);
            printf("%c",ascii);
        }
    }
}

//DIBUJA UN CUADRADO EN LA MATRIZ DE CUALQUIER TIPO
void cuadrado(int **matriz, int x1, int y1, int x2, int y2,int ascii)
{
    for(int i = x1; i <= x2; i++)
    {
        for(int j = y1; j <= y2; j++)
        {
            matriz[i][j] = ascii;
        }
    }
}

void cuadradoConMarco(int x1,int y1,int x2,int y2,char color[])
{
    dibujarCuadro(x1,y1,x2,y2,color); //cuadrado vida
    cuadradoAscii(x1+1,y1+1,x2,y2,32); //fondo blanco
}


























































