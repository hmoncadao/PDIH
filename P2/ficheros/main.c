#include "p2-dino.h"
#include <stdlib.h>

int main() {
    int max_y, max_x, score;
    char opcion;

    // Inicialización estándar
    initscr();             
    if (has_colors() == FALSE) { 
        endwin();
        printf("Tu terminal no soporta colores\n");
        exit(1);
    }

    start_color();         
    use_default_colors();  
    noecho();              
    
    // Ocultar cursor
    curs_set(0);           

    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    getmaxyx(stdscr, max_y, max_x);

    // Pantalla de bienvenida
    pantalla_bienvenida(max_y, max_x);

    do {
        clear();
        refresh();

        // Jugar
        score = jugar(max_y, max_x);

        nodelay(stdscr, FALSE); 
        flushinp();

        // Pantalla final
        pantalla_final(max_y, max_x, score);
        
        opcion = getch(); 

    } while (opcion == 's' || opcion == 'S');

    endwin(); 
    return 0;
}