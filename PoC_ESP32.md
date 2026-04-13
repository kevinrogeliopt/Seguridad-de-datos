# Prueba de Concepto: Ataques de Seguridad WiFi con ESP32 Marauder

## 1. Introducción

El presente documento describe una Prueba de Concepto realizada con un dispositivo ESP32 utilizando el firmware ESP32 Marauder desarrollado por justcallmekoko. El objetivo principal fue demostrar vulnerabilidades en redes WiFi mediante técnicas como escaneo de redes, ataques de desautenticación, creación de redes falsas (Beacon Spam) y captura de paquetes. Adicionalmente, se intentó implementar un ataque de Evil Twin, el cual no pudo completarse debido a limitaciones de hardware.

## 2. Materiales utilizados

- Placa ESP32-S con chip USB CP2102
- Computadora con sistema operativo Windows
- Firmware ESP32 Marauder v1.11.0
- Herramienta FZEE Flasher para la instalación del firmware
- Terminal ESP Web Tool para monitoreo y control

## 3. Procedimiento de instalación

El firmware fue flasheado exitosamente utilizando FZEE Flasher, seleccionando el modelo ESP32 Marauder v4 Device. Una vez completada la instalación, se estableció comunicación con el dispositivo a través de la terminal integrada en ESP Web Tool, configurando la velocidad a 115200 baudios.

## 4. Actividades realizadas

### 4.1 Escaneo de redes

Se ejecutó el comando `scanap` para identificar las redes WiFi disponibles en el entorno. El ESP32 respondió mostrando una lista detallada que incluía nombres de redes (SSID), direcciones MAC (BSSID), canales e intensidad de señal (RSSI). Entre las redes detectadas se encontró TERARED-12445, TP-Link_B3CC, starlink y otras redes cercanas. Esta función demostró la capacidad del dispositivo para reconocer y catalogar el espectro WiFi circundante.

### 4.2 Ataque de desautenticación

Previo al ataque, se seleccionó la red objetivo mediante el comando `select -a 0`, utilizando el índice correspondiente a TP-Link_B3CC. El sistema confirmó la selección con el mensaje "1 selected, 0 unselected". Posteriormente se ejecutó `attack -t deauth` con la intención de enviar paquetes que forzaran la desconexión de dispositivos conectados a la red objetivo.

Es importante aclarar que este ataque no elimina ni compromete la contraseña almacenada en los dispositivos. Simplemente los desconecta temporalmente, tras lo cual se reconectan automáticamente utilizando la credencial previamente guardada. La utilidad principal de este ataque dentro de una estrategia Evil Twin es forzar reconexiones que puedan ser redirigidas hacia un punto de acceso falso.

### 4.3 Beacon Spam o creación de redes falsas

Se realizaron dos variantes de esta prueba.

En la primera variante, se ejecutó `attack -t beacon -r` para generar redes falsas con nombres aleatorios. El ESP32 confirmó el inicio del proceso y, al verificar desde un teléfono móvil, se observó la aparición de múltiples redes inexistentes en la lista de conexiones disponibles.

En la segunda variante, se detuvo el proceso anterior con `stopscan` y se agregó un nombre personalizado mediante `ssid -a -n WiFi_Gratis_Cafe`. Luego se inició el Beacon Spam con la lista creada usando `attack -t beacon -l`. Esto permitió generar una red falsa con un nombre específico diseñado para engañar a posibles víctimas.

### 4.4 Sniffing de paquetes

Se ejecutó el comando `sniffbeacon` para capturar paquetes Beacon transmitidos por los puntos de acceso cercanos. Esta funcionalidad demuestra la capacidad del ESP32 para monitorear el tráfico WiFi pasivamente y recolectar información sobre las redes del entorno.

## 5. Intento fallido de Evil Twin

Se intentó implementar un ataque Evil Twin completo utilizando el comando `evilportal -c start`. El objetivo era que el ESP32 creara un punto de acceso falso con el mismo nombre que la red TERARED-12445 y presentara una página de inicio de sesión falsa para capturar credenciales.

El sistema respondió con el mensaje "Could not find index.html. Use stopscan". Esto indica que el firmware de Marauder está diseñado para leer el archivo HTML de la página falsa desde una tarjeta microSD insertada en el dispositivo.

Se intentaron varias alternativas para resolver esta limitación. Se probaron comandos como `sethtml` y `evilportal -s html` con la esperanza de cargar el contenido HTML a través del puerto serie. Ninguno de estos comandos produjo el resultado esperado, ya que el firmware fue compilado con soporte obligatorio para tarjeta SD.

Se investigó la posibilidad de utilizar una versión del firmware compilada sin soporte para SD (HAS_SD desactivado), pero no se encontró un binario precompilado con estas características. La compilación manual desde el código fuente habría requerido instalar el entorno de desarrollo de Arduino y configurar las opciones adecuadas, lo cual excedía el alcance de esta prueba.

## 6. Conclusiones

El ESP32 Marauder demostró ser una herramienta capaz de realizar múltiples funciones de auditoría WiFi. Se verificó su capacidad para escanear redes, lanzar ataques de desautenticación, generar redes falsas mediante Beacon Spam y capturar paquetes del entorno.

La limitación principal encontrada fue la dependencia del Evil Twin respecto a una tarjeta microSD para almacenar el archivo HTML del portal cautivo. El modelo de ESP32 utilizado carece de ranura para este tipo de almacenamiento, lo que impidió completar esa parte de la prueba. Las alternativas exploradas para cargar el HTML por puerto serie no fueron efectivas debido a la configuración del firmware.

A pesar de esto, las funciones que sí operaron correctamente permiten demostrar vulnerabilidades significativas en redes WiFi. El Beacon Spam y el ataque de desautenticación son componentes fundamentales de un ataque Evil Twin, pues el primero crea el señuelo y el segundo fuerza a las víctimas hacia él.

## 7. Demostración

<div align="center">
<a href="https://drive.google.com/file/d/10ZDbCNBerz5x7wx567xj88cqlIn_Wk2B/view?usp=sharing" target="_blank">
<img src="https://upload.wikimedia.org/wikipedia/commons/d/da/Google_Drive_logo.png" alt="Ver en Google Drive" width="100"/>
</a>
<p><strong><a href="https://drive.google.com/file/d/10ZDbCNBerz5x7wx567xj88cqlIn_Wk2B/view?usp=sharing" target="_blank">Haz clic aquí para ver el video de la prueba de concepto</a></strong></p>
<p><em>El video muestra la ejecución de los comandos scanap, select -a 0, attack -t deauth, attack -t beacon -r, ssid -a -n WiFi_Gratis_Cafe, attack -t beacon -l y sniffbeacon en la terminal del ESP32 Marauder, así como la aparición de redes falsas en la lista de WiFi.</em></p>
</div>