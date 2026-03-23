#ifndef DINO_H
#define DINO_H

#include <ncurses.h>
#include <unistd.h>

#define DELAY 60000
#define ANCHO 60
#define ALTO 20

// ---------------------------- Requisitos minimos ----------------------------

//Función principal del juego, devuelve el marcador final
int jugar(int m_y, int m_x);

// ----------------------------------------------------------------------------

// ---------------------------- Requisitos adicionales ------------------------

// Función para la pantalla de bienvenida
void pantalla_bienvenida(int m_y, int m_x);

// Función para la pantalla final con el marcador
void pantalla_final(int m_y, int m_x, int score);
// ----------------------------------------------------------------------------

#endif