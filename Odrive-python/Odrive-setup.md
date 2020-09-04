# Guía de pasos para Setup de motores y Odrive

Esta guía debe de permitirnos hacer el setup ideal del Odrive y los motores. Leer detenidamente en caso de que Valentin se muera.

Esta guia va correlacionada a ciertos pasos en la construcción fisica del robot. Pasar al siguiente paso hasta haber asegurado que se cumplen todos los requisitos del paso anterior

La lista es la que sigue:

0. Setup del odrive
1. Conectar motores al odrive
2. Alinear indice del encoder y montar los motores ya alineados
3. Conectar Eslabones


## 0. Setup del odrive

- Clonar este repositorio en un camputadora que tenga Python 3.8 instalado.

Opcional pero recomendado - installar un [virtualenv](https://mothergeo-py.readthedocs.io/en/latest/development/how-to/venv-win.html).
Instalar las dependencias necesarias con el comando:

`pip install -r requirments.txt`

- Conectar el oDrive a la computadora por USB y correr en el repo

`odrivetool`

Probar con algunos comandos como: <cmd1>, <cmd2>,  que este funcionando la conexion.


## 1. Conectar motores al odrive

- Asegurar que las fases de los motores esten cableadas en el mismo orden al oDrive para que los motores tengan la misma "direccion positiva"

- Hacer la configuracion inicial de parametros base y maximos

  >Revisar los parametros propuestos en `initial_config.py`
  >Correr el programa initial_config.py

- Correr el programa encoder_calibration.py

A partir de ahora cada vez que se haga un reboot del sistema los eslabones se van a mover hasta llegar al index. Revisar que la direccion de giro hacia el index sea la misma para asegurar una iniciacion facil.

Si esto no se logra cambiando el orden de las fases del motor entonces checar la seccion de codigo comentada al final del programa del encoder.

- Simular una situacion de arranque y asegurar que los motores regresen bien al indice.

## 2. Alinear los indices de los motores y montar en la base

Conectar los primeros eslabones para poder visualizar que esten bien alineados a la hora del montaje.

- Correr `alineacion.py`

- Verificar que los eslabones se encuentren alineados con el eje de montaje

El comand prompt preguntara si quieres correr una secuencia que lleva a los motores a 90 grados y despues regresa.

>Si la fuerza del motor en oposicion es muy baja cambiar el parametro

>`robo_drive.axis0.motor.config.current_lim = limiteCorriente`

>`robo_drive.axis1.motor.config.current_lim = limiteCorriente`

 Una vez alineados los motores montar fijamente a la base. 
