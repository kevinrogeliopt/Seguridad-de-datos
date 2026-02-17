# Bitácora: Seguridad de Datos

## Clase 19 de enero de 2026

En la primera clase se abordaron los fundamentos de la seguridad de la información. Iniciamos con el Triángulo CIA (Confidencialidad, Integridad y Disponibilidad), que establece que los datos deben estar protegidos contra accesos no autorizados, no deben ser alterados indebidamente y deben estar disponibles cuando se necesiten.

Después se explicó el modelo Triple AAA: autenticación (verificar identidad), autorización (definir qué puede hacer el usuario) y accountability (registro de acciones para auditoría). Relacionado con esto, vimos el non-repudiation, que evita que una persona niegue haber realizado una acción dentro del sistema.

También analizamos el equilibrio entre funcionalidad, usabilidad y seguridad, entendiendo que aumentar la seguridad puede afectar la comodidad del usuario. Se estudiaron los estados de los datos: en uso, en tránsito y en reposo, junto con sus mecanismos de protección como cifrado y controles de acceso.

Finalmente, revisamos los factores de autenticación: algo que sabes (contraseña), algo que tienes (token) y algo que eres (biometría), lo que da paso al MFA. Además, se explicó el principio de least privilege, que indica que cada usuario debe tener solo los permisos mínimos necesarios.

## Clase 21 de enero de 2026

En esta sesión se estudiaron los fundamentos de redes aplicados a la seguridad. Se revisaron el modelo OSI (7 capas) y el modelo TCP/IP (4 capas), que explican cómo viaja la información en una red.

Se identificaron las direcciones utilizadas en cada nivel: dirección MAC (capa de acceso), dirección IP (capa de red) y puertos (capa de transporte), entendiendo que cada una cumple una función específica en la comunicación.

También se introdujeron conceptos de reconocimiento y ataques en red. Se habló de Nmap como herramienta para realizar port scanning, técnica que permite detectar puertos abiertos y servicios activos. Además, se explicaron ataques como spoofing (suplantación de identidad), poisoning (como el envenenamiento ARP) y la manipulación de la MAC address table en switches.

La clase permitió relacionar el funcionamiento técnico de las redes con los principios de seguridad vistos anteriormente, entendiendo que conocer cómo operan los sistemas es clave para poder protegerlos.
