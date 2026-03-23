#ifndef DINO_H
#define DINO_H

#include <ncurses.h>
#include <unistd.h>

#define DELAY 60000
#define ANCHO 60
#define ALTO 20

void pantalla_bienvenida(int m_y, int m_x);
int jugar(int m_y, int m_x);
void pantalla_final(int m_y, int m_x, int score);

#endif