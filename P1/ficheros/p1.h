#ifndef P1_H
#define P1_H

#include <stdio.h>    
#include <dos.h>      
#include <conio.h>  

//Variables globales para almacenar el estado actual del color de texto y fondo
extern unsigned int fondo;
extern unsigned int texto;

// ---------------------------- Requisitos minimos ----------------------------

// Obtiene un carácter de teclado
int mi_getchar(void);

// Escribe un carácter en pantalla 
void mi_putchar(char c);

//Borra toda la pantalla
void clrscr(void);

//Fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO
void setcursortype(int tipo_cursor);

// Establece el modo de vídeo: 3-texto, 4-gráfico
void setvideomode(int mode);

//Colocar el cursor en una posición determinada
void gotoxy(int x, int y);

//Obtiene el modo de video actual
int getvideomode(void);

// Modifica el color de primer plano (letras)
void textcolor(int nuevo_color);

// Modifica el color de fondo
void textbackground(int nuevo_color);

// Escribe un carácter con el color actual (texto y fondo)
void cputchar(char c);

// Pone un pixel en la coordenada X,Y de color C
void pixel(int x, int y, unsigned char c);

// Hace una pausa
void pausa(void);

// Obtiene un carácter de teclado y lo muestra en pantalla
int getche(void);
// ------------------------------------------------------------------------------


// ---------------------------- Requisitos ampliados ----------------------------

// Dibujar un recuadro en la pantalla en modo texto
void dibujarRecuadro(int x1, int y1, int x2, int y2, int color_t, int color_f);

// Establecer modo gráfico CGA (modo=4) para crear dibujos
void modoCGA();

// Dibujo sencillo de tipo “ascii art”
void asciiArt(void);

// ------------------------------------------------------------------------------

#endif