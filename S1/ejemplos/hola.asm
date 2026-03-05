.model small
.stack 100h

.data
    ; Definimos el mensaje. 13 y 10 son para que haga un salto de línea (Enter)
    msg db 'Hola Mundo', 13, 10, '$'

.code
main proc
    ; Inicialización del segmento de datos
    mov ax, @data
    mov ds, ax

    ; --- AQUÍ EMPIEZA EL BUCLE ---
    mov cx, 7          ; Ponemos el contador en 7

bucle_imprimir:
    push cx            ; Guardamos CX porque algunas funciones de DOS lo alteran
    
    mov ah, 09h        ; Función 09h: Imprimir cadena en pantalla
    lea dx, msg        ; Cargar la dirección del mensaje en DX
    int 21h            ; Interrupción de DOS
    
    pop cx             ; Recuperamos el valor del contador
    loop bucle_imprimir ; Resta 1 a CX y si no es 0, salta a 'bucle_imprimir'
    ; --- AQUÍ TERMINA EL BUCLE ---

    ; Finalizar el programa y volver a DOS
    mov ax, 4C00h
    int 21h
main endp

end main
