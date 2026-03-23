#include "p2-dino.h"
#include <stdlib.h>

int main() {
    int max_y, max_x, score;
    char opcion;

    // 1. Inicialización de ncurses
    initscr();             
    if (has_colors() == FALSE) { 
        endwin();
        printf("Tu terminal no soporta colores\n");
        exit(1);
    }

    start_color();         // Activa colores
    use_default_colors();  // Mantiene el fondo original de tu terminal
    noecho();              // No muestra las teclas pulsadas
    
    // LA CLAVE: curs_set(0) oculta el cursor (adiós a los bloques negros)
    curs_set(0);           

    // 2. Definir Par 1: Negro sobre Blanco
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    // 3. Obtener tamaño del terminal
    getmaxyx(stdscr, max_y, max_x);

    // 4. Pantalla de Bienvenida (Requisito Ampliado 1)
    pantalla_bienvenida(max_y, max_x);

    // 5. Bucle principal de juego
    do {
        // Limpiamos stdscr antes de empezar para que no haya restos
        clear();
        refresh();

        // Ejecutar el juego (Requisito Obligatorio)
        score = jugar(max_y, max_x);

        // 6. Preparación para la Pantalla Final (Requisito Ampliado 2)
        nodelay(stdscr, FALSE); // Desactivar modo sin pausa
        flushinp();             // Limpiar buffer de teclado (evita saltos accidentales)

        // Dibujar la cajita blanca de resumen
        pantalla_final(max_y, max_x, score);

        // Esperar la tecla 's' o 'n'
        opcion = getch(); 

    } while (opcion == 's' || opcion == 'S');

    // 7. Restaurar terminal y salir
    endwin(); 
    return 0;
}