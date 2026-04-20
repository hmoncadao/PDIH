# Práctica 3 - Experimentación con Arduino
---
El objetivo principal de esta práctica es aprender a usar el entorno de desarrollo de Arduino así como practicar el montaje de circuitos electrónicos. A lo largo de esta memoria se explicarán los pasos seguidos para lograr completar todos los ejercicios, desde la configuración del entorno a la implementación, simulación y validación de problemas. 	

--- 

## Estructura de los ejercicios
Tanto los ejercicios obligatorios como los opcionales siguen la misma estructura, que nos permite cuidar el material, así como aprende....
....


* **Configuración del entorno:** Se instala y configura la herramienta de trabajo necesarias para programar el dispositivo Arduino. En mi caso, ya tenía instalado el paquete. En Linux, usé el comando:		
```bash
sudo apt install arduino
sudo apt install arduino-core	
```		
* **Implementación de programas:** Desarrollar programas en `C++`, siendo aplicaciones sencillas que se encargan de gestionar tanto entradas como salidas digitales.	
* **Simulación y validación:** Usar la herramienta [Tinkercad] (https://www.tinkercad.com) para verificar que el diseño de nuestros prototipos es correcto antes de implementarlo físicamente y poner en riesgo nuestros componentes.
* **Adaptación de circuitos:** Adaptar los circuitos simulados en Tinkercad en nuestras placas físicas usando el Kit de Arduino.

Todo esto se encuentra recogido en la carpeta individual de cada ejercicio, donde podemos ver todo tipo de detalles del funcionamiento de cada circuito individualmente. Podrás encontrar desde imagenes de la simulación, imagenes reales del montaje en la placa física, hasta videos y el código fuente que hace funcionar el experimento.  

_*Visita mi [Panel de Circutios de Tinkercad] (https://www.tinkercad.com/dashboard/designs/all)._
  
---

## 1. Ejercicios Obligatorios (Requisitos Mínimos)
En esta sección explicaremos dos ejercicios que debemos realizar para cumplir los requisitos más básicos que se solicitane en esta práctica. Con estos, aprenderemos la utilidad y manejo de E/S digitales. 

### Ejercicio 1 - Parpadeo de LED
El primer ejercicio consiste en implementar un programa de parpadeo de LED que permita encender y apagar alternativamente tres LEDs de diferentes colores. Para ello, se nos propone una estructura y ciertas referencias para poder llevarlo a cabo. Concretamente, debemos usar las salidas digitales 11, 12 y 13 de Arduino y un intervalo de 1.5 segundos (1500 milisegundos). Los detalles se encuentran en este [enlace]("img_fich/ej1/simulacion.png") 

<p align = "center"> Simulación del ejercicio 1 en Tinkercad.</p>
<p align="center">
  <img src="img_fich/ej1/simulacion.png" width="500">
</p>



Descripción
Fotos
Codigo

### Ejercicio 2 - Parpadeo de LEDs con interruptor
Descripción
Fotos
Codigo
	

---

## Ejercicios Opcionales (Requisitos Ampliados)

### Ejercicio 1 - Secuencia de LEDs (_"El coche fantástico"_)

### Ejercicio 2 - Detector de la distancia a un objeto

### Ejercicio 3 - Detector de la cantidad de luz

### Ejercicio 4 - Activación de un motor

---

## DISEÑO 

<p align="center">
  <img src="img_memoria/dino.png" width="400">
  <img src="img_memoria/dino-salto.png" width="400">
</p>

<p align="center">
  <img src="img_memoria/intro-dino.png" width="500">
</p>

`ej`		
```bash
trozo codigo	
```

[p2-dino.h](ficheros/p2-dino.h) - Archivo donde encotramos los prototipos y cabeceras. 	

---
