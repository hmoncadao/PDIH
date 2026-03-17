#include "p1.h"  

void dibujarRecuadro(int x1, int y1, int x2, int y2, int color_t, int color_f) {
    int i;

    textcolor(color_t);
    textbackground(color_f);

    // Esquinas
    gotoxy(x1, y1); cputchar((char)218); // Esquina superior izquierda 
    gotoxy(x2, y1); cputchar((char)191); // Esquina superior derecha 
    gotoxy(x1, y2); cputchar((char)192); // Esquina inferior izquierda
    gotoxy(x2, y2); cputchar((char)217); // Esquina inferior derecha

    // Dibujar las líneas horizontales 
    for (i = x1 + 1; i < x2; i++) {
        gotoxy(i, y1); cputchar((char)196); // Linea horizontal
        gotoxy(i, y2); cputchar((char)196); // Linea horizontal
    }

    // Lineas verticales
    for (i = y1 + 1; i < y2; i++) {
        gotoxy(x1, i); cputchar((char)179); // Linea vertical
        gotoxy(x2, i); cputchar((char)179); // Linea vertical
    }
}

void modoCGA() {
    int i;

    setvideomode(4);

    // Cuadro azul en el centro
    // Horizontal
    for(i = 100; i < 220; i++) {
        pixel(i, 70, 1);  // Lado superior
        pixel(i, 130, 1); // Lado inferior
    }
    // Vertical
    for(i = 70; i < 130; i++) {
        pixel(100, i, 1); // Lado izquierdo
        pixel(220, i, 1); // Lado derecho
    }

    //Cruz de color magenta
    for(i = 80; i < 120; i++) {
        pixel(160, i, 2); // Linea vertical
    }
    for(i = 140; i < 180; i++) {
        pixel(i, 100, 2); // Linea horizontal
    }

    //Pixel blanco en el centro
    pixel(160, 100, 3);

    pausa();

    setvideomode(3);
}

void asciiArt() {
    clrscr();
    textcolor(15); 
    printf("\n\n");
    printf("       (\\ /)  \n");
    printf("       (. .)  \n");
    printf("      c(   )  \n");
    printf("       .. .. \n");
    printf("       O   O  \n");
    
    printf("\nPulse una tecla para volver...");
    pausa();
}