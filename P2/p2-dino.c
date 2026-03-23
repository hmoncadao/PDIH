#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 60000
#define ANCHO 60
#define ALTO 20

int main() {
    int x_dino = 5, y_dino;
    int x_cactus, score = 0, saltando = 0;
    int max_y, max_x;

    initscr();
    
    if (has_colors() == FALSE) {
        endwin();
        printf("Tu terminal no soporta colores [cite: 92, 102]\n");
        exit(1);
    }

    start_color();          
    use_default_colors();    
    noecho();               
    curs_set(0);             

    // Color para la ventana 
    init_pair(1, 0, COLOR_WHITE); 

    getmaxyx(stdscr, max_y, max_x); // [cite: 79, 111]
    
    clear();
    refresh();

    // Ventana del juego centrada en la pantalla
    WINDOW *juego_win = newwin(ALTO, ANCHO, (max_y - ALTO) / 2, (max_x - ANCHO) / 2);
    
    wbkgd(juego_win, COLOR_PAIR(1));
    
    nodelay(juego_win, TRUE); 

    int y_suelo = ALTO - 3;
    y_dino = y_suelo;
    x_cactus = ANCHO - 5;

    while(1) {
        werase(juego_win);    
        box(juego_win, 0, 0); 

        mvwprintw(juego_win, 1, 2, "Score: %d", score); 
        mvwprintw(juego_win, y_suelo + 1, 1, "----------------------------------------------------------");
        mvwprintw(juego_win, y_dino, x_dino, "D");
        mvwprintw(juego_win, y_suelo, x_cactus, "X");

        int ch = wgetch(juego_win); 
        if (ch == ' ' && !saltando) saltando = 10;

        if (saltando > 5) y_dino--;
        else if (saltando > 0) y_dino++;
        if (saltando > 0) saltando--;

        x_cactus--;
        if (x_cactus < 1) {
            x_cactus = ANCHO - 2;
            score++;
        }

        if (x_cactus == x_dino && y_dino == y_suelo) break;

        wrefresh(juego_win); 
        usleep(DELAY);       
    }

    nodelay(juego_win, FALSE);
    mvwprintw(juego_win, ALTO / 2, (ANCHO / 2) - 10, "GAME OVER! Score: %d", score);
    wrefresh(juego_win);
    wgetch(juego_win);

    delwin(juego_win); 
    endwin();          
    
    return 0;
}