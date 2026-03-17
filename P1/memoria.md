# Práctica 1 - Entrada/Salida utilizando interrupciones con lenguaje C
---

En esta primera práctica, se implementa un conjunto de funciones (en lenguaje C) relacionada con la E/S mediante interrupciones sowftware (control del crusor, gestión de colores en pantalla...). Todas estas funciones, se pueden probar en [el fichero principal](/ficheros/p1.c), donde se permite ver el funcionamente de estas de manera interactiva, usando una estructura `switch`.       
    
Los ficheros se dividen en aquellos de naturaleza obligatoria (requisitos mínimos) cuya implementación se encuentra en [p1.c](/ficheros/p1.c) y los requisitos opcionales, en [p1_op.c](/ficheros/p1_op.c). Las especificaciones y cabeceras de todas estas funciones se encuentran en el fichero [p1.h](/ficheros/p1.h).        

---
## Requisitos mínimos
1.**`gotoxy()`**: Coloca el cursor en una posición determinada.        
<p align="center">
  <img src="img_memoria/gotoxy.png" width="500">
</p>        

2. **`setcursortype()`**: Fija el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.        
<p align="center">
  <img src="img_memoria/cursor.png" width="500">
</p>

3. **`setvideomode()`**: Fija el modo de video deseado.
<p align="center">
  <img src="img_memoria/videomode.png" width="500">
</p>        

4. **`getvideomode()`**: Obtiene el modo de video actual.        
<p align="center">
  <img src="img_memoria/getvideo.png" width="500">
</p>
   
5. **`textcolor()`**: Modifica el color de primer plano con que se mostrarán los caracteres.        
<p align="center">
  <img src="img_memoria/textocolor.png" width="500">
</p>
   
6. **`textbackground()`**: Modifica el color de fondo con que se mostrarán los caracteres.
<p align="center">
  <img src="img_memoria/textoback.png" width="500">
</p>

7. **`clrscr()`**: Borra toda la pantalla.
<p align="center">
  <img src="img_memoria/clear1.png" width="400">
  <img src="img_memoria/clear2.png" width="400">
</p>

8. **`cputchar()`**: Escribe un carácter en pantalla con el color indicado actualmente.
Esta función se usa como complementaria en varias de las funciones. Para comprobarlo se recomienda visitar el código fuente [p1.h](/p1.h).

9. **`getche()`**: Obtiene un carácter de teclado y lo muestra en pantalla.        
<p align="center">
  <img src="img_memoria/getche.png" width="500">
</p>

10. **`pixel()`**: Dibujar un pixel en modo gráfico (la función recibirá la coordinada x,y y el color del punto.        
<p align="center">
  <img src="img_memoria/pixel1.png" width="400">
  <img src="img_memoria/pixel2.png" width="400">
</p>

---
## Requisitos ampliados
1. **`dibujarRecuadro()`**: Dibujar un recuadro en la pantalla en modo texto.        
<p align="center">
  <img src="img_memoria/recuadro1.png" width="400">
  <img src="img_memoria/recuadro2.png" width="400">
</p>

2. **`modoCGA()`**: Establecer modo gráfico CGA (modo=4) para crear dibujos.        
<p align="center">
  <img src="img_memoria/cga1.png" width="400">
  <img src="img_memoria/cga2.png" width="400">
</p>

3. **`asciiArt()`**: Dibujo sencillo de tipo “ascii art”.       
<p align="center">
  <img src="img_memoria/ascii1.png" width="400">
  <img src="img_memoria/ascii2.png" width="400">
</p>
