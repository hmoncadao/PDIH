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

int main() {
    int opcion;
    int x, y;
    
    do {
        clrscr();
        printf("Menu\n");
        printf("1. GOTOXY - Colocar el cursor en una posicion determinada\n");
        printf("2. SETCURSORTYPE - Fijar el aspecto del cursor\n");
        printf("3. SETVIDEOMODE - Fijar el modo de video deseado\n");
        printf("4. GETVIDEOMODE - Obtener el modo de video actual\n");
        printf("5. TEXTCOLOR - Modificar el color de primer plano (Usa cputchar)\n");
        printf("6. TEXTBACKGROUND - Modificar el color de fondo (Usa cputchar)\n");
        printf("7. PIXEL - Poner un pixel en una posicion determinada\n");
        printf("8. GETCHE - Obtener un caracter de teclado y mostrarlo en pantalla\n");
        printf("9. CLRSCR - Limpiar la pantalla\n");
        printf("10. DIBUJAR RECUADRO - Dibujar un recuadro en la pantalla en modo texto\n");
        printf("11. MODO CGA - Dibujar en modo grafico CGA (320x200, 4 colores)\n");
        printf("12. ASCII ART - Dibujo sencillo de tipo “ascii art”\n");
        printf("0. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion); 
        fflush(stdin);
        
        switch(opcion) {
            case 1:
                printf("Ingresa la columna (x): ");
                scanf("%d", &x);
                printf("Ingresa la fila (y): ");
                scanf("%d", &y);
                
                gotoxy(x, y);
                printf("x(%d,%d)", x, y);
                
                gotoxy(0, 22); 
                printf("\nPulsa cualquier tecla para volver al menu...");
                getch();
                break;
            
            case 2:
                printf("Ingresa el tipo de cursor (0: Invisible, 1: Normal, 2: Grueso): ");
                scanf("%d", &opcion);

                setcursortype(opcion);

                printf("\nObserva el cursor ahora. Pulsa una tecla para continuar...");
                
                gotoxy(10, 10);   
                pausa();          

                gotoxy(0, 22);    
                printf("\nPulsa cualquier tecla para volver al menu...");
                pausa();          
                break;
            
            case 3:
                printf("Ingresa el modo de video (ej. 3 para texto): ");
                scanf("%x", &opcion);
                setvideomode(opcion);
                break;
            
            case 4:
                printf("El modo de video actual es: 0x%02X\n", getvideomode());
                printf("\nPulsa cualquier tecla para volver al menu...");
                getch();
                break;
            
            case 5:
                printf("Color de TEXTO (0-15): ");
                scanf("%d", &opcion);
                textcolor(opcion); 
                
                printf("Escribe una frase: ");
                fflush(stdin);{

                    char frase[80];
                    int i;
                    int fila = 18;    
                    int columna = 15;
                    
                    gets(frase); 

                    //Escribir la frase
                    for(i = 0; frase[i] != '\0'; i++) {
                        gotoxy(columna + i, fila); 
                        cputchar(frase[i]);
                    }
                }
            
                gotoxy(0, 22);
                printf("Mira el texto en la parte inferior. Pulsa tecla...");
                pausa();
                break;

            case 6:
                printf("Color de FONDO (0-7): ");
                scanf("%d", &opcion);
                textbackground(opcion);

                printf("Escribe la frase: ");
                fflush(stdin);{
                    char frase[80];
                    int i;
                    gets(frase); 

                    //Escribir la frase
                    for(i = 0; frase[i] != '\0'; i++) {
                        gotoxy(10 + i, 20); 
                        cputchar(frase[i]);
                    }
                }

                gotoxy(0, 24);
                printf("Fondo aplicado. Pulsa una tecla...");
                pausa();
                break;

            case 7:
                printf("Cambiando a modo grafico 0x13 (320x200)...\n");
                pausa();
                
                setvideomode(0x13); 
    
                pixel(x, 50, 10);      
                
                gotoxy(0, 10); 
                printf("Dibujo listo. Pulsa tecla para volver a modo texto...");
                
                pausa();            
                setvideomode(0x03); // Modo texto
                break;

            case 8:
                printf("\nEscribe un caracter: ");
                fflush(stdin);
                
                x = getche(); 
                
                printf("\n\nHas pulsado: %c. Pulsa otra tecla para volver al menu...", (char)x);
                pausa(); 
                break;
            
            case 9:
                clrscr();
                printf("Pantalla limpia. Pulsa cualquier tecla para volver al menu...");
                pausa();
                break;
            
            case 10:
                clrscr();
                printf("Requisito ampliado: Dibujar un recuadro en modo texto.\n");
                
                // 15 (Blanco) y 1 (Azul)
                dibujarRecuadro(10, 5, 40, 15, 15, 1); 
                
                gotoxy(12, 10);
                gotoxy(0, 22);

                printf("Pulsa una tecla para volver al menu...");
                getch(); 
                break;
            
            case 11:
                clrscr();
                printf("Requisito ampliado: Dibujar en modo grafico CGA (320x200, 4 colores).\n");
                
                modoCGA(); 
                
                gotoxy(0, 22);
                printf("Pulsa una tecla para volver al menu...");
                getch(); 
                break;

            case 12:
                asciiArt();
                break;
                
            case 0:
                printf("Saliendo...\n");
                break;
            
            default:
                printf("Opcion invalida.\n");
                getch();
        }
        
    } while(opcion != 0);
    
    return 0;
}