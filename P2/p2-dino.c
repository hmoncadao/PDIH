#include "p2-dino.h"

int jugar(int m_y, int m_x) {
    int x_dino = 5, y_dino, x_cactus, score = 0, saltando = 0;
    
    WINDOW *juego_win = newwin(ALTO, ANCHO, (m_y - ALTO) / 2, (m_x - ANCHO) / 2);
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
        if (x_cactus < 1) { x_cactus = ANCHO - 2; score++; }

        if (x_cactus == x_dino && y_dino == y_suelo) break; 

        wrefresh(juego_win); 
        usleep(DELAY);       
    }
    delwin(juego_win);
    return score;
}