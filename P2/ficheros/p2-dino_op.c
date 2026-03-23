#include "p2-dino.h"

void pantalla_bienvenida(int m_y, int m_x) {
    clear(); 
    refresh(); 

    // Crear ventana de bienvenida
    WINDOW *win = newwin(ALTO, ANCHO, (m_y - ALTO) / 2, (m_x - ANCHO) / 2); 
    wbkgd(win, COLOR_PAIR(1)); 
    box(win, 0, 0); 

    // Contenido de bienvenida
    mvwprintw(win, ALTO/2 - 6, (ANCHO/2) - 6, "Bienvenido/a:"); 
    mvwprintw(win, ALTO/2 - 4, (ANCHO/2) - 7, "DINO - EL JUEGO"); 
    mvwprintw(win, ALTO/2, (ANCHO/2) - 15, "Controles: ESPACIO para saltar");
    mvwprintw(win, ALTO/2 + 2, (ANCHO/2) - 14, "Autora: Helena Moncada Ocana");
    mvwprintw(win, ALTO/2 + 6, (ANCHO/2) - 17, "Presiona una tecla para empezar...");
    
    wrefresh(win); 
    nodelay(stdscr, FALSE); 
    getch(); 
    delwin(win); 
}

void pantalla_final(int m_y, int m_x, int score) {
    clear();
    refresh();

    // Crear ventana de pantalla final
    WINDOW *win_fin = newwin(ALTO, ANCHO, (m_y - ALTO) / 2, (m_x - ANCHO) / 2);
    
    werase(win_fin); 
    wbkgd(win_fin, COLOR_PAIR(1)); 
    
    box(win_fin, 0, 0); 

    // Contenido de pantalla final
    mvwprintw(win_fin, ALTO/2 - 4, (ANCHO/2) - 9, "¡FIN DE LA PARTIDA!"); 
    mvwprintw(win_fin, ALTO/2 - 2, (ANCHO/2) - 9, "Marcador final: %d", score);
    mvwprintw(win_fin, ALTO/2, (ANCHO/2) - 6, "¡FELICIDADES!");
    mvwprintw(win_fin, ALTO/2 + 4, (ANCHO/2) - 11, "¿Volver a jugar? (s/n)");

    wrefresh(win_fin);
}