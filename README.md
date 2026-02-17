# Bitácora: Seguridad de Datos
# Parcial 1
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

## Clase 26 de enero de 2026

En esta sesión se abordaron conceptos relacionados con la gestión de vulnerabilidades y el análisis de amenazas.

Se inició con troubleshooting, entendido como el proceso sistemático para identificar, analizar y solucionar fallas en sistemas. En este contexto se explicaron los conceptos de falso positivo (cuando una herramienta detecta una amenaza que en realidad no existe) y falso negativo (cuando no detecta una amenaza real), destacando que ambos afectan la efectividad de la seguridad.

Se revisaron herramientas de análisis de vulnerabilidades como Tenable, Qualys y OpenVAS, utilizadas para escanear sistemas en busca de debilidades. También se mencionaron metodologías como STRIDE y el marco de referencia MITRE ATT&CK, que permiten clasificar y analizar amenazas.

Se diferenciaron los conceptos de vulnerabilidad (debilidad en un sistema), exploit (código o técnica que aprovecha esa debilidad), amenaza (posible evento dañino) y riesgo (probabilidad e impacto de que la amenaza explote la vulnerabilidad).

Posteriormente se habló sobre los hackers, sus motivaciones y objetivos. Se explicó la diferencia entre red team (equipo ofensivo que simula ataques) y blue team (equipo defensivo). También se clasificaron distintos tipos de hackers: script kiddies, white hat, black hat, grey hat, entre otros, según su intención y nivel técnico.

Además, se mencionó el benchmarking como práctica para comparar estándares o niveles de seguridad frente a otras organizaciones. Finalmente, se explicó el concepto de puertos efímeros, que son puertos temporales asignados dinámicamente por el sistema operativo para establecer conexiones salientes.

## Clase 28 de enero de 2026

En esta clase se profundizó en herramientas y prácticas relacionadas con la explotación de vulnerabilidades.

Se analizó Exploit Database, repositorio público de exploits conocidos, y su contraparte defensiva, donde se publican parches y soluciones. También se trabajó con Metasploit y el entorno vulnerable Metasploitable 2, diseñado para practicar pruebas de penetración.

Se estudió el caso de vsftpd 2.3.4, una versión vulnerable que contenía una puerta trasera activada con un ":", como ejemplo de flaw o falla explotable.

Posteriormente se explicaron los conceptos de NOC (Network Operations Center) y SOC (Security Operations Center), diferenciando que el primero se enfoca en la operación y disponibilidad de la red, mientras que el segundo se centra en la monitoreo y respuesta ante incidentes de seguridad.

También se revisó Shodan, motor de búsqueda de dispositivos conectados a internet, útil en procesos de footprinting y network mapping, que consisten en recolectar información y mapear la infraestructura de una red objetivo.

Se mencionó la fase de gaining access, donde el atacante obtiene acceso inicial al sistema, y el concepto de zero-day, que se refiere a vulnerabilidades desconocidas públicamente y sin parche disponible al momento de su explotación.

La clase permitió comprender cómo se pasa del análisis teórico de vulnerabilidades a la explotación práctica y cómo las organizaciones deben prepararse para detectar y responder ante estos escenarios.

## Clase 4 de febrero de 2026

En esta sesión se reforzaron los conceptos vistos en las clases anteriores, enfocándonos en la relación práctica entre vulnerabilidades, exploits y procesos de ataque controlados.

Se profundizó en cómo herramientas como Metasploit permiten aprovechar vulnerabilidades documentadas en repositorios como Exploit Database, siempre dentro de entornos de laboratorio como Metasploitable 2. Se hizo énfasis en que la explotación no es un fin en sí mismo, sino una forma de demostrar riesgos reales para poder mitigarlos.

También se relacionaron estas prácticas con el trabajo del SOC y el análisis de amenazas, entendiendo que mientras el atacante realiza fases como footprinting, scanning y gaining access, el equipo defensivo debe identificar indicadores de compromiso y reducir el impacto mediante controles de seguridad, monitoreo y aplicación de parches.

La sesión permitió integrar la parte teórica (riesgo, amenaza, vulnerabilidad) con la parte práctica (explotación controlada y respuesta).

## Clase 9 de febrero de 2026

En esta clase se realizaron pruebas de concepto utilizando dispositivos como el ATtiny85, cargándoles distintos payloads obtenidos de repositorios como GitHub. Estos payloads permiten automatizar secuencias de comandos al conectarse a un equipo, simulando escenarios reales de ataque físico o ingeniería social.

Se mencionó el caso de Windows Fisher como ejemplo de cómo un dispositivo puede ejecutar instrucciones automáticamente en un sistema Windows, demostrando la importancia de los controles físicos y de autenticación.

Además, se trabajó nuevamente con Metasploitable 2, donde el profesor explotó la vulnerabilidad presente en vsftpd 2.3.4, activada mediante la cadena ":)", lo que permitió obtener acceso remoto al sistema. Esta práctica evidenció cómo una falla específica puede convertirse en un punto crítico de compromiso si no se corrige oportunamente.

La clase reforzó la importancia de mantener sistemas actualizados, aplicar parches y comprender tanto la perspectiva ofensiva como la defensiva dentro de la seguridad de datos.
