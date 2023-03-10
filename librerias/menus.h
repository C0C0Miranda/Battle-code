#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "usuario.h"
#include "gotoxy.h"
#include "botonesAnimaciones.h"

//     PROTOTIPADO MENUS

void frontMenuCombate();
void menuCombate(stPj * personaje,nodoEnemigo * enememigo);

void frontInicioMenu();
char inicioMenuSecundario(char tecla);
char inicioMenu(char tecla);

char menuInicioSesion(char tecla);
void frontMenuInicioSesion();
char menuInicioSesionSecundario(char tecla);

void frontMenuIngreso();
char menuIngresarSecundario(char tecla);
char menuIngresar(char tecla);

void frontMenuAdministrador();
char menuAdministrador(char tecla);

void frontMenuRegistro();
char menuRegitro(char tecla);

void frontMenuComandoAdmin();
char menuComandoAdmin(char tecla, stUsuario admin);

void frontMenuUsuario();
char menuUsuario(stUsuario usuario,char tecla);

void cargarDato(char arreglo[],int x,int y);
void cargarDatoPass(char arreglo[],int x,int y);
void limpiarArregloChar(char arreglo[]);
void imprimirSelector(int posicion);
void selector(int x, int y);
void selectorUsuario(int x, int y,char color[]);
void movimientoSelectorUsuario(int posicion);
void marcosUsuarios();
void borrarMuestraUsuarios();

void nombreEquipo(int x,int y);
void dinamitaIZQ(int x,int y);
void dinamitaDER(int x, int y);
void PantallaVictoria ();
void Cama(int x,int y );
void  victoria (int x, int y );
void Copa (int x, int y );
void programa();























#endif // MENUS_H_INCLUDED
