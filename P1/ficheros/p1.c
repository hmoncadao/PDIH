#include "p1.h"  

unsigned int fondo = 0; // Negro
unsigned int texto = 7; // Blanco/gris

int mi_getchar(){
    union REGS inregs, outregs;
    int caracter;

    inregs.h.ah = 1;
    int86(0x21, &inregs, &outregs);
    
    caracter = outregs.h.al;
    return caracter;
}

void mi_putchar(char c){
    union REGS inregs, outregs;
    
    inregs.h.ah = 2;
    inregs.h.dl = c;
    int86(0x21, &inregs, &outregs);
}

void clrscr(){
    union REGS inregs, outregs;
    inregs.h.ah = 0x06;
    inregs.h.al = 0;
    inregs.h.ch = 0;
    inregs.h.cl = 0;
    inregs.h.dh = 24;
    inregs.h.dl = 79;
    inregs.h.bh = 0x07;
    int86(0x10, &inregs, &outregs);
    
    inregs.h.ah = 0x02;
    inregs.h.bh = 0x00;
    inregs.h.dh = 0;
    inregs.h.dl = 0;
    int86(0x10, &inregs, &outregs);
}

void setcursortype(int tipo_cursor){
    union REGS inregs, outregs;
    inregs.h.ah = 0x01;
    switch(tipo_cursor){
        case 0: //invisible
            inregs.h.ch = 0x20;
            inregs.h.cl = 0x00;
            break;
        case 1: //normal
            inregs.h.ch = 0x06;
            inregs.h.cl = 0x07;
            break;
        case 2: //grueso
            inregs.h.ch = 0x00;
            inregs.h.cl = 0x07;
            break;
    }
    int86(0x10, &inregs, &outregs);
}

void pausa(){
    union REGS inregs, outregs;
    inregs.h.ah = 0x00;
    int86(0x16, &inregs, &outregs);
}

void setvideomode(int mode){
    union REGS inregs, outregs;
    inregs.h.ah = 0x00; 
    inregs.h.al = (unsigned char)mode;
    int86(0x10, &inregs, &outregs);
}

void pixel(int x, int y, unsigned char c){
    union REGS inregs, outregs;
    inregs.x.cx = x;
    inregs.x.dx = y;
    inregs.h.al = c;
    inregs.h.ah = 0x0C;
    int86(0x10, &inregs, &outregs);
}

void gotoxy(int x, int y){
    union REGS r;
    r.h.ah = 0x02; 
    r.h.bh = 0x00; 
    r.h.dh = (unsigned char)y; 
    r.h.dl = (unsigned char)x; 
    
    int86(0x10, &r, &r); 
}

int getvideomode(void){
    union REGS inregs, outregs;
    inregs.h.ah = 0x0F;
    int86(0x10, &inregs, &outregs); 
    return outregs.h.al; 
}

void cputchar(char c) {
    union REGS inregs, outregs;
    unsigned char atributo;

    // Juntamos los dos estados globales en un solo byte de atributo
    atributo = (unsigned char)((fondo << 4) | (texto & 0x0F));

    inregs.h.ah = 0x09;          
    inregs.h.al = c;             
    inregs.h.bh = 0x00;          
    inregs.h.bl = atributo;      
    inregs.x.cx = 1;             

    int86(0x10, &inregs, &outregs);
}

void textcolor(int nuevo_color) {
    texto = nuevo_color & 0x0F; // Aseguramos que solo use 4 bits (0-15)
}

void textbackground(int nuevo_color) {
    fondo = nuevo_color & 0x07; // El fondo estándar solo admite 3 bits (0-7)
}

int getche(void) {
    return mi_getchar();
}