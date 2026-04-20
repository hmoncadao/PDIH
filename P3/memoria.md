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
El primer ejercicio consiste en implementar un programa de parpadeo de LED que permita encender y apagar alternativamente tres LEDs de diferentes colores. Para ello, se nos propone una estructura y ciertas referencias para poder llevarlo a cabo. Concretamente, debemos usar las salidas digitales 11, 12 y 13 de Arduino y un intervalo de 1.5 segundos (1500 milisegundos). Los detalles se encuentran en el [código fuente]("img_fich/ej1/ej1.ino").

<p align = "center"> Simulación del ejercicio 1 en Tinkercad.</p>
<p align="center">
  <img src="img_fich/ej1/ej1_simulacion.png" width="500">
</p>

Una vez realizamos la simulación en la plataforma, así como el código fuente, el trabajo más complejo está hecho. El siguiente paso era realiar el montaje, lo cual podemos apreciar en las fotos a continuación y en el [video]("img_fich/ej1/ej1_video.mp4")  que se encuentra en la misma carpeta. 

<p align="center">
  <img src="img_fich/ej1/ej1_montaje1.jpeg" width="400">
  <img src="img_fich/ej1/ej1_montaje2.jpeg" width="400">
</p>

### Ejercicio 2 - Parpadeo de LEDs con interruptor
Este ejercicio es una ampliación del programa anterior en el que se nos solicita introducir una lógica de control basada en un botón o interruptor (salida externa). Para ello, mantenemos la misma estructura y añaidmos un pulsador en la entrada digital 7. Lo que buscamos en este caso es que los LEDs amarillo y verde sigan el mismo funcionamiento que en el apartado 1, mientras que el LED rojo debe permanecer encendido cuando esté el botón pulsado y apagado en el resto de casos. La lógica de este experimento la encontramos en este [enlace]("img_fich/ej2/ej2.ino").

Duplicamos el fichero de Tinkercad anterior, al cual le añadimos un pulsador, y obtenemos el siguiente modelo: 

<p align = "center"> Simulación del ejercicio 2 en Tinkercad.</p>
<p align="center">
  <img src="img_fich/ej2/ej2_simulacion.png" width="500">
</p>

El montaje en nuestra placa con los diferentes componentes electrónicos (LEDs, resistencia, cables y pulsador, entre otros):
<p align="center">
  <img src="img_fich/ej2/ej2_montaje1.jpeg" width="400">
  <img src="img_fich/ej2/ej2_montaje2.jpeg" width="400">
</p>

---

## Ejercicios Opcionales (Requisitos Ampliados)
El comienzo de estos ejercicios requiere la previa consolidación de los conceptos fundamentales que hemos trabajado y explicado en la parte "obligatoria". Ahora, exploraremos capacidades y componentes más avanzados de Arduino. Aumentaremos el nivel de complejidad técnica usando señales binarias y procesando señales de tiempo y control con actuadores mecánicos.  

### Ejercicio 1 - Secuencia de LEDs (_"El coche fantástico"_)
Para resolver este apartado, debemos programar cuatro LEDs para que se enciendan y apaguen de forma consecutiva (efecto de barrido o ida y vuelta). Este efecto lo podemos ver en uno de los [videos]("https://bit.ly/3Lu7YNz") proporcionado por el profesor. La implementación la podemos consultar en la carpeta ([ej1_op]("https://bit.ly/3Lu7YNz")) asignada. 

<p align = "center"> Simulación del ejercicio opcional 1 en Tinkercad.</p>
<p align="center">
  <img src="img_fich/ej1_op/ej1_op_simulacion.png" width="500">
</p>

Podemos ver la estructura y montaje en las siguientes imagenes:
<p align="center">
  <img src="img_fich/ej1_op/ej1_op_montaje1.jpeg" width="400">
  <img src="img_fich/ej1_op/ej1_op_montaje2.jpeg" width="400">
</p>



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
